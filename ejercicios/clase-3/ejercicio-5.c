/*
    Solicite la cantidad disponible de 10 videojuegos distintos. Muestre stock total, productos con
    menos de 5 unidades y el producto con mayor stock.
 */

#include <stdio.h>
#include <string.h>

#define STR_LEN 20

int main(int argc, char** argv) {
    char videojuegos[10][STR_LEN];
    int stock[10];

    int mayor = -1;
    int total = 0;

    for (int i = 0; i < 10; i++) {
        char nombre[STR_LEN];

        printf("VIDEOJUEGO #%d\n", i + 1);
        printf("Nombre: ");
        fgets(nombre, STR_LEN - 1, stdin);
        printf("Stock: ");
        scanf(" %d", &stock[i]);

        if (nombre[strlen(nombre) - 1] == '\n')
            nombre[strlen(nombre) - 1] = '\0';

        strcpy(videojuegos[i], nombre);

        getchar();

        total += stock[i];

        if (mayor == -1 || stock[i] > stock[mayor])
            mayor = i;
    }

    for (int i = 0; i < 10; i++) {
        printf("[%d] %s (%d)", i + 1, videojuegos[i], stock[i]);

        if (mayor == i)
            printf(" (MAYOR STOCK)");

        printf("\n");
    }

    printf("Total: %d\n", total);
    return 0;
}
