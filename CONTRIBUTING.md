# Contributing to Process Scheduling Algorithms

Thank you for your interest in contributing to this project! This document provides guidelines and instructions for contributing.

## Code Style Guidelines

1. **Naming Conventions**
   - Use camelCase for method names and variables
   - Use PascalCase for class names
   - Use snake_case for file names
   - Use UPPER_CASE for constants

2. **Documentation**
   - All classes must have Doxygen-style documentation
   - Document all public methods with parameters and return values
   - Add inline comments for complex logic
   - Keep documentation up to date with code changes

3. **Code Organization**
   - One class per file
   - Group related functionality together
   - Use appropriate access modifiers (public, private, protected)
   - Follow the existing project structure

## How to Contribute

1. **Fork the Repository**
   - Click the 'Fork' button on GitHub
   - Clone your fork locally
   ```bash
   git clone https://github.com/your-username/process_scheduling_algos.git
   ```

2. **Create a Branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **Make Changes**
   - Follow the code style guidelines
   - Add tests if applicable
   - Update documentation
   - Ensure all existing tests pass

4. **Commit Your Changes**
   - Write clear, concise commit messages
   - Reference any relevant issues
   ```bash
   git commit -m "Add feature: description of changes"
   ```

5. **Push to Your Fork**
   ```bash
   git push origin feature/your-feature-name
   ```

6. **Submit a Pull Request**
   - Go to the original repository
   - Click 'New Pull Request'
   - Select your branch
   - Fill in the PR template
   - Wait for review

## Adding New Scheduling Algorithms

1. **Create New Files**
   - Add header file (`NewAlgorithm.h`)
   - Add implementation file (`NewAlgorithm.cpp`)
   - Follow existing class structure

2. **Implement Required Methods**
   - Inherit from `SchedulingAlgorithm`
   - Implement `solve()` method
   - Add Gantt chart display
   - Calculate all metrics

3. **Update Main Program**
   - Add algorithm to menu
   - Add case in switch statement
   - Update utility functions

4. **Add Documentation**
   - Document algorithm characteristics
   - Add usage examples
   - Update README.md

## Testing

1. **Test Cases**
   - Test with different process counts
   - Test edge cases (0 burst time, same arrival times)
   - Test with varying priorities/time quantum
   - Verify metrics calculations

2. **Performance Testing**
   - Test with large number of processes
   - Compare with other algorithms
   - Document performance characteristics

## Questions or Issues?

- Open an issue for bugs or feature requests
- Join discussions in existing issues
- Contact maintainers for clarification

## Code of Conduct

- Be respectful and inclusive
- Focus on constructive feedback
- Help others learn and grow
- Follow project guidelines

Thank you for contributing! 