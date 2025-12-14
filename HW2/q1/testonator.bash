#!/usr/bin/env bash

PROGRAM_PATH="${1}"
TESTS_PATH="${2}"


CLEAR='\033[0m'
RED='\033[31m'
GREEN='\033[32m'

jq -c '.tests[]' "$TESTS_PATH" | sed --expression='s/\n/\\n/g' |  while read -r line; do


    TEST_NAME=$(jq '.name' <<<"$line" | tr -d \")
    TEST_INPUT=$(jq '.input' <<<"$line" | tr -d \")
    TEST_OUTPUT=$(jq '.output' <<<"$line" | tr -d \")
    printf "%s" "$GREEN"
    echo ----------
    printf "%s" "$RED"
    echo "$TEST_NAME"
    echo  "$TEST_INPUT"
    echo   "$TEST_OUTPUT"
    printf "%s" "$CLEAR"
    PROGRAM_OUTPUT=$("$PROGRAM_PATH" <<< "$(echo -e "$TEST_INPUT")")

    echo "$PROGRAM_OUTPUT"

done
