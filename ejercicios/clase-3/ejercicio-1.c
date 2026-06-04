/*
 Un club recreativo permite el ingreso gratuito a los niños menores de 12 años. Las personas
 entre 12 y 59 años deben pagar entrada normal, mientras que los adultos mayores (60 años o
 más) reciben un descuento especial.
 Desarrolle un programa en C que solicite la edad de una persona y determine la categoría de
 acceso que le corresponde.
 */

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    int edad = -1;

    while (edad < 0) {
        printf("Ingrese su edad: ");
        scanf("%d", &edad);
    }

    bool menor = edad < 12;
    bool mayor = edad >= 60;

    if (menor) {
        printf("Clasificación: MENOR (GRATUITO)\n");
        return 0;
    }

    if (mayor) {
        printf("Clasificación: MAYOR (DESCUENTO)\n");
        return 0;
    }

    printf("Clasificación: NORMAL\n");
    return 0;
}
