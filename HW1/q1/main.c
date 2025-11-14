#include <stdio.h>

#define DAYS_IN_A_WEEK 7
#define LOWEST_POSSIBLE_AVERAGE 15

int main(void) {
    double temperature = -1;
    scanf("%lf", &temperature); // There is at least one input
    int week = 1;

    // When there's only one entry, it's both the maximum and the miminum
    double maxTemp = temperature;
    double minTemp = temperature;

    // Sum and count needed to calculate average
    double weekSum = temperature;
    double overallSum = temperature;
    int dayCount = 1;
    while (scanf("%lf", &temperature) != EOF) {
        dayCount++;
        if (temperature > maxTemp) {
            maxTemp = temperature;
        }
        if (temperature < minTemp) {
            minTemp = temperature;
        }
        weekSum += temperature;
        overallSum += temperature;
        if (dayCount % DAYS_IN_A_WEEK == 0) { // End of the week
            double weekAverageTemp = weekSum / DAYS_IN_A_WEEK;
            printf("Week %d average: %.2f\n", week, weekAverageTemp);
            week++;
            weekSum = 0;
        }
    }
    printf("Max temp: %.2f\n", maxTemp);
    printf("Min temp: %.2f\n", minTemp);
    double overallAverage = overallSum / dayCount;
    if (overallAverage >= LOWEST_POSSIBLE_AVERAGE) {
        printf("Average temp: %.2f\n", overallAverage);
    } else {
        printf("Error in input!\n");
    }
    return 0;
}
