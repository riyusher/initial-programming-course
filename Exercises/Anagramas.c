#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 100
#define ABCSIZE 26

void ingresarCadena(char cadena[]) {
    fgets(cadena, MAXSIZE, stdin);
}

// Convertir la cadena a minusculas y eliminar caracteres especiales y espacios
void limpiarCadena(char cadena[], char cadenaLimpia[]) {
    int j = 0;
    for(int i = 0; cadena[i] != '\0'; i++) {
        if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')) {
            if(cadena[i] >= 'A' && cadena[i] <= 'Z') {
                cadena[i] += ('a' - 'A');
            }
        cadenaLimpia[j] = cadena[i];
        j++;
        }
    }
    cadenaLimpia[j] = '\0';
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void bubbleSort(char cadena[], int size) {
    for (int paso = 0; paso < size - 1; ++paso) {
        for (int i = 0; i < size - paso - 1; ++i) {
            if (cadena[i] > cadena[i + 1]) {
                char aux = cadena[i];
                cadena[i] = cadena[i + 1];
                cadena[i + 1] = aux;
            }
        }
    }
}

bool sonAnagramas(char cadena1[], char cadena2[]) {
    if(strlen(cadena1) != strlen(cadena2)) {
        return false;
    }
    
    bubbleSort(cadena1, strlen(cadena1));
    bubbleSort(cadena2, strlen(cadena2));
    
    for (int i = 0; i != '\0'; i++) {
        if (cadena1[i] != cadena2[i]) {
            return false;
        }
    }
    
    return true;
}


void imprimirResultado(char cadena1[], char cadena2[], bool resultado) {
    if (resultado) {
        printf("Las palabras %s y %s son anagramas.\n", cadena1, cadena2);
    } else {
        printf("Las palabras %s y %s no son anagramas.\n", cadena1, cadena2);
    }
}

int main() {
    char anagrama1[MAXSIZE];
    char anagrama2[MAXSIZE];
    char conversion1[MAXSIZE];
    char conversion2[MAXSIZE];
    
    printf("\n\tIdentificador de anagramas\n\n");
    
    printf("Ingrese la primera palabra:\n");
    ingresarCadena(anagrama1);
    limpiarCadena(anagrama1, conversion1);
    
    limpiarBuffer();
    
    printf("Ingrese la segunda palabra:\n");
    ingresarCadena(anagrama2);
    limpiarCadena(anagrama2, conversion2);
    
    bool validacion = sonAnagramas(conversion1, conversion2);
    imprimirResultado(conversion1, conversion2, validacion);
   
    return 0;
}