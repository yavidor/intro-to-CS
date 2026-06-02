#!/usr/bin/env bash

PROGRAM_PATH="${1}"
TESTS_PATH="${2}"

echo "${PROGRAM_PATH}"

echo $([ -z "$PROGRAM_PATH" ])

echo "HELLO"

if [ -z "${PROGRAM_PATH}" ] || [ -z "${TESTS_PATH}" ]; then
    echo "Error: incorrect parameters"
    echo "Usage: $0 <PROGRAM_PATH> <TESTS_PATH>"
    echo "If you're using CLion, <PROGRAM_PATH> will be the executable inside cmake-build-debug"
    echo "TESTS_PATH is the path to student_tests.json"
    exit 1

# COLORS, I love ANSI
CLEAR='\033[0m'
RED='\033[31m'
GREEN='\033[32m'

# Perhaps there's a better way, but IDK
jq -c '.tests[]' "$TESTS_PATH" | sed --expression='s/\n/\\n/g' | while read -r line; do

    # I think it's supposed to be easier, I'm so rusty with jq
    TEST_NAME=$(jq '.name' <<<"$line" | tr -d \")
    TEST_INPUT=$(jq '.input' <<<"$line" | tr -d \")
    TEST_OUTPUT=$(jq '.output' <<<"$line" | tr -d \")
    echo ----------

    # This too, I don't like it but it works (:
    PROGRAM_OUTPUT=$("$PROGRAM_PATH" <<< "$(echo -en "$TEST_INPUT")")
    if [[ "$PROGRAM_OUTPUT" !=  "$TEST_OUTPUT" ]]
    then
        echo -en "$RED"
        echo "TEST FAILED"
        echo "On test: $TEST_NAME"
        echo "Input: $TEST_INPUT" 
        echo "Expected: $TEST_OUTPUT"
        echo "Received: $PROGRAM_OUTPUT"
        echo -en "$CLEAR"
    else
        echo -en "$GREEN"
        echo "TEST SUCCESS: $TEST_NAME"
        echo -en "$CLEAR"
    fi

done
