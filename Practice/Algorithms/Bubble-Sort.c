#include <stdio.h>

int main() {
  int cadena[10] = {1, 5, 7, 4, 9, 10, 3, 8, 2, 6};
  int ordenado = 0; 

  while (!ordenado) {
    ordenado = 1; 
    for (int i = 0; i < 9; i++) {
      if (cadena[i] > cadena[i + 1]) {
        // Intercambiar elementos
        int aux = cadena[i];
        cadena[i] = cadena[i + 1];
        cadena[i + 1] = aux;
        ordenado = 0; 
      }
    }
  }

  // Imprimir el arreglo ordenado
  for (int i = 0; i < 10; i++) {
    printf("%d", cadena[i]);
  }

  return 0;
}
