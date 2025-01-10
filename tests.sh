#!/bin/bash

# Helper function to print section headers in color
function print_header() {
    echo ""
    echo "======================================"
    echo -e "\033[34m$1\033[0m"
    echo "======================================"
}

####################################
#             MAIN SCRIPT          #
####################################

# ------------------------------------------------------------------------------
# ERROR MANAGEMENT TESTS
# ------------------------------------------------------------------------------

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

print_header "3. Duplicates (explicitly testing repeated numbers)"
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


# ------------------------------------------------------------------------------
# IDENTITY / SIMPLE TESTS
# ------------------------------------------------------------------------------

print_header "6. Single element"
echo "ARG='42'"
ARG="42"
ps_out="$(./push_swap $ARG 2>&1 | tr -d '\r')"

# If push_swap output is empty, pass a blank line to checker
if [ -z "$ps_out" ]; then
    checker_result=$(echo -e "\n" | ./checker_linux $ARG)
else
    checker_result=$(echo -e "$ps_out\n" | ./checker_linux $ARG)
fi

start_time=$(date +%s%N)
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo -n "$ps_out" | wc -l)

echo "Checker result: $checker_result"
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""

# ---------------------------

print_header "7. Already-sorted list"
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

print_header "8. 2 random values"
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

print_header "9. 2 values: INT_MAX, INT_MIN"
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

print_header "10. 3 random values"
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

print_header "11. 5 random values"
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


# ------------------------------------------------------------------------------
# LARGER RANDOM TESTS (NO DUPLICATES, THANKS TO SHUF)
# ------------------------------------------------------------------------------

print_header "12. 100 random distinct values"
# shuf -i 0-999 => picks from 0..999
# -n 100 => picks 100 distinct numbers
ARG=$(shuf -i 0-999 -n 100 | tr '\n' ' ')
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

print_header "13. 500 random distinct values"
# Picks 500 distinct numbers from 0..9999
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
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

print_header "14. 1000 random distinct values"
# Picks 1000 distinct numbers from -100000..100000
ARG=$(seq -100000 100000 | shuf -n 1000 | tr '\n' ' ')
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

print_header "15. 2000 random distinct values"
echo "----------- 2000 random distinct values in [-100000,100000]"
ARG=$(seq -100000 100000 | shuf -n 2000 | tr '\n' ' ')
ps_out="$(./push_swap $ARG 2>&1)"
start_time=$(date +%s%N)
echo "$ps_out" | ./checker_linux $ARG
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
moves=$(echo "$ps_out" | wc -l)
echo "Number of moves: $moves"
echo "Time (push_swap + checker): ${total_elapsed_ms} ms"
echo ""
