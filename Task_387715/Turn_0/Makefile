# Standard Makefile for AI-based C++ Interview Tasks
# This template works across different environments

# Compiler settings
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -I./src

# Try to find gtest - check multiple possible locations
GTEST_PATHS := /usr/include /usr/local/include /opt/homebrew/include
GTEST_LIB_PATHS := /usr/lib /usr/local/lib /opt/homebrew/lib

# Find gtest include directory
GTEST_INCLUDE := $(firstword $(foreach path,$(GTEST_PATHS),$(wildcard $(path)/gtest)))
ifneq ($(GTEST_INCLUDE),)
    CXXFLAGS += -I$(dir $(GTEST_INCLUDE))
    HAS_GTEST := 1
else
    HAS_GTEST := 0
endif

# Find gtest library directory
GTEST_LIB_DIR := $(firstword $(foreach path,$(GTEST_LIB_PATHS),$(wildcard $(path)/libgtest.a $(path)/libgtest.so)))
ifneq ($(GTEST_LIB_DIR),)
    LDFLAGS := -L$(dir $(GTEST_LIB_DIR)) -lgtest -lgtest_main -lpthread
else
    LDFLAGS := -lgtest -lgtest_main -lpthread
endif

# Directories
SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_FILES))

# Exclude main.o for tests
OBJ_FILES_EXCLUDE_MAIN := $(filter-out $(BUILD_DIR)/main.o, $(OBJ_FILES))

# Targets
BINARY := main
TEST_BINARY := test_runner

# Colors for output
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;33m
NC := \033[0m # No Color

# Default target
all: $(BUILD_DIR)/$(BINARY)

# Build main binary
$(BUILD_DIR)/$(BINARY): $(OBJ_FILES) | $(BUILD_DIR)
	@echo "$(GREEN)Building main executable...$(NC)"
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(GREEN)✓ Build successful!$(NC)"

# Build test binary (only if test files exist)
$(BUILD_DIR)/$(TEST_BINARY): $(OBJ_FILES_EXCLUDE_MAIN) $(TEST_OBJ_FILES) | $(BUILD_DIR)
	@if [ "$(HAS_GTEST)" = "0" ]; then \
		echo "$(YELLOW)Warning: GoogleTest not found. Skipping test build.$(NC)"; \
		exit 1; \
	fi
	@echo "$(GREEN)Building test executable...$(NC)"
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "$(GREEN)✓ Test build successful!$(NC)"

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@echo "$(GREEN)Compiling $<...$(NC)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	@echo "$(GREEN)Compiling test $<...$(NC)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Run main program
run: $(BUILD_DIR)/$(BINARY)
	@echo "$(GREEN)Running main program:$(NC)"
	@echo "$(YELLOW)=====================================$(NC)"
	@./$(BUILD_DIR)/$(BINARY)
	@echo "$(YELLOW)=====================================$(NC)"

# Run tests
test: $(BUILD_DIR)/$(TEST_BINARY)
	@echo "$(GREEN)Running tests:$(NC)"
	@echo "$(YELLOW)=====================================$(NC)"
	@./$(BUILD_DIR)/$(TEST_BINARY)
	@echo "$(YELLOW)=====================================$(NC)"

# Run tests if they exist, otherwise run main
check: $(BUILD_DIR)/$(BINARY)
	@if [ -f "$(BUILD_DIR)/$(TEST_BINARY)" ]; then \
		$(MAKE) test; \
	else \
		echo "$(YELLOW)No tests found, running main program:$(NC)"; \
		$(MAKE) run; \
	fi

# Clean build directory
clean:
	@echo "$(GREEN)Cleaning build directory...$(NC)"
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)✓ Clean complete!$(NC)"

# Show help
help:
	@echo "$(GREEN)Available targets:$(NC)"
	@echo "  $(YELLOW)all$(NC)     - Build main executable"
	@echo "  $(YELLOW)test$(NC)    - Build and run tests (requires GoogleTest)"
	@echo "  $(YELLOW)run$(NC)     - Build and run main program"
	@echo "  $(YELLOW)check$(NC)   - Run tests if available, otherwise run main"
	@echo "  $(YELLOW)clean$(NC)   - Remove build directory"
	@echo "  $(YELLOW)help$(NC)    - Show this help message"

.PHONY: all test run check clean help