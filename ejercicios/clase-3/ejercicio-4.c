/*
    Una veterinaria necesita almacenar las edades de 5 mascotas que asistirán a una campaña de
    vacunación.
    Solicite la edad de cada mascota y almacénela en un arreglo. Muestre todas las edades, la mayor
    y la menor.
 */

#include <stdio.h>

int main(int argc, char** argv) {
    int edades[5];
    int mayor = -1;
    int menor = -1;

    for (int i = 0; i < 5; i++) {
        printf("Edad #%d: ", i + 1);
        scanf(" %d", &edades[i]);

        if (mayor == -1 || edades[i] > edades[mayor])
            mayor = i;

        if (menor == -1 || edades[i] < edades[menor])
            menor = i;
    }

    for (int i = 0; i < 5; i++) {
        printf("[%d] %d", i, edades[i]);

        if (mayor == i)
            printf(" (MAYOR)");

        if (menor == i)
            printf(" (MENOR)");

        printf("\n");
    }

    return 0;
}
