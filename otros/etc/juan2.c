#include <stdio.h>

int dia = 0;
int cant = 0;
int venta_baja = 0;
int venta_normal = 0;
int venta_alta = 0;
int dias[7];
int suma = 0;

int main() {
  for (int semana = 0; semana < 7; semana++) {
    printf("cuantos juegos vendio esta semana?: ");
    scanf("%d", &cant);
    suma = suma + cant;

    if (cant < 20) {
      venta_baja = venta_baja + 1;
    } else if (20 <= cant && cant < 50) {
      venta_normal = venta_normal + 1;
    } else {
      venta_alta = venta_alta + 1;
    }

    dias[semana] = cant;
  }

  printf("Suma: %d\n", suma);

  for (int x = 0; x < 7; x++) {
    printf("el dia %d vendio: %d\n", x + 1, dias[x]);
  }

  return 0;
}
