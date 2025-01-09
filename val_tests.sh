#!/bin/bash

# Helper function to print section headers
function print_header() {
    echo ""
    echo "======================================"
    echo "$1"
    echo "======================================"
}

####################################
#            MAIN SCRIPT           #
####################################

# Define Valgrind command + flags here (adjust as needed).
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all"

##############################################################################
# ERROR MANAGEMENT TESTS
##############################################################################
print_header "ERROR MANAGEMENT TESTS"

echo "[1] Non-numeric parameters"
ARG="a b c"
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))
# Separate push_swap output vs. Valgrind messages
ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG 2>&1)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""

echo "[2] Duplicate numeric parameters"
ARG="2 1 0 2 1"
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG 2>&1)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""

echo "[3] Numbers out of range > INT_MAX"
ARG="1 2147483648"
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG 2>&1)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""

echo "[4] Numbers out of range < INT_MIN"
ARG="1 -2147483649"
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG 2>&1)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""

echo "[5] No parameters"
ARG=""
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG 2>&1)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""

echo "[6] Empty string"
ARG=""
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG 2>&1)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""


##############################################################################
# IDENTITY TESTS
##############################################################################
print_header "IDENTITY TESTS"

echo "[1] Single element"
ARG="42"
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""

echo "[2] Already sorted list"
ARG="0 1 2 3"
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""


##############################################################################
# SIMPLE VERSION TESTS
##############################################################################
print_header "SIMPLE VERSION TESTS"

echo "[1] Simple 3-element unsorted list"
ARG="2 1 0"
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""

echo "[2] Simple 5-element unsorted list"
ARG="1 5 2 4 3"
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""


##############################################################################
# MIDDLE VERSION TESTS (100 random values)
##############################################################################
print_header "MIDDLE VERSION TESTS"

echo "[1] 100 random values (range 0..99)"
ARG=$(shuf -i 0-99 -n 100 | tr '\n' ' ')
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""


##############################################################################
# ADVANCED VERSION TESTS
##############################################################################
print_header "ADVANCED VERSION TESTS"

echo "[1] 500 random values (range 0..499)"
ARG=$(shuf -i 0-499 -n 500 | tr '\n' ' ')
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""

print_header "ADVANCED VERSION TESTS (1000 random values)"

echo "[2] 1000 random values (range -1000000..1000000)"
ARG=$(seq -1000000 1000000 | shuf -n 1000 | tr '\n' ' ')
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""

print_header "ADVANCED VERSION TESTS (2000 random values)"

echo "[3] 2000 random values (range -1000000..1000000)"
ARG=$(seq -1000000 1000000 | shuf -n 2000 | tr '\n' ' ')
start_time=$(date +%s%N)
valgrind_out="$($VALGRIND ./push_swap $ARG 2>&1)"
end_time=$(date +%s%N)
total_elapsed_ms=$(( (end_time - start_time) / 1000000 ))

ps_out="$(echo "$valgrind_out" | grep -v '^==')"
valgrind_msgs="$(echo "$valgrind_out" | grep '^==')"

echo "Valgrind diagnostic messages:"
echo "$valgrind_msgs"

checker_out="$(echo "$ps_out" | ./checker_linux $ARG)"
moves=$(echo "$ps_out" | wc -l)

echo "Checker output: $checker_out"
echo "Number of moves: $moves"
echo "Time: ${total_elapsed_ms} ms"
echo ""
