#!/bin/bash

# AI-Based C++ Interview Runner
# This script helps conduct C++ coding interviews by running specific tasks

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

print_header() {
    echo -e "${BLUE}================================================${NC}"
    echo -e "${BLUE}    AI-Based C++ Interview System v1.0${NC}"
    echo -e "${BLUE}================================================${NC}"
    echo
}

print_help() {
    echo -e "${CYAN}Usage: $0 [COMMAND] [TASK]${NC}"
    echo
    echo -e "${YELLOW}Commands:${NC}"
    echo -e "  ${GREEN}list${NC}                   - List all available interview tasks"
    echo -e "  ${GREEN}info <task_id>${NC}         - Show information about a specific task"
    echo -e "  ${GREEN}run <task_id> [turn]${NC}   - Run a specific task and turn"
    echo -e "  ${GREEN}test <task_id> [turn]${NC}  - Run tests for a specific task and turn"
    echo -e "  ${GREEN}validate${NC}               - Validate all tasks in the repository"
    echo -e "  ${GREEN}categories${NC}             - Show tasks organized by category"
    echo -e "  ${GREEN}help${NC}                   - Show this help message"
    echo
    echo -e "${YELLOW}Examples:${NC}"
    echo -e "  $0 list"
    echo -e "  $0 info 387715"
    echo -e "  $0 run 387715 Turn_SimilarPrompt"
    echo -e "  $0 run 387708 Turn_0"
    echo
}

list_tasks() {
    echo -e "${BLUE}Available Interview Tasks:${NC}"
    echo -e "${YELLOW}===========================${NC}"
    
    for task_dir in Task_*/; do
        if [ -d "$task_dir" ]; then
            task_id=$(echo "$task_dir" | sed 's/Task_\([0-9]*\)\/.*/\1/')
            echo -e "${GREEN}Task $task_id${NC}"
            
            # Find and list turns
            for turn_dir in "$task_dir"Turn_*/; do
                if [ -d "$turn_dir" ]; then
                    turn=$(basename "$turn_dir")
                    echo -e "  ${CYAN}$turn${NC}"
                fi
            done
            echo
        fi
    done
}

show_categories() {
    echo -e "${BLUE}Tasks by Category:${NC}"
    echo -e "${YELLOW}==================${NC}"
    echo
    
    echo -e "${GREEN}Dynamic Programming:${NC}"
    echo -e "  Task 387695 - Grid path counting with overlapping rectangles"
    echo -e "  Task 387715 - Oil tanker compartment optimization"
    echo
    
    echo -e "${GREEN}String Processing:${NC}"
    echo -e "  Task 387708 - Text alliteration improvement"
    echo
    
    echo -e "${GREEN}Graph Algorithms:${NC}"
    echo -e "  Task 387725 - Flood fill algorithm (32xN image processing)"
    echo
    
    echo -e "${GREEN}Game Theory/Simulation:${NC}"
    echo -e "  Task 387724 - Rock-paper-scissors tournament simulation"
    echo
    
    echo -e "${GREEN}Other Algorithms:${NC}"
    echo -e "  Task 387701 - [Additional algorithm task]"
    echo -e "  Task 387706 - [Additional algorithm task]"
    echo -e "  Task 387718 - [Additional algorithm task]"
    echo
}

show_task_info() {
    local task_id="$1"
    local task_dir="Task_${task_id}"
    
    if [ ! -d "$task_dir" ]; then
        echo -e "${RED}Error: Task $task_id not found${NC}"
        return 1
    fi
    
    echo -e "${BLUE}Task $task_id Information:${NC}"
    echo -e "${YELLOW}==========================${NC}"
    
    # Find a README file
    readme_file=""
    for turn_dir in "$task_dir"/Turn_*/; do
        if [ -f "$turn_dir/Readme" ]; then
            readme_file="$turn_dir/Readme"
            break
        fi
    done
    
    if [ -n "$readme_file" ]; then
        echo -e "${GREEN}Problem Description:${NC}"
        head -20 "$readme_file"
        echo
    fi
    
    echo -e "${GREEN}Available Turns:${NC}"
    for turn_dir in "$task_dir"/Turn_*/; do
        if [ -d "$turn_dir" ]; then
            turn=$(basename "$turn_dir")
            echo -e "  ${CYAN}$turn${NC}"
            
            # Check if it builds successfully
            cd "$turn_dir"
            if make clean >/dev/null 2>&1 && make >/dev/null 2>&1; then
                echo -e "    ${GREEN}✓ Builds successfully${NC}"
            else
                echo -e "    ${RED}✗ Has compilation issues${NC}"
            fi
            cd - >/dev/null 2>&1
        fi
    done
    echo
}

run_task() {
    local task_id="$1"
    local turn="$2"
    
    if [ -z "$turn" ]; then
        turn="Turn_0"
    fi
    
    local task_path="Task_${task_id}/$turn"
    
    if [ ! -d "$task_path" ]; then
        echo -e "${RED}Error: Task $task_id/$turn not found${NC}"
        return 1
    fi
    
    echo -e "${BLUE}Running Task $task_id/$turn:${NC}"
    echo -e "${YELLOW}==============================${NC}"
    
    cd "$task_path"
    
    echo -e "${GREEN}Building...${NC}"
    if make clean && make; then
        echo
        echo -e "${GREEN}Executing:${NC}"
        echo -e "${YELLOW}----------${NC}"
        make run
    else
        echo -e "${RED}Build failed!${NC}"
        cd - >/dev/null 2>&1
        return 1
    fi
    
    cd - >/dev/null 2>&1
}

run_tests() {
    local task_id="$1"
    local turn="$2"
    
    if [ -z "$turn" ]; then
        turn="Turn_0"
    fi
    
    local task_path="Task_${task_id}/$turn"
    
    if [ ! -d "$task_path" ]; then
        echo -e "${RED}Error: Task $task_id/$turn not found${NC}"
        return 1
    fi
    
    echo -e "${BLUE}Testing Task $task_id/$turn:${NC}"
    echo -e "${YELLOW}==============================${NC}"
    
    cd "$task_path"
    
    if make test >/dev/null 2>&1; then
        echo -e "${GREEN}Running tests:${NC}"
        make test
    else
        echo -e "${YELLOW}No tests found, running main program:${NC}"
        make run
    fi
    
    cd - >/dev/null 2>&1
}

# Main script logic
case "${1:-help}" in
    "help"|"-h"|"--help")
        print_header
        print_help
        ;;
    "list")
        print_header
        list_tasks
        ;;
    "categories")
        print_header
        show_categories
        ;;
    "info")
        if [ -z "$2" ]; then
            echo -e "${RED}Error: Task ID required${NC}"
            echo -e "Usage: $0 info <task_id>"
            exit 1
        fi
        print_header
        show_task_info "$2"
        ;;
    "run")
        if [ -z "$2" ]; then
            echo -e "${RED}Error: Task ID required${NC}"
            echo -e "Usage: $0 run <task_id> [turn]"
            exit 1
        fi
        print_header
        run_task "$2" "$3"
        ;;
    "test")
        if [ -z "$2" ]; then
            echo -e "${RED}Error: Task ID required${NC}"
            echo -e "Usage: $0 test <task_id> [turn]"
            exit 1
        fi
        print_header
        run_tests "$2" "$3"
        ;;
    "validate")
        print_header
        echo -e "${GREEN}Running repository validation...${NC}"
        ./validate_repository.sh
        ;;
    *)
        print_header
        echo -e "${RED}Unknown command: $1${NC}"
        echo
        print_help
        exit 1
        ;;
esac