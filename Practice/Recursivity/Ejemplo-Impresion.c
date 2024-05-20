#include <stdio.h>

int impresionHola(int indice) {
    printf("Hola Diablo Número: %d\n", indice);
    if(indice <= 1) {
        return indice;
    }
    else {
        return impresionHola(indice - 1);
    }
}

int main() {
    int limite = 6;
    impresionHola(limite);

    return 0;
}