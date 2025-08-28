#!/bin/bash

# Script to fix common compilation warnings across all tasks
# This script will attempt to fix signed/unsigned comparison issues automatically

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== Fixing Compilation Warnings Across Repository ===${NC}"
echo

# Function to fix signed/unsigned comparison in a file
fix_signed_unsigned() {
    local file="$1"
    local temp_file="${file}.tmp"
    
    # Common patterns to fix:
    # int i; i < container.size()  -> size_t i; i < container.size()
    # int i; i >= container.size() -> size_t i; i >= container.size() 
    # container.size() > int_var   -> container.size() > static_cast<size_t>(int_var)
    # etc.
    
    echo -e "${YELLOW}  Fixing signed/unsigned comparisons in $file${NC}"
    
    sed -E '
        # Fix: for(int i = 0; i < container.size(); ++i)
        s/for\s*\(\s*int\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*0\s*;\s*\1\s*<\s*([a-zA-Z_][a-zA-Z0-9_]*\.size\(\))/for(size_t \1 = 0; \1 < \2/g
        
        # Fix: for(int i = 0; i < container.size(); i++)
        s/for\s*\(\s*int\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*0\s*;\s*\1\s*<\s*([a-zA-Z_][a-zA-Z0-9_]*\.size\(\))\s*;\s*\1\+\+\s*\)/for(size_t \1 = 0; \1 < \2; \1++)/g
        s/for\s*\(\s*int\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*0\s*;\s*\1\s*<\s*([a-zA-Z_][a-zA-Z0-9_]*\.size\(\))\s*;\s*\+\+\1\s*\)/for(size_t \1 = 0; \1 < \2; ++\1)/g
        
        # Fix int variable declarations when used with size()
        s/int\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*0\s*;/size_t \1 = 0;/g
    ' "$file" > "$temp_file"
    
    if [ -s "$temp_file" ]; then
        mv "$temp_file" "$file"
        echo -e "${GREEN}    ✓ Fixed patterns in $file${NC}"
    else
        rm -f "$temp_file"
        echo -e "${RED}    ✗ No changes needed or error in $file${NC}"
    fi
}

# Find all app.cpp files and attempt to fix them
find . -path "./Task_*" -name "app.cpp" | while read cpp_file; do
    echo -e "${BLUE}Processing: $cpp_file${NC}"
    
    # Check if the file has signed/unsigned comparison issues
    dir=$(dirname "$cpp_file")
    cd "$dir"
    
    if make clean >/dev/null 2>&1 && make 2>&1 | grep -q "sign-compare"; then
        echo -e "${YELLOW}  Found signed/unsigned comparison issues${NC}"
        fix_signed_unsigned "$cpp_file"
        
        # Test if the fix worked
        if make clean >/dev/null 2>&1 && make >/dev/null 2>&1; then
            echo -e "${GREEN}  ✓ Compilation fixed!${NC}"
        else
            echo -e "${RED}  ✗ Still has compilation issues - manual fix needed${NC}"
            # Show the errors
            make 2>&1 | head -3
        fi
    else
        echo -e "${GREEN}  ✓ No signed/unsigned comparison issues found${NC}"
    fi
    
    echo
    cd - >/dev/null 2>&1
done

echo -e "${BLUE}=== Warning Fix Complete ===${NC}"