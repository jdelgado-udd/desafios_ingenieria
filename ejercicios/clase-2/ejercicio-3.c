#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    printf("Ingrese un número: ");
    int numero;
    scanf(" %d", &numero);

    int rango = 0;

    while (rango < 1) {
        printf("Ingrese x en [0, x]: ");
        scanf(" %d", &rango);
    }

    printf("Tabla:\n");

    for (int i = 0; i <= rango; i++)
        printf(" - [%d] %d\n", i, i * numero);
}
