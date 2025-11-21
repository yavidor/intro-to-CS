#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int input = 0;
    char after = 0;
    int result = scanf("%d%c", &input, &after);

    if (result == 1) {
        // "YOU FCKED UP"
        printf("! result I guess\n");
    }
    printf("input: %d\nafter: %d\n", input, after);
    bool isPositive = 0;
    if (input > 0) {
        isPositive = true;
    } else {
        isPositive = false;
    }
    printf("%d\n", isPositive);
    // while (input != 0) {
    //     printf("%d", isPositive);
    // }
}
