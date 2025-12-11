#include <stdio.h>

#define MAX_DIGITS 10
#define MIN_DIGITS 1

int main(void) {
    printf("Please enter condition numbers:\n");
    int numberLength = 0;
    int maxDifferentDigits = 0;
    int maxOfSameDigit = 0;
    scanf("%d %d %d", &numberLength, &maxDifferentDigits, &maxOfSameDigit);
    if (MIN_DIGITS > maxDifferentDigits || maxDifferentDigits > MAX_DIGITS) {
        printf("Number of unique digits must be between 1 to 10\n");
        return 1;
    }
    printf("Please enter test number:\n");
    char digit = 0;
    // Ten different counters, one for each digit
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int count7 = 0;
    int count8 = 0;
    int count9 = 0;

    // To count the length of the number
    int digitCount = -1;

    int uniqueDigits = 0;
    while (scanf("%c", &digit) != EOF) {
        digitCount++;
        switch (digit) {
        case '0':
            if (count0 == 0) {
                uniqueDigits++;
            }
            count0++;
            break;
        case '1':
            if (count1 == 0) {
                uniqueDigits++;
            }
            count1++;
            break;
        case '2':
            if (count2 == 0) {
                uniqueDigits++;
            }
            count2++;
            break;
        case '3':
            if (count3 == 0) {
                uniqueDigits++;
            }
            count3++;
            break;
        case '4':
            if (count4 == 0) {
                uniqueDigits++;
            }
            count4++;
            break;
        case '5':
            if (count5 == 0) {
                uniqueDigits++;
            }
            count5++;
            break;
        case '6':
            if (count6 == 0) {
                uniqueDigits++;
            }
            count6++;
            break;
        case '7':
            if (count7 == 0) {
                uniqueDigits++;
            }
            count7++;
            break;
        case '8':
            if (count8 == 0) {
                uniqueDigits++;
            }
            count8++;
            break;
        case '9':
            if (count9 == 0) {
                uniqueDigits++;
            }
            count9++;
            break;
        }
    }
    if (uniqueDigits > maxDifferentDigits || count0 > maxOfSameDigit ||
        count1 > maxOfSameDigit || count2 > maxOfSameDigit ||
        count3 > maxOfSameDigit || count4 > maxOfSameDigit ||
        count5 > maxOfSameDigit || count6 > maxOfSameDigit ||
        count7 > maxOfSameDigit || count8 > maxOfSameDigit ||
        count9 > maxOfSameDigit || digitCount > numberLength) {
        printf("The number given does not meet all the conditions\n");
    } else {
        printf("The number given meets all the conditions\n");
    }
}
