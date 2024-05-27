#include <stdio.h>

// Función para realizar la búsqueda binaria de manera iterativa
int busquedaBinaria(int arr[], int n, int x) {
    int inicio = 0;
    int fin = n - 1;
    
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;  // Encuentra el índice medio

        // Verifica si el elemento en el medio es el que buscamos
        if (arr[medio] == x) {
            return medio;  // Retorna el índice si encuentra el elemento
        }

        // Si el elemento es mayor que el medio, entonces está en la mitad derecha
        if (arr[medio] < x) {
            inicio = medio + 1;
        }
        // Si el elemento es menor que el medio, entonces está en la mitad izquierda
        else {
            fin = medio - 1;
        }
    }

    return -1;  // Retorna -1 si el elemento no está presente en el array
}

int main() {
    int datos[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Array debe estar ordenado
    int tam = sizeof(datos) / sizeof(datos[0]);    // Tamaño del array. 'sizeof(datos)' tamaño total en bytes, 'sizeof(datos[0])' tamaño de un solo elemento en bytes.
    int objetivo = 7;  // Elemento a buscar

    int resultado = busquedaBinaria(datos, tam, objetivo);

    if (resultado != -1) {
        printf("Elemento encontrado en el índice %d\n", resultado);
    } else {
        printf("Elemento no encontrado\n");
    }

    return 0;
}