/*
 Contexto Un cine posee una sala de 2 filas y 3 columnas. Cada asiento puede estar disponible u ocupado.
 Enunciado Use una matriz de enteros donde 0 indique disponible y 1 ocupado. Permita reservar un asiento, mostrar
 sala y contar asientos disponibles.
 Entrada Opción de menú, fila y columna.
 Salida esperada Reserva validada, mapa de sala y disponibilidad.
 Restricciones Valide rangos y evite reservar asientos ocupados
 */

#include <stdio.h>

#define FILAS 5
#define COLUMNAS 10

#define DISPONIBLE 0
#define OCUPADO 1

int main(int argc, char** argv) {
    /* Definir sala y cada asiento como disponible */
    int sala[FILAS][COLUMNAS]; // Definir matriz

    for (int fila = 0; fila < FILAS; fila++) // Loop por cada fila
        for (int columna = 0; columna < COLUMNAS; columna++) // Loop por cada columna
            sala[fila][columna] = DISPONIBLE; // Colocar fila y columna en sala como disponible.

    /* Menu */
    int salir = 0; // Definir variable para cortar loop

    while (salir != 1) { // Loop hasta que salir sea 1
        printf(
            "1 - Reservar asiento.\n"
            "2 - Mostrar sala.\n"
            "3 - Contar asientos disponibles.\n"
            "0 - Salir.\n"
            "> "
        ); // Mostrar opciones de menu

        int opcion; // Definir opción dentro del código
        scanf(" %d", &opcion); // Recibir número de opción

        while (getchar() != '\n'); // Prevenir que input inapropiada corrompa el programa

        switch (opcion) { // Ejecutar código de acuerdo a la opción
            case 0:
                salir = 1; // Setear salir en 1, para detener el loop

                break; // Saltar código restante
            case 1:
                /* Solicitar fila */
                printf("¿Qué fila desea reservar? ");
                int fila;
                scanf(" %d", &fila);

                /* Solicitar columna */
                printf("¿Qué columna desea reservar? ");
                int columna;
                scanf(" %d", &columna);

                /* Chequear bounds */
                if (fila < 1 || fila > FILAS || columna < 1 || columna > COLUMNAS) {
                    printf("Hay %d filas y %d columnas.\n", FILAS, COLUMNAS);
                    break;
                }

                sala[fila - 1][columna - 1] = OCUPADO; // Setear asiento como ocupado

                printf("¡Asiento reservado!\n"); // Notificar al usuario
                break; // Saltar código restante
            case 2:
                /* Mostrar todas las lineas de la sala */
                for (int fila = 0; fila < FILAS; fila++) { // Loop por cada fila
                    printf("[%d]", fila + 1); // Indicar número de fila

                    for (int columna = 0; columna < COLUMNAS; columna++) { // Loop por cada columna en la fila
                        if (sala[fila][columna] == DISPONIBLE) // Revisar si el lugar está disponible
                            printf(" _");
                        else
                            printf(" X");
                    }

                    printf("\n"); // Saltar linea para el siguiente loop
                }

                break; // Saltar código restante
            case 3: ;
                int contador = 0; // Crear un contador

                for (int fila = 0; fila < FILAS; fila++) // Loop por cada fila
                    for (int columna = 0; columna < COLUMNAS; columna++) // Loop por cada columna
                        if (sala[fila][columna] == DISPONIBLE) // Chequear si el asiento está disponible
                            contador++; // Agregar al contador

                printf("Hay %d asientos disponibles.\n", contador); // Mostrar el resultado al usuario
                break; // Saltar código restante
            default:
                printf("Opción no reconocida, intentalo de nuevo.\n");
        }
    }

    printf("¡Disfruta tu película!\n");

    return 0;
}

/*

[ [0, 0, 0],
  [0, 0, 0] ]

 */
