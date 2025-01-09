# IN PROGRESS !!! ----------------------

# Tests for Push_Swap

## **How to Run All Tests**

1. Navigate to the `tests` directory:
   ```bash
   cd tests
   ```

2. Run all the test cases at once:
   ```bash
   make run_tests
   ```

---

## **Memory Leak Testing**

Use `valgrind` to check for memory leaks in the `push_swap` program:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap
```

- **Explanation**:
  - `--leak-check=full`: Provides detailed information about memory leaks.
  - `--show-leak-kinds=all`: Displays all types of memory leaks.
  - `--track-origins=yes`: Tracks the origin of uninitialized values.

---

## **Debugging with AddressSanitizer**

To compile and test individual files with AddressSanitizer:

```bash
cc -fsanitize=address -g -O1 <test_file>.c -o a.out
./a.out
```

- **Flags**:
  - `-fsanitize=address`: Detects memory-related bugs like buffer overflows and use-after-free.
  - `-g`: Generates debug symbols for detailed stack traces.
  - `-O1`: Optimizes code for debugging.

---

## **Testing with Checker**

To validate your `push_swap` program with the `checker` tool:

1. Provide an input argument and run:

   ```bash
   ARG="<your_values>"; ./push_swap $ARG | ./checker_linux $ARG
   ```

   - Replace `<your_values>` with a list of integers (e.g., `1 2 3`).

2. Count the number of operations performed:

   ```bash
   ARG="<your_values>"; ./push_swap $ARG | wc -l
   ```

   - This prints the total number of operations used by your `push_swap` implementation.

---

### Example Usage:

- Run tests for input `3 2 1`:
  ```bash
  ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
  ```

- Count operations for `3 2 1`:
  ```bash
  ARG="3 2 1"; ./push_swap $ARG | wc -l
  ```

---

## **Notes**

- Ensure that `checker_linux` is in the same directory as `push_swap` or update the path accordingly.
- Use `make clean` or `make fclean` to clean up compiled files and directories.

## Number generator
https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php
