/*Write aprogram to print a histogram of the lengths of words
in its input. it is easy to draw the histogram with the bars horizontal; 
a vertical orientation is more challenging.*/
#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LENGTH 20 // Longitud máxima de una palabra en el histograma

int main() {
    int c, state, length;
    int word_lengths[MAX_LENGTH + 1]; // El índice representa la longitud de la palabra, el valor representa la cantidad de palabras de esa longitud
    int i;

    state = OUT;
    length = 0;

    // Inicializar el array word_lengths
    for (i = 0; i <= MAX_LENGTH; ++i) {
        word_lengths[i] = 0;
    }

    // Leer la entrada y contar las longitudes de las palabras
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\\n' || c == '\\t') {
            if (state == IN) {
                if (length <= MAX_LENGTH) {
                    ++word_lengths[length];
                } else {
                    ++word_lengths[MAX_LENGTH]; // Contar palabras con longitud mayor a MAX_LENGTH
                }
            }
            state = OUT;
            length = 0;
        } else {
            state = IN;
            ++length;
        }
    }

    // Imprimir el histograma
    printf("Histograma de longitudes de palabras:\\n");
    for (i = 1; i <= MAX_LENGTH; ++i) {
        printf("%2d | ", i);
        for (int j = 0; j < word_lengths[i]; ++j) {
            printf("#");
        }
        printf("\\n");
    }
    if (word_lengths[MAX_LENGTH] > 0) {
        printf(">20| ");
        for (int j = 0; j < word_lengths[MAX_LENGTH]; ++j) {
            printf("#");
        }
        printf("\\n");
    }

    return 0;
}