/*
    Una empresa de transporte desea estimar el combustible utilizado durante un viaje.
    Solicite al usuario la cantidad de kilómetros recorridos y calcule el combustible consumido
    considerando que el vehículo consume 12 kilómetros por litro.
 */

#include <stdio.h>

int main(int argc, char** argv) {
    double km = -1;

    while (km < 0) {
        printf("Km recorridos: ");
        scanf("%lf", &km);
    }

    printf("Litros consumidos: %lf\n", km / 12);
    return 0;
}
