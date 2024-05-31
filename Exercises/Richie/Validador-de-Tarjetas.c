#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 30

void limpiarBufferEntradaArr(char array[]) {
    int len = strlen(array);
    if (len > 0 && array[len - 1] == '\n') {
        array[len - 1] = '\0';
    }
}

void limpiarCadenaChar(char cadena[]) {
    char cadenaLimpia[MAXLEN];
    int j = 0;
    for(int i = 0; cadena[i] != '\0'; i++) {
        if(cadena[i] >= '0' && cadena[i] <= '9') {
            cadenaLimpia[j] = cadena[i];        
            j++;
        }
    }
    cadenaLimpia[j] = '\0';
    strcpy(cadena, cadenaLimpia);
}

// Leer Array
void leerArrayChar(char peticion[]) {
    fgets(peticion, MAXLEN, stdin);
    limpiarBufferEntradaArr(peticion);
    return;
}

// Validar Tarjeta
bool validarTarjeta(char cadena[], int cadenaLen) {
    int suma = 0; // Variable entera para manejar en número
    bool ciclo = false; // booleano para manejar cada segundo número

    for(int i = cadenaLen - 1; i >= 0; i--) {
        // Convertir caracter en número para manipularlo
        int tempNum = cadena[i] - '0';
        // Agarrar cada segundo dígito

        if (ciclo) {
            tempNum *= 2;
            if(tempNum > 9) {
                tempNum -= 9;
            }
        }
        suma += tempNum;
        ciclo = !ciclo;
    }
    // Aplicar la regla del modulo 10 para saber si la suma de la tarjeta es valida
    return (suma % 10 == 0);
}

int main() {
    char tarjeta[MAXLEN] = {0};
    printf("\n\tValidador de Tarjetas\n\n");
    printf("Digite el Número de la Tarjeta\n");

    leerArrayChar(tarjeta);
    limpiarCadenaChar(tarjeta);
    printf("\n");

    int largoTarjeta = strlen(tarjeta);

    if(validarTarjeta(tarjeta, largoTarjeta)) {
        printf("\nLa tarjeta es Valida\n");
    }
    else {
        printf("\nLa tarjeta es Invalida\n");
    }

    return 0;
}