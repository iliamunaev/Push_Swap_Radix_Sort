#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+         #
#    Created: 2025/01/10 22:44:03 by imunaev-          #+#    #+#              #
#    Updated: 2025/01/10 22:44:06 by imunaev-         ###   ########.fr        #
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
# ERROR MANAGEMENT TESTS
# (Shows push_swap output directly)
# -----------------------------
function run_error_test() {
  local description="$1"
  local arg="$2"

  echo -e "\033[34m$description\033[0m"
  ARG="$arg"

  # Capture push_swap output (including any errors)
  ps_out="$(./push_swap $ARG 2>&1)"

  # Check if push_swap indicates an error
  if [[ "$ps_out" == "Error" ]]; then
    echo -e "\033[32mPush_swap output: $ps_out\033[0m"
  else
    echo -e "\033[31mPush_swap output: $ps_out\033[0m"
  fi

  echo ""

  # Pause for 1 second before the next test
  sleep 0.5
}

# -----------------------------
# REGULAR / SIMPLE TESTS
# (Checks with checker + counts moves)
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

  # Check sorting correctness with checker
  checker_output=$(echo "$ps_out" | ./checker_linux $ARG)

  # Print push_swap output if you want to see the commands
  # echo "Push_swap output:"
  # echo "$ps_out"

  # Print result of the checker
  if [[ "$checker_output" == "OK" ]]; then
    echo -e "\033[32mChecker result: $checker_output\033[0m"
  else
    echo -e "\033[31mChecker result: $checker_output\033[0m"
  fi

  # Print the number of moves
  echo "Number of moves: $moves"
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

run_test "6 values + INT_MAX and INT_MIN" "-7 2147483647 77 41 0 -2147483648"
run_test "2 random values" "2 -5"
run_test "3 random values" "2 1 0"
run_test "5 random values" "1 5 2 4 3"

# 3. LARGER RANDOM TESTS
print_header "LARGER RANDOM TESTS"

run_test "50 random distinct values"  "$(shuf -i 0-999 -n 50 | tr '\n' ' ')"
run_test "100 random distinct values"  "$(shuf -i 0-999 -n 100 | tr '\n' ' ')"
run_test "500 random distinct values"  "$(shuf -i 0-9999 -n 500 | tr '\n' ' ')"
run_test "1000 random distinct values" "$(seq -100000 100000 | shuf -n 1000 | tr '\n' ' ')"
run_test "1500 random distinct values" "$(seq -100000 100000 | shuf -n 1500 | tr '\n' ' ')"
run_test "2000 random distinct values" "$(seq -100000 100000 | shuf -n 2000 | tr '\n' ' ')"

# Uncomment for a larger stress test (may take a while)

run_test "5000 random distinct values" "$(seq -100000 100000 | shuf -n 5000 | tr '\n' ' ')"
run_test "8000 random distinct values" "$(seq -100000 100000 | shuf -n 8000 | tr '\n' ' ')"
run_test "10000 random distinct values" "$(seq -100000 100000 | shuf -n 10000 | tr '\n' ' ')"


echo "All tests completed."
