#include <stdio.h>
#include <stdbool.h>

#define TAMANOSEMANA 7
#define TAMANOMAXMES 42

void limpiarBuffer() {
    while (getchar() != '\n' && getchar() != EOF);
}

// Función que lea los datos ingresados
void peticionDatos(int ano, int mes) {
    printf("Digite el Año (1990 a 2024)\n");
    scanf("%d", ano);
    limpiarBuffer();
    while (ano < 1990 || ano > 2024) {
        printf("Digite un Año Valido (1990 - 2024)\n");
        scanf("%d", ano);
        limpiarBuffer();
    }

    printf("Digita el Mes (1 - 12)\n");
    scanf("%d", mes);
    limpiarBuffer();
    while (mes < 1 || mes > 12) {
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

// Remplazar valores para su procesamiento
void remplazoDatos(int mes, int ano) {
    int diasMes, diasAno;
    // Definir días del año
    if(esBisiesto(ano)) {
        diasAno = 366;
    }
    else {
        diasAno = 365;
    }
    //Switch para definir los días del mes según el indicado
    switch(mes) {
        case 1:// Enero
            diasMes = 31;
        break;
        case 2:// Febrero
            if(esBisiesto(ano)) {
                diasMes = 29;
            }
            else {
                diasMes = 28;
            }
        break;
        case 3: // Marzo 
            diasMes = 31;
        break;
        case 4: // Abril
            diasMes = 30;
        break;
        case 5: // Mayo
            diasMes = 31;
        break;
        case 6: // Junio
            diasMes = 30;
        break;
        case 7: // Julio
            diasMes = 31;
        break;
        case 8: // Agosto
            diasMes = 31;
        break;
        case 9: // Septiembre
            diasMes = 30;
        break;
        case 10: // Octubre
            diasMes = 31;
        break;
        case 11: // Noviembre
            diasMes = 30;
        break;
        case 12: // Diciembre
            diasMes = 31;
        break;
    }
}
// Imprimir los días de la semana junto a los números correspondientes al mes
void impresionDatos(int ano, int mes, char dia[], int numeros[]) {
    //Imprimir Año
    printf("\t\t%d\t", ano);
    //Imprimir Mes
    switch(mes) {
        case 1: printf("Enero\t\n");
        break;
        case 2: printf("Febrero\t\n");
        break;
        case 3: printf("Marzo\t\n");
        break;
        case 4: printf("Abril\t\n");
        break;
        case 5: printf("Mayo\t\n");
        break;
        case 6: printf("Junio\t\n");
        break;
        case 7: printf("Julio\t\n");
        break;
        case 8: printf("Agosto\t\n");
        break;
        case 9: printf("Septiembre\t\n");
        break;
        case 10: printf("Octubre\t\n");
        break;
        case 11: printf("Noviembre\t\n");
        break;
        case 12: printf("Diciembre\t\n");
        break;
    }
    // Impresión de los días de la semana
    for (int i = 0; i < TAMANOSEMANA; i++) {
        printf("%c\t", dia[i]);
    }
    printf("\n");
    // Impresión de los números del mes
    for(int j = 0; j <= TAMANOMAXMES; j++) {
        if(j % 7 == 0) {
            printf("\n");
        }
        if(numeros[j] == 0) {
                printf("\t");
                continue;
            }
        printf("%d\t", numeros[j]);
    }
}

int main() {
    int ano = 1990, mes = 5;
    char diaSemana[TAMANOSEMANA] = {'L', 'M', 'M', 'J', 'V', 'S', 'D'}; // Días de la semana
    int numeroDia[TAMANOMAXMES] = {0};
    for(int i = 0; i <= 31; i++) {
        numeroDia[i] = i;
    }

    printf("\n\t\tCalendario\n\n");
    impresionDatos(ano, mes, diaSemana, numeroDia);

    return 0;
}
