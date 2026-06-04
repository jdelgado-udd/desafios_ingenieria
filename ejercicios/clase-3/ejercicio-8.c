/*
    Una empresa realizó una encuesta a 20 clientes.
    Cada cliente entrega una nota entre 1 y 7.
    Al finalizar el programa debe mostrar:
    • Promedio de satisfacción.
    • Cantidad de clientes satisfechos (nota ≥ 5).
    • Cantidad de clientes insatisfechos (nota < 5).
 */

#include <stdio.h>

int main(int argc, char** argv) {
    int notas[20];

    int mayor = -1;
    int menor = -1;

    int satisfechos = 0;
    int insatisfechos = 0;

    for (int i = 0; i < 20; i++) {
        printf("Nota #%d: ", i + 1);
        scanf(" %d", &notas[i]);

        if (notas[i] < 1 || notas[i] > 7) {
            i--;
            continue;
        }

        if (notas[i] >= 5)
            satisfechos++;
        else
            insatisfechos++;

        if (mayor == -1 || notas[i] > notas[mayor])
            mayor = i;

        if (menor == -1 || notas[i] < notas[menor])
            menor = i;
    }

    printf("Min: %d, Max: %d, Satisfechos: %d, Insatisfechos: %d\n", menor, mayor, satisfechos, insatisfechos);
    return 0;
}
