# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 17:04:02 by imunaev-          #+#    #+#              #
#    Updated: 2025/01/10 17:20:22 by imunaev-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Helper function to print section headers in color
function print_header() {
    echo ""
    echo "======================================"
    echo -e "\033[34m$1\033[0m"
    echo "======================================"
}

# Function to run a test for ERROR MANAGEMENT TESTS (includes push_swap output)
function run_error_test() {
    local description=$1
    local arg=$2

    echo -e "\033[34m$description\033[0m"
    ARG="$arg"

    ps_out="$(./push_swap $ARG 2>&1)"
    checker_out=$(echo "$ps_out" | ./checker_linux $ARG 2>&1)

    # Check if outputs match
    if [[ "$ps_out" == "$checker_out" ]]; then
        echo -e "\033[32mPush_swap output: $ps_out\033[0m"
        echo -e "\033[32mChecker output: $checker_out\033[0m"
    else
        echo -e "\033[31mPush_swap output: $ps_out\033[0m"
        echo -e "\033[31mChecker output: $checker_out\033[0m"
    fi

    echo ""
}

# Function to run a test for other sections (no push_swap output)
function run_test() {
    local description=$1
    local arg=$2

    # ====================================
    # SPECIAL CASES
    # ====================================
    if [[ "$description" == "Single element" || "$description" == "Already sorted list" ]]; then
        echo -e "\033[34m$description\033[0m"
        ARG="$arg"

        # Run push_swap only, skip checker output
        ps_out="$(./push_swap $ARG 2>&1)"

        echo "Push_swap output: $ps_out"
        echo ""
        return 0
    fi

    # ====================================
    # REGULAR CASES
    # ====================================
    echo -e "\033[34m$description\033[0m"
    ARG="$arg"

    # Capture push_swap output and checker output
    ps_out="$(./push_swap $ARG 2>&1)"
    checker_out=$(echo "$ps_out" | ./checker_linux $ARG 2>&1)
    moves=$(echo "$ps_out" | wc -l)

    # Display checker output only
    if [[ "$checker_out" == "Error" ]]; then
        echo -e "\033[31mChecker output: $checker_out\033[0m"
    else
        echo -e "\033[32mChecker output: $checker_out\033[0m"
    fi

    # Display the number of moves only if checker output is OK
    if [[ "$checker_out" == "OK" ]]; then
        echo "Number of moves: $moves"
    fi

    echo ""
}

####################################
#             MAIN SCRIPT          #
####################################

# --------------------------------------------------------------------------
# ERROR MANAGEMENT TESTS
# --------------------------------------------------------------------------

print_header "ERROR MANAGEMENT TESTS"

declare -A test_cases=(
    ["No parameters"]=""
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
    ["Empty string: '  '"]="  "
    ["Invalid leading zeros: '0123'"]="0123"
    ["Invalid mixed leading zeros: '7 66 07'"]="7 66 07"
)

# Run all error management tests with push_swap output
for desc in "${!test_cases[@]}"; do
    run_error_test "$desc" "${test_cases[$desc]}"
done

# --------------------------------------------------------------------------
# SIMPLE TESTS
# --------------------------------------------------------------------------

print_header "IDENTITY AND SIMPLE TESTS"
run_test "Single element" "42"
run_test "Already sorted list" "0 1 2 3"
run_test "6 values + INT_MAX and INT_MIN" "-7 2147483647 77 41 0 -2147483648"
run_test "2 random values" "2 -5"
run_test "3 random values" "2 1 0"
run_test "5 random values" "1 5 2 4 3"

# --------------------------------------------------------------------------
# LARGER RANDOM TESTS
# --------------------------------------------------------------------------

print_header "LARGER RANDOM TESTS"
run_test "100 random distinct values" "$(shuf -i 0-999 -n 100 | tr '\n' ' ')"
run_test "500 random distinct values" "$(shuf -i 0-9999 -n 500 | tr '\n' ' ')"
run_test "1000 random distinct values" "$(seq -100000 100000 | shuf -n 1000 | tr '\n' ' ')"
run_test "2000 random distinct values" "$(seq -100000 100000 | shuf -n 2000 | tr '\n' ' ')"

# Uncomment the line below for larger tests, but be cautious with resources
# run_test "10,000 random distinct values" "$(seq -100000 100000 | shuf -n 10000 | tr '\n' ' ')"

echo "All tests completed."
