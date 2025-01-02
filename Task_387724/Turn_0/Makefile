# Variables
CXX := g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./src -I/opt/homebrew/Cellar/googletest/1.15.2/include
LDFLAGS = -L/opt/homebrew/Cellar/googletest/1.15.2/lib -lgtest -lgtest_main -lpthread

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

# Default Target
all: $(BUILD_DIR)/$(BINARY)

# Build main binary
$(BUILD_DIR)/$(BINARY): $(OBJ_FILES)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build test binary
$(BUILD_DIR)/$(TEST_BINARY): $(OBJ_FILES_EXCLUDE_MAIN) $(TEST_OBJ_FILES)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
test: $(BUILD_DIR)/$(TEST_BINARY)
	./$<

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean test
