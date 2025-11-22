#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int input = 0;
    char suffix = 0;
    int output = 0;
    scanf("%d%c", &input, &suffix);

    if (suffix != '\n') {
        printf("Error in input!\n");
    } else {
        while (input != 0) {
            output *= 10;
            output += input % 10;
            input /= 10;
        }
        printf("%d\n", output);
    }
}
