# Variables
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I./src

# Directories
SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build

# Source and Object files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_FILES))

# Exclude main.o for tests
OBJ_FILES_EXCLUDE_MAIN := $(filter-out $(BUILD_DIR)/main.o, $(OBJ_FILES))

# Targets
BINARY := main
TEST_BINARY := test_runner

# Try to find gtest
GTEST_CFLAGS := $(shell pkg-config --cflags gtest 2>/dev/null || echo "-I/usr/include")
GTEST_LDFLAGS := $(shell pkg-config --libs gtest gtest_main 2>/dev/null || echo "-lgtest -lgtest_main -lpthread")

# Default Target
all: $(BUILD_DIR)/$(BINARY)

# Build main binary
$(BUILD_DIR)/$(BINARY): $(OBJ_FILES)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build test binary
$(BUILD_DIR)/$(TEST_BINARY): $(OBJ_FILES_EXCLUDE_MAIN) $(TEST_OBJ_FILES)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(GTEST_CFLAGS) -o $@ $^ $(GTEST_LDFLAGS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(GTEST_CFLAGS) -c $< -o $@

# Run tests
test: $(BUILD_DIR)/$(TEST_BINARY)
	./$<

# Run main
run: $(BUILD_DIR)/$(BINARY)
	./$<

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean test run
