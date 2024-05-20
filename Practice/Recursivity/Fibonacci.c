#include <stdio.h>

int fibonacci(int numero) {
    if(numero <= 1) {
        return numero;
    }
    else {
        return fibonacci(numero - 1) + fibonacci(numero -2);
    }
}
int main() {
    int numero = 13;

    printf("El número es %d", fibonacci(numero));

    return 0;
}