//Write aprogram to print a histogram of the frequencies of different characters in its input.
#include <stdio.h>

#define NUM_CHARS 128 // Número total de caracteres ASCII

int main() {
    int c;
    int char_frequencies[NUM_CHARS] = {0}; // Array para almacenar las frecuencias de los caracteres

    // Leer la entrada y contar las frecuencias de los caracteres
    while ((c = getchar()) != EOF) {
        if (c < NUM_CHARS && c >= 0) { // Asegurarse de que el valor de c está dentro del rango del array
            ++char_frequencies[c];
        }
    }

    // Imprimir el histograma
    printf("Histograma de frecuencias de caracteres:\\n");
    for (int i = 0; i < NUM_CHARS; ++i) {
        if (char_frequencies[i] > 0) {
            printf("%c | ", i); // Imprimir el caracter
            for (int j = 0; j < char_frequencies[i]; ++j) {
                printf("#"); // Imprimir un '#' por cada aparición del caracter
            }
            printf("\\n");
        }
    }

    return 0;
}