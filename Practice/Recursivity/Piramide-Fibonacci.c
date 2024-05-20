#include <stdio.h>

int fibonacci(int numero) {
    if(numero <= 1) {
        return numero;
    }
    else {
        return fibonacci(numero - 1) + fibonacci(numero -2);
    }
}

int impresionPiramideFibonacci(int tamano) {
    // Definir ciclo que itere n cantidad de veces donde n es la cantidad de filas
    for(int i = 1; i <= tamano; i++) {
        /* Definir ciclo que itere n cantidad de veces donde n es la cantidad
        de columnas*/
        
        // Imprimir el número correspondiente de fibonacci en cada iteración
    }
}

int main() {

    return 0;
}