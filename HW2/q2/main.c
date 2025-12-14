//
// Created by yavidor on 13/12/2025.
//

#include <stdbool.h>
#include <stdio.h>

#define PARTS 8
#define MAX_VALUE 50
#define MIN_VALUE 0
#define SPECIAL_VALUE (-1)
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
bool validateInput(const int values[]);

// (3) Calculate the ship's health after the battle
int calculateHP(const int values[], const bool marks[], int size);

bool fillArray(int arr[], const int size) {
    int input = 0;
    int index = 0;
    while (index < size) {
        scanf("%d", &input);
        arr[index++] = input;
    }
    return false;
}

void intToBoolArr(const int intArr[], bool boolArr[], const int size) {
    int index = 0;
    while (index < size) {
        boolArr[index] = (bool)intArr[index];
        index++;
    }
}

int calculateHP(const int values[], const bool marks[], const int size) {
    int healthPoints = MAX_HP;
    for (int i = 0; i < size; i++) {
        if (marks[i] == false) {
            healthPoints -= values[i];
        } else if (values[i] == -1) {
            return 0;
        }
    }
    return healthPoints;
}

int main(void) {
    printf("Please enter ship's parts value:\n");
    int ShipValues[PARTS] = {0};
    fillArray(ShipValues, PARTS);

    int firstShipMarksInts[PARTS] = {0};
    int secondShipMarksInts[PARTS] = {0};
    bool firstShipMarks[PARTS] = {0};
    bool secondShipMarks[PARTS] = {0};
    printf("Please enter first ship's hit marks:\n");
    fillArray(firstShipMarksInts, PARTS);
    printf("Please enter second ship's hit marks:\n");
    fillArray(secondShipMarksInts, PARTS);
    intToBoolArr(firstShipMarksInts, firstShipMarks, PARTS);
    intToBoolArr(secondShipMarksInts, secondShipMarks, PARTS);
    const int firstShipHP = calculateHP(ShipValues, firstShipMarks, PARTS);
    const int secondShipHP = calculateHP(ShipValues, secondShipMarks, PARTS);
    if (firstShipHP == 0 && secondShipHP == 0) {
        printf("Both ships have lost the battle!\n");
    } else if (firstShipHP != 0 && secondShipHP != 0) {
        printf("Both ships survived the battle!\n");
    } else {
        if (firstShipHP == 0) {
            printf("Ship 2 has won the battle!\n");
        } else {
            printf("Ship 1 has won the battle!\n");
        }
    }
    return 0;
}