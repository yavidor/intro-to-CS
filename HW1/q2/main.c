#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int input = 0;
    char suffix = 0; // Needed to check if input contains invalid characters
    int output = 0;
    int result = scanf("%d%c", &input, &suffix);

    // If additional characters was captured, it must be newlike
    if (result != 1 && suffix != '\n') {
        printf("Error in input!\n");
    } else {
        while (input != 0) {
            // Take out the last digit from the input, add it to the output
            output *= 10;
            output += input % 10;
            input /= 10;
        }
        printf("%d\n", output);
    }
}
