//
// Created by yavidor on 14/12/2025.
//

#include <stdbool.h>
#include <stdio.h>

#define PARTS 8
#define MAX_VALUE 50
#define MIN_VALUE (-1)
#define MAX_HP 100

/*
 * -------------------
 * | Algorithm Steps |
 * -------------------
 * (1) Get the values of the ships' parts
 *  (1.a) Validate the values
 * (2) Get the ships' hit marks
 *  (2.a) Turn the hit marks to booleans
 * (3) Check the ships Health
 * (4) Print the results
 */

// Function declarations

// Utils

// Fills an array with integer values
bool fillArray(int arr[], int size);

// Fill a bool array with the values of an int array
void intToBoolArr(const int intArr[], bool boolArr[], int size);

// Steps

// (1.a) Check that every value is in the range (-1,50)
bool validateParts(const int values[], int size);

// (3) Calculate the ship's health after the battle
int calculateHP(const int values[], const bool marks[], int size);

// Implementations

bool fillArray(int arr[], const int size) {
    int input = 0;
    int index = 0;
    while (index < size) {
        const int scanResult = scanf("%d", &input);
        if (scanResult != 1) {
            return false;
        }
        arr[index++] = input;
    }
    return true;
}

void intToBoolArr(const int intArr[], bool boolArr[], const int size) {
    int index = 0;
    while (index < size) {
        boolArr[index] = (bool)intArr[index];
        index++;
    }
}
bool validateParts(const int values[], const int size) {
    for (int i = 0; i < size; i++) {
        if (values[i] > MAX_VALUE || values[i] < MIN_VALUE) {
            return false;
        }
    }
    return true;
}

int calculateHP(const int values[], const bool marks[], const int size) {
    int healthPoints = MAX_HP;
    for (int i = 0; i < size; i++) {
        if (marks[i]) {
            healthPoints -= values[i];
            if (values[i] == -1) {
                return 0;
            }
        }
    }
    return healthPoints;
}

int main(void) {
    printf("Please enter ship's parts value:\n");
    int shipValues[PARTS] = {0};
    if (!(fillArray(shipValues, PARTS) && validateParts(shipValues, PARTS))) {
        printf("There was an error in input");
        return 1;
    }
    int firstShipMarksInts[PARTS] = {0};
    int secondShipMarksInts[PARTS] = {0};
    bool firstShipMarks[PARTS] = {0};
    bool secondShipMarks[PARTS] = {0};
    printf("Please enter first ship's hit marks:\n");
    if (!fillArray(firstShipMarksInts, PARTS)) {
        printf("There was an error in input");
        return 1;
    }
    printf("Please enter second ship's hit marks:\n");
    if (!fillArray(secondShipMarksInts, PARTS)) {
        printf("There was an error in input");
        return 1;
    }
    intToBoolArr(firstShipMarksInts, firstShipMarks, PARTS);
    intToBoolArr(secondShipMarksInts, secondShipMarks, PARTS);
    const int firstShipHP = calculateHP(shipValues, firstShipMarks, PARTS);
    const int secondShipHP = calculateHP(shipValues, secondShipMarks, PARTS);
    if (firstShipHP <= 0 && secondShipHP <= 0) {
        printf("Both ships have lost the battle!\n");
    } else if (firstShipHP > 0 && secondShipHP > 0) {
        printf("Both ships survived the battle!\n");
    } else {
        if (firstShipHP == 0) {
            printf("Ship #2 has won the battle!\n");
        } else {
            printf("Ship #1 has won the battle!\n");
        }
    }
    return 0;
}