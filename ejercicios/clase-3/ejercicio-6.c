/*
    Un entrenador registra los goles anotados por 8 jugadores durante una temporada.
    Ingrese los goles de cada jugador en un arreglo.
    El programa debe mostrar:
    • Promedio de goles. *
    • Jugador con más goles. *
    • Cantidad de jugadores que anotaron más que el promedio. *
 */

#include <stdio.h>

int main(int argc, char** argv) {
    int goles[8];

    int mayor = -1;
    int total = 0;

    for (int i = 0; i < 8; i++) {
        printf("JUGADOR #%d\n", i + 1);
        printf("Goles: ");
        scanf(" %d", &goles[i]);

        total += goles[i];

        if (mayor == -1 || goles[i] > goles[mayor])
            mayor = i;
    }

    double prom = total / 8.0;
    int hprom = 0;

    for (int i = 0; i < 8; i++) {
        printf("[%d] %d", i + 1, goles[i]);

        if (goles[i] > prom) {
            printf(" (+P)");
            hprom++;
        }

        if (mayor == i)
            printf(" (MVP)");

        printf("\n");
    }

    printf("Total: %d, Promedio: %lf, +P: %d\n", total, prom, hprom);
    return 0;
}
