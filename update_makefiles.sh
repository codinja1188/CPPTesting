#!/bin/bash

# Script to update all Makefiles in the repository with the standardized template

# Colors for output
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}Updating all Makefiles with standardized template...${NC}"

# Find all directories containing Makefiles
find . -name "Makefile" -type f | while read makefile; do
    dir=$(dirname "$makefile")
    echo -e "${YELLOW}Updating: $makefile${NC}"
    cp Makefile.template "$makefile"
done

echo -e "${GREEN}✓ All Makefiles updated successfully!${NC}"