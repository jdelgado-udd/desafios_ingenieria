/*
    Un administrador de sistemas registra la temperatura de un servidor durante 12 horas.
    Ingrese las 12 temperaturas registradas.
    El programa debe indicar:
    • Temperatura máxima.
    • Temperatura mínima.
    • Cantidad de veces que la temperatura superó los 70°C.
 */

#include <stdio.h>

int main(int argc, char** argv) {
    int temperaturas[12];
    int mayor = -1;
    int menor = -1;
    int altas = 0;

    for (int i = 0; i < 12; i++) {
        printf("Temperaturas #%d: ", i + 1);
        scanf(" %d", &temperaturas[i]);

        if (temperaturas[i] > 70)
            altas++;

        if (mayor == -1 || temperaturas[i] > temperaturas[mayor])
            mayor = i;

        if (menor == -1 || temperaturas[i] < temperaturas[menor])
            menor = i;
    }

    printf("Min: %d, Max: %d, Altas: %d\n", menor, mayor, altas);
    return 0;
}
