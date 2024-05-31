#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
#define imprimirTarjetaInvalida printf("\nLa Tarjeta Ingresada no es Valida\n");

int peticionTarjeta(char cadena[]) {
    printf("Digite el Número de Tarjeta a Procesar\n");
    fgets(cadena, MAXSIZE, stdin);
    if(strlen(cadena) < 13) {
        return 0;
    }
    return 1;
}

void limpiarCadena(char cadena[], char cadenaLimpia[]) {
    int j = 0;
    for(int i = 0; cadena[i] != '\0'; i++) {
        if(cadena[i] >= '0' && cadena[i] <= '9') {
            cadenaLimpia[j] = cadena[i];        
            j++;
        }
    }
    cadenaLimpia[j] = '\0';
}

void identificarTarjeta(char cadena[], int largoCadena) {
    switch(largoCadena) {
        //
        case(13):
            if(cadena[0] == '4') {// Inicial 4
                printf("\nLa Tarjeta Ingresada es Visa\n");
                return;
            }
        break;
        case(16):
            if(cadena[0] == '4') {// Inicial 4
                printf("\nLa Tarjeta Ingresada es Visa\n");
                return;
            }
            else if((cadena[0] == '5') && (cadena[1] >= '1' && cadena[1] <= '5')) {// Inicial 51 a 55
                printf("\nLa Tarjeta Ingresada es Mastercard\n");
                return;
            }
            else if((cadena[0] == '2') &&(cadena[1] >= '2' && cadena[1] <= '7')&&(cadena[2] == '2')&&(cadena[3] >= '0' && cadena[3] <= '1')) {// Inicial 2221 a 2720
                printf("\nLa Tarjeta Ingresada es Mastercard\n");
                return;
            }
        break;
        //
        case(15):
            if((cadena[0] == '3') && (cadena[1] >= '4' && cadena[1] <= '7')) {// Inicial 34 a 37
                printf("\n La Tarjeta Ingresada es American Express");
                return;
            }
        break;
    }
    imprimirTarjetaInvalida
}

int main() {
    char numeroTarjeta[MAXSIZE] = {0};
    char numeroTarjetaLimpio[MAXSIZE] = {0};
    int tamanoMinimo;

    printf("\n\tIdentificador de Tarjetas\n\n");
    tamanoMinimo = peticionTarjeta(numeroTarjeta);
    if(tamanoMinimo == 0) {
        imprimirTarjetaInvalida
        return 0;
    }
    limpiarCadena(numeroTarjeta, numeroTarjetaLimpio);
    
    int largoTarjeta = strlen(numeroTarjetaLimpio);
    
    identificarTarjeta(numeroTarjetaLimpio, largoTarjeta);
    

    return 0;
}