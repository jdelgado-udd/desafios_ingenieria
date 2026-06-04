/*
    Un entrenador desea registrar la cantidad de flexiones realizadas por un deportista durante 7
    días.
    Solicite al usuario la cantidad de flexiones realizadas cada día de la semana. Al finalizar muestre
    el total y el promedio diario.
 */

#include <stdio.h>

int main(int argc, char** argv) {
    printf("FLEXIONES\n");
    int sum = 0;

    for (int i = 0; i < 7; i++) {
        int flex;

        printf("Día #%d: ", i + 1);
        scanf(" %d", &flex);

        sum += flex;
    }

    printf("Sum: %d, Prom: %lf\n", sum, sum / 7.0);
    return 0;
}
