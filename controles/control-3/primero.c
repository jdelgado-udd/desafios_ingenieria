/*
Hay 8 salas en biblio, necesitamos analizar solicitudes.

Solicitud = nombre, cantidad y duracion. V

Restricciones (terminar en rechazo):
- Max 6 personas
- Max 3 horas

Se analizan 10 solicitudes:
- Registrar datos. V
- Determinar aprobación o rechazo.V
- Acumulador aprobadas.V
- Acumulador rechazos por categoría, y ambas.V
- Porcentaje aprobadas.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define CANTIDAD_SOLICITUDES 10
#define LONGITUD_STRING 20

#define REPROBADAS_PERSONAS 0
#define REPROBADAS_HORAS 1
#define REPROBADAS_AMBAS 2

int main(int argc, char** argv) {
    int aprobadas = 0;
    int reprobadas[] = {0, 0, 0};

    for (int i = 0; i < CANTIDAD_SOLICITUDES; i++) {
        char nombre[LONGITUD_STRING];
        int personas;
        float duracion;

        printf("Reserva #%d\n", i + 1);

        printf("Nombre: ");
        fgets(nombre, LONGITUD_STRING - 1, stdin);

        if (nombre[strlen(nombre) - 1] == '\n')
            nombre[strlen(nombre) - 1] = '\0';

        printf("Cantidad de integrantes: ");
        scanf(" %d", &personas);

        printf("Duración en horas: ");
        scanf(" %f", &duracion);

        getchar(); // Quitar trailing new-line.

        bool rep_personas = personas > 6 || personas < 1;
        bool rep_horas = duracion > 3 || duracion <= 0;

        if (!rep_horas && !rep_personas) {
            aprobadas += 1;
            printf(
                "Reserva N°%d para %s con %d integrantes con una duración de %f horas ha sido aprobada.\n",
                i + 1,
                nombre,
                personas,
                duracion
            );

            continue;
        }

        printf("Lamentablemente, tu reserva ha sido reprobada ya que:\n");

        if (rep_personas) {
            reprobadas[REPROBADAS_PERSONAS] += 1;
            printf("- Deben ser entre 1 y 6 integrantes.\n");
        }

        if (rep_horas) {
            reprobadas[REPROBADAS_HORAS] += 1;
            printf("- La duración debe de ser entre 0 y 3 horas.\n");
        }

        if (rep_personas && rep_horas) {
            reprobadas[REPROBADAS_PERSONAS] -= 1;
            reprobadas[REPROBADAS_HORAS] -= 1;
            reprobadas[REPROBADAS_AMBAS] += 1;
        }
    }

    if (aprobadas == CANTIDAD_SOLICITUDES) {
        printf("INFORME DE SALAS DE ESTUDIO\n 100%% DE APROBACIÓN\n");
        return 0;
    }

    printf(
        "INFORME DE SALAS DE ESTUDIO\n Aprobadas: %d (%f%%)\n Reprobadas: %d (%f%%)\n - Cantidad de integrantes: %d (%f%%)\n - Horas: %d (%f%%)\n - Ambas: %d (%f%%)\n",
        aprobadas,
        aprobadas * 100 / (float) CANTIDAD_SOLICITUDES,
        CANTIDAD_SOLICITUDES - aprobadas,
        (CANTIDAD_SOLICITUDES - aprobadas) * 100 / (float) CANTIDAD_SOLICITUDES,
        reprobadas[REPROBADAS_PERSONAS],
        reprobadas[REPROBADAS_PERSONAS] * 100 / (float) (CANTIDAD_SOLICITUDES - aprobadas),
        reprobadas[REPROBADAS_HORAS],
        reprobadas[REPROBADAS_HORAS] * 100 / (float) (CANTIDAD_SOLICITUDES - aprobadas),
        reprobadas[REPROBADAS_AMBAS],
        reprobadas[REPROBADAS_AMBAS] * 100 / (float) (CANTIDAD_SOLICITUDES - aprobadas)
    );

    return 0;
}
