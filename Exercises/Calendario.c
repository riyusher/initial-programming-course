#include <stdio.h>
#include <stdbool.h>

#define tamanoSemana 7

void limpiarBuffer() {
    while (getchar() != '\n' && getchar() != EOF);
}

// Función que lea los datos ingresados
void peticionDatos(int *ano, int *mes) {
    printf("Digite el Año (1990 a 2024)\n");
    scanf("%d", ano);
    limpiarBuffer();
    while (*ano < 1990 || *ano > 2024) {
        printf("Digite un Año Valido (1990 - 2024)\n");
        scanf("%d", ano);
        limpiarBuffer();
    }

    printf("Digita el Mes (1 - 12)\n");
    scanf("%d", mes);
    limpiarBuffer();
    while (*mes < 1 || *mes > 12) {
        printf("Digite un Mes Valido (1 - 12)\n");
        scanf("%d", mes);
        limpiarBuffer();
    }
}

// Reconocer si el año es bisiesto o no
bool esBisiesto(int ano) {
    if (ano % 4 == 0) {
        if (ano % 100 == 0) {
            if (ano % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;  
        }
    } else {
        return false;
    }
}

/* Remplazar un array de dias y un array de números correspondiente a los días
según lo validado*/

// Imprimir los días de la semana junto a los números correspondientes al mes
void impresionDatos(char dia[], int numeros[][tamanoSemana]) {
    // Impresión de los días de la semana
    for (int i = 0; i < tamanoSemana; i++) {
        printf("%c\t", dia[i]);
    }
    printf("\n");
    // Impresión de los números del mes
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < tamanoSemana; j++) {
            printf("%d\t", numeros[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int ano, mes;
    char dia[tamanoSemana] = {'L', 'M', 'M', 'J', 'V', 'S', 'D'}; // Días de la semana
    int numeroDia[6][tamanoSemana] = {
        {1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26, 27, 28},
        {29, 30, 31, 0, 0, 0, 0}, // Los ceros indican días vacíos
        {0, 0, 0, 0, 0, 0, 0} // Dejar vacía esta fila si el mes no tiene 31 días
    };

    printf("\n\tCalendario\n\n");
    impresionDatos(dia, numeroDia);

    return 0;
}
