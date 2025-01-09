#!/bin/bash

# Helper function to print section headers
function print_header() {
    echo ""
    echo "======================================"
    echo -e "\033[34m$1\033[0m"
    echo "======================================"
}

####################################
#             MAIN SCRIPT          #
####################################

# ---------------------------
# Error Management Tests
# ---------------------------


print_header "1. No parameters"

echo "ARG=''"

ARG=""
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

print_header "2. Non-numeric parameters"
echo "ARG='a b c'"
ARG="a b c"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

echo "ARG=' !2 1 0'"
ARG=" !2 1 0"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

print_header "3. Duplicates"

echo "ARG='2 1 0 2 1'"

ARG="2 1 0 2 1"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

print_header "4. Numbers out of range > INT_MAX"

echo "ARG='1 2147483648'"

ARG="1 2147483648"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

print_header "5. Numbers out of range < INT_MIN"

echo "ARG='1 -2147483649'"

ARG="1 -2147483649"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""


# ---------------------------
# Identity Tests
# ---------------------------

print_header "6. Single element"

echo "ARG='42'"
ARG="42"

# Capture push_swap output
ps_out="$(./push_swap $ARG 2>&1 | tr -d '\r')"

# Debug: Print raw output and its length
echo "Raw push_swap output: '$ps_out'"
echo "Length of ps_out: ${#ps_out}"

# Handle empty ps_out explicitly
if [ -z "$ps_out" ]; then
    echo "Passing to checker_linux: <empty newline>"
    checker_result=$(echo -e "\n" | ./checker_linux $ARG)
else
    echo "Passing to checker_linux: <$ps_out>"
    checker_result=$(echo -e "$ps_out\n" | ./checker_linux $ARG)
fi

# Measure execution time
start_time=$(date +%s%N)
end_time=$(date +%s%N)

# Calculate elapsed time
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

# Count number of moves (ensure no newline misinterpretation)
moves=$(echo -n "$ps_out" | wc -l)

# Print results
echo "Checker result: $checker_result"
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""


# ---------------------------

print_header "Sorted list"

echo "ARG='0 1 2 3'"

ARG="0 1 2 3"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------
# Simple Version Tests
# ---------------------------

print_header "2 random values"

echo "ARG=' 2 -5'"

ARG=" 2 -5"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

print_header "2 values: INT_MAX, INT_MIN"

echo "ARG='2147483647 -2147483648'"

ARG="2147483647 -2147483648"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

print_header "3 random values"

echo "ARG='2 1 0'"

ARG="2 1 0"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

print_header "5 random values"

echo "ARG='1 5 2 4 3'"

ARG="1 5 2 4 3"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------
# Middle Version Tests
# ---------------------------

print_header "100 random values"

ARG=$(shuf -i 0-99 -n 100 | tr '\n' ' ')
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------
# Advanced Version Tests
# ---------------------------

print_header "500 random values"

ARG=$(shuf -i 0-499 -n 500 | tr '\n' ' ')
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

print_header "1000 random values"

ARG=$(seq -1000000 1000000 | shuf -n 1000 | tr '\n' ' ')
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

print_header "2000 random values"

ARG=$(seq -1000000 1000000 | shuf -n 2000 | tr '\n' ' ')
echo "---------------2000 random values (-1000000 to 1000000)"
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""
