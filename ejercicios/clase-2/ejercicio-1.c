#include <stdio.h>

#define NUMBERS 10

int main(int argc, char** argv) {
    int sum = 0;
    int high = 0;
    int low = 0;

    for (int index = 0; index < NUMBERS; index++) {
        int scan;
        printf("> ");
        scanf(" %d", &scan);

        sum += scan;

        if (index == 0) {
            high = scan;
            low = scan;
            continue;
        }

        if (high < scan)
            high = scan;

        if (scan < low)
            low = scan;
    }

    double prom = sum / (NUMBERS * 1.0);

    printf(
        "Sum: %d\nProm: %f\nHigh: %d\nLow: %d\n",
        sum,
        prom,
        high,
        low
    );
}
