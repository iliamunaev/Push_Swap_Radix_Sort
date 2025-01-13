#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_valgrind_tests.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 18:59:52 by imunaev-          #+#    #+#              #
#    Updated: 2025/01/13 19:00:00 by imunaev-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------
# Colorful Section Headers
# -----------------------------
function print_header() {
  echo ""
  echo "======================================"
  echo -e "\033[34m$1\033[0m"
  echo "======================================"
}

# -----------------------------
# RUN VALGRIND TEST
# -----------------------------
function run_valgrind_test() {
  local description="$1"
  local arg="$2"

  echo -e "\033[34m$description\033[0m"
  ARG="$arg"

  # Run push_swap under Valgrind
  valgrind_output=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./push_swap $ARG 2>&1)

  # Display Valgrind output summary
  grep -A 10 "HEAP SUMMARY" valgrind.log

  # Indicate whether memory leaks were detected
  if grep -q "All heap blocks were freed -- no leaks are possible" valgrind.log; then
    echo -e "\033[32mNo memory leaks detected.\033[0m"
  else
    echo -e "\033[31mMemory leaks detected! Check valgrind.log for details.\033[0m"
  fi

  echo ""

  # Pause for 1 second before the next test
  sleep 0.5
}

# -----------------------------
# ERROR MANAGEMENT TESTS
# -----------------------------
function run_error_test() {
  local description="$1"
  local arg="$2"

  echo -e "\033[34m$description\033[0m"
  ARG="$arg"

  # Capture push_swap output
  ps_out="$(./push_swap $ARG 2>&1)"

  # Check if push_swap indicates an error
  if [[ "$ps_out" == "Error" ]]; then
    echo -e "\033[32mPush_swap output: $ps_out\033[0m"
  else
    echo -e "\033[31mPush_swap output: $ps_out\033[0m"
  fi

  # Run Valgrind for the test
  run_valgrind_test "$description (Valgrind Test)" "$ARG"

  echo ""

  # Pause for 1 second before the next test
  sleep 0.5
}

# -----------------------------
# REGULAR / SIMPLE TESTS
# -----------------------------
function run_test() {
  local description="$1"
  local arg="$2"

  echo -e "\033[34m$description\033[0m"
  ARG="$arg"

  # Capture push_swap output
  ps_out="$(./push_swap $ARG 2>&1)"

  # Count the number of lines only if there is output
  if [[ -z "$ps_out" ]]; then
    moves=0
  else
    moves=$(wc -l <<< "$ps_out")
  fi

  # Print push_swap output if you want to see the commands
  # echo "Push_swap output:"
  # echo "$ps_out"

  # Check if push_swap indicates an error
  if [[ "$ps_out" == "Error" ]]; then
    echo -e "\033[31mPush_swap output: $ps_out\033[0m"
  else
    echo -e "\033[32mPush_swap completed successfully.\033[0m"
    echo "Number of moves: $moves"
  fi

  # Run Valgrind for the test
  run_valgrind_test "$description (Valgrind Test)" "$ARG"

  echo ""

  # Pause for 1 second before the next test
  sleep 0.5
}

# =============================
#            MAIN
# =============================

# 1. ERROR MANAGEMENT TESTS
print_header "ERROR MANAGEMENT TESTS"

declare -A test_cases=(
  ["Non-numeric: 'a b c'"]="a b c"
  ["Non-numeric: '!2 1 0'"]="!2 1 0"
  ["Single sign: '+'"]="+"
  ["Single sign: '-'"]="-"
  ["Consecutive signs: '--'"]="--"
  ["Consecutive signs: '++'"]="++"
  ["Duplicate numbers"]="-1 2 0 -1 2"
  ["Out of range > INT_MAX"]="1 -4 2147483648"
  ["Out of range < INT_MIN"]="1 -4 -2147483649"
  ["Leading zeros: '-01'"]="-01"
  ["Leading zeros: '+01'"]="+01"
  ["Leading zeros: '01'"]="01"
  ["Multiple signs: '--1'"]="--1"
  ["Multiple signs: '++1'"]="++1"
  ["Plus with space: '+ 42'"]="+ 42"
  ["Invalid leading zeros: '0123'"]="0123"
  ["Invalid mixed leading zeros: '7 66 07'"]="7 66 07"
)

for desc in "${!test_cases[@]}"; do
  run_error_test "$desc" "${test_cases[$desc]}"
done

# 2. SIMPLE TESTS
print_header "IDENTITY AND SIMPLE TESTS"

run_test "Empty string: '  '. Empty output" "  "
run_test "Zero parameters. Empty output" ""
run_test "Single element" "42"
run_test "Already sorted list" "0 1 2 3"
run_test "6 values + INT_MAX and INT_MIN" "-7 2147483647 77 41 0 -2147483648"
run_test "2 random values" "2 -5"
run_test "3 random values" "2 1 0"
run_test "5 random values" "1 5 2 4 3"

# 3. LARGER RANDOM TESTS
print_header "LARGER RANDOM TESTS"

run_test "100 random distinct values" "$(seq -100000 100000 | shuf -n 100 | tr '\n' ' ')"
run_test "500 random distinct values" "$(seq -100000 100000 | shuf -n 500 | tr '\n' ' ')"

# Uncomment for a larger stress test (may take a while)
# run_test "1000 random distinct values" "$(seq -100000 100000 | shuf -n 1000 | tr '\n' ' ')"

echo "All tests completed."
