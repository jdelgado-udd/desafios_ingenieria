#include <stdio.h>

int cant = 0;
int temp = 0;
int rechazado = 0;
int aprobado = 0;
int estudiantes[10][2];

int main() {
  for (int i = 0; i < 10; i++) {
      printf("\ncuantos quieren usar la sala?: ");
      scanf("%d", &cant);
      printf("\ncuanto tiempo necesita la sala?: ");
      scanf("%d", &temp);
      if (cant > 6) {
        rechazado = rechazado + 1;
        printf("\nsolicitud rechazada");
      } else if (temp > 8) {
        rechazado = rechazado + 1;
        printf("\nsolicitud rechazada");
      } else {
        aprobado = aprobado + 1;
        printf("\nsolicitud aprobada");
      }

      estudiantes[i][0] = temp;
      estudiantes[i][1] = cant;
  }

  printf("hay %d solicitudes aprobadas\n", aprobado);
  printf("hay %d solicitudes rechazadas", rechazado);
  return 0;
}
