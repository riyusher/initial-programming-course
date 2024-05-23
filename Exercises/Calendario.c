#include <stdio.h>
#include <stdbool.h>

void limpiarBuffer() {
    while (getchar() != '\n' && getchar() != EOF);
}

// Función que lea los datos ingresados
void peticionDatos(int ano, int mes) {
    printf("Digite el Año (1990 a 2024)\n");
    scanf("%d", &ano);
    limpiarBuffer();
    while(ano <1990 && ano > 2024) {
        printf("Digite un Año Valido (1990 - 2024)");
        scanf("%d", &ano);
        limpiarBuffer();
    }

    printf("Digita el Mes (Número)\n");
    scanf("%d", &mes);
    limpiarBuffer();
    while(mes < 1 && mes > 12) {
        printf("Digite un Mes Valido (1 - 12)");
        scanf("%d", &mes);
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
            return false;
        }
    } else {
        return false;
    }
}

/* Remplazar un array de dias y un array de números correspondiente a los días
según lo validado*/
void impresionDatos() {
    for(int i = 0; i <= 7; i++) {
        printf("%c\t", dia[i])
    }
    printf("\n");
    for(int i = 0; i <= 7; i++) {
        printf("%c\t", dia[i])
    }
    printf("\n");
    
    
}

int main() {
    int ano, mes;
    printf("\n\tCalendario\n\n");
    // Pedir Año y Mes a imprimir
    peticionDatos(ano, mes);
    impresionDatos();
    // Función que lea los datos ingresados y los procese
    if(esBisiesto(ano));
}