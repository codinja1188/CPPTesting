# AI-Based C++ Interview Repository

This repository contains a collection of AI-based C++ coding interview problems designed to test algorithmic thinking and implementation skills. Each task represents a different algorithmic challenge with multiple solution attempts and comprehensive test cases.

## Repository Structure

```
CPPTesting/
├── Task_387695/          # Grid path counting problem
├── Task_387701/          # [Problem description TBD]
├── Task_387706/          # [Problem description TBD]
├── Task_387708/          # Text alliteration improvement
├── Task_387715/          # Oil tanker compartment optimization
├── Task_387718/          # [Problem description TBD]
├── Task_387724/          # Rock-paper-scissors tournament
├── Task_387725/          # Flood fill algorithm
├── Makefile.template     # Standardized build configuration
└── update_makefiles.sh   # Script to update all Makefiles
```

### Task Structure

Each task directory contains multiple "turns" representing different solution attempts:
- `Turn_0/` - Initial solution attempt
- `Turn_1/` - Refined solution
- `Turn_Ideal/` - Optimal solution
- Additional turns as needed

Each turn contains:
- `src/` - Source code files (`app.h`, `app.cpp`, `main.cpp`)
- `test/` - Unit tests (when applicable)
- `Makefile` - Build configuration
- `Readme` - Problem description and requirements

## Quick Start

### Prerequisites
- C++17 compatible compiler (g++ recommended)
- Make build system
- GoogleTest (optional, for unit tests)

### Building and Running

Navigate to any task directory and use the standardized Makefile:

```bash
cd Task_387715/Turn_SimilarPrompt/

# Build the project
make

# Run the main program
make run

# Run tests (if available)
make test

# Clean build artifacts
make clean

# Show available commands
make help
```

### Available Make Targets

- `make all` - Build main executable (default)
- `make run` - Build and run main program with formatted output
- `make test` - Build and run unit tests (requires GoogleTest)
- `make check` - Run tests if available, otherwise run main program
- `make clean` - Remove build directory
- `make help` - Show help message

## Problem Categories

### 1. Dynamic Programming
- **Task_387695**: Grid path counting with overlapping rectangles
- **Task_387715**: Oil tanker compartment optimization

### 2. String Processing
- **Task_387708**: Text alliteration improvement

### 3. Graph Algorithms
- **Task_387725**: Flood fill algorithm (32xN image processing)

### 4. Game Theory/Simulation
- **Task_387724**: Rock-paper-scissors tournament simulation

### 5. Other Algorithms
- Additional tasks covering various algorithmic concepts

## Key Features

### Standardized Build System
- Cross-platform Makefile template
- Automatic GoogleTest detection
- Colored output for better readability
- Consistent error handling

### Code Quality Standards
- C++17 standard compliance
- Strict compiler warnings (`-Wall -Wextra -Werror`)
- Consistent coding style
- Comprehensive error checking

### Test Infrastructure
- Unit tests using GoogleTest framework
- Automated test discovery
- Clear test output formatting
- Assertion-based validation

## Development Workflow

### Adding New Problems

1. Create a new task directory: `Task_XXXXXX/`
2. Create initial turn: `Turn_0/`
3. Copy template structure:
   ```bash
   mkdir -p Task_XXXXXX/Turn_0/{src,test}
   cp Makefile.template Task_XXXXXX/Turn_0/Makefile
   ```
4. Implement the solution in `src/app.cpp`
5. Add tests in `main.cpp` or `test/test.cpp`
6. Document the problem in `Readme`

### Code Quality Guidelines

- Use meaningful variable names
- Add comments for complex algorithms
- Handle edge cases appropriately
- Provide comprehensive test coverage
- Follow C++17 best practices

## Building All Tasks

To verify all tasks build correctly:

```bash
# Update all Makefiles to latest template
./update_makefiles.sh

# Test build for all tasks
find . -name "Makefile" -execdir make clean \; -execdir make \;
```

## Contributing

When contributing new solutions or improvements:

1. Maintain consistent code style
2. Ensure all compiler warnings are resolved
3. Add comprehensive test cases
4. Update documentation as needed
5. Test on multiple platforms if possible

## License

This repository is intended for educational and interview preparation purposes.