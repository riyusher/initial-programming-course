#include <stdio.h>

int peticionNumero() {
    int numero;
    printf("Digite el Número de la Tarjeta a Procesar");
    scanf("%d", &numero);
    return numero;
}

int identificarTipoTarjeta(int numero) {
    if(numero % 10000 == 0) {
        return 1;
    }
    else if(numero % 1000000 == 0) {
        return 2;
    }
    return 0;
}

int main() {
    int numeroTarjeta, tipoTarjeta = 0;

    numeroTarjeta = peticionNumero();
    tipoTarjeta = identificarTipoTarjeta(numeroTarjeta);

    if(tipoTarjeta>= 1) {
        switch(tipoTarjeta) {
        case 1:
            printf("La Tarjeta es Mastercard o Visa");
        break;
        case 2:
            printf("La Tarjeta es American Express");
        break;
        }
    }   
    else {
        printf("La Tarjeta no Corresponde a Ningún Tipo");
    }
    
    return 0;
}