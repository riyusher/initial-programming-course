#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXSIZE 100

int main() {
    char anagrama1[MAXSIZE];
    char anagrama2[MAXSIZE];
    char conversion1[MAXSIZE];
    char conversion2[MAXSIZE];
    
    printf("\n\tIdentificador de anagramas\n\n");
    printf("Ingrese la primera palabra:\n");
    fgets(anagrama1, sizeof(anagrama1), stdin);

    // Convertir la cadena a minusculas y eliminar caracteres especiales y espacios
    int j = 0;
    for(int i = 0; anagrama1[i] != '\0'; i++) {
        if((anagrama1[i] >= 'a' && anagrama1[i] <= 'z') || (anagrama1[i] >= 'A' && anagrama1[i] <= 'Z')) {
            if(anagrama1[i] >= 'A' && anagrama1[i] <= 'Z') {
                anagrama1[i] += 32;
            }
        conversion1[j] = anagrama1[i];
        j++;
        }
    }

    printf("Digite la segunda palabra:\n");
    fgets(anagrama2, sizeof(anagrama2), stdin);

    j = 0;
    for(int i = 0; anagrama2[i] != '\0'; i++) {
        if((anagrama2[i] >= 'a' && anagrama2[i] <= 'z') || (anagrama2[i] >= 'A' && anagrama2[i] <= 'Z')) {
            if(anagrama2[i] >= 'A' && anagrama2[i] <= 'Z') {
                anagrama2[i] += 32;
            }
        conversion2[j] = anagrama2[i];
        j++;
        }
    }

    int frecuencia1[26]; 
    int frecuencia2[26]; 

    int largo1 = strlen(conversion1);
    int largo2 = strlen(conversion2);

    // Calcular la frecuencia de cada letra 
    for (int i = 0; i < largo1; i++)
        frecuencia1[conversion1[i] - 'a']++;

    for (int i = 0; i < largo2; i++)
        frecuencia2[conversion2[i] - 'a']++;

    // Comparar las frecuencias
    bool anagramas = true;
    for (int i = 0; i < 26; i++) {
        if (frecuencia1[i] != frecuencia2[i]) {
            anagramas = false;
            break;
        }
    }

    char validacion[25];
    if(anagramas == true) {
    strcpy(validacion, "son anagramas");
    }
    else {
    strcpy(validacion, "no son anagramas");
    }

    
    printf("Las palabras %s y %s %s\n", conversion1, conversion2, validacion);
    
    return 0;
}