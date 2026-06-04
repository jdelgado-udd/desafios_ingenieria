/*
Criterios de venta:
- Bajo: <20
- Normal: [20, 50]
- Alto: >50

Almacenar:
- Ventas diarias en arreglo. V
- Mayor V
- Menor V
- Días por categoría de criterio. V

Informe:
- Ventas por día. V
- Total de venta. V
- Si promedio > 40 "SEMANA EXITOSA DE VENTAS". V
- De lo contratio "SE REQUIEREN NUEVAS ESTRATEGIAS COMERCIALES". V
*/

#include <stdio.h>

#define VENTAS_BAJO 0
#define VENTAS_NORMAL 1
#define VENTAS_ALTO 2
char *nombres_criterios[] = {"Bajo", "Normal", "Alto"};

#define DIAS_SEMANA 7
char *nombres_dias[] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};

int main(int argc, char** argv) {
    int total_ventas = 0;
    int ventas_diarias[DIAS_SEMANA];
    int criterio_diarias[DIAS_SEMANA];

    int mayor = -1;
    int menor = -1;

    for (int i = 0; i < DIAS_SEMANA; i++) {
        printf("Videojuegos vendidos durante el %s: ", nombres_dias[i]);
        scanf(" %d", &ventas_diarias[i]);

        if (ventas_diarias[i] < 0) {
            printf("Cantidad inválida.\n");
            i--;

            continue;
        }

        total_ventas += ventas_diarias[i];

        if (ventas_diarias[i] < 20)
            criterio_diarias[i] = VENTAS_BAJO;
        else if (ventas_diarias[i] <= 50)
            criterio_diarias[i] = VENTAS_NORMAL;
        else
            criterio_diarias[i] = VENTAS_ALTO;

        if (mayor == -1 || ventas_diarias[mayor] < ventas_diarias[i])
            mayor = i;

        if (menor == -1 || ventas_diarias[menor] > ventas_diarias[i])
            menor = i;
    }

    // INFORME

    printf("INFORME DE VENTAS SEMANALES\n");

    for (int i = 0; i < DIAS_SEMANA; i++) {
        printf(
            "[%d] %s: %d (%s)",
            i + 1,
            nombres_dias[i],
            ventas_diarias[i],
            nombres_criterios[criterio_diarias[i]]
        );

        if (mayor == i)
            printf(" (MAYOR)");

        if (menor == i)
            printf(" (MENOR)");

        printf("\n");
    }

    float promedio = total_ventas / (float) DIAS_SEMANA;

    printf("TOTAL DE VENTAS: %d, PROMEDIO: %f\n", total_ventas, promedio);

    if (promedio > 40)
        printf("SEMANA EXITOSA DE VENTAS\n");
    else
        printf("SE REQUIEREN NUEVAS ESTRATEGIAS COMERCIALES\n");
}
