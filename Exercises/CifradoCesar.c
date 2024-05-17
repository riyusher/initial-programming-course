#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
#define ABCSIZE 26
#define ESPACIO 32 

#define ROJO "\033[0;31m"
#define VERDE "\033[0;32m"
#define DEFECTO "\033[0m"

void rellenarAbcdario(char str[]) {
    int letra = 'A';
    for(int i = 0; i < ABCSIZE; i++) {
        str[i] = letra++;
    }
}

int menuOpciones() {
    int n;
    //Menú de 2 opciones
    printf("\n\tCifrado Cesar\n\n");
    printf("1: Cifrar\t2: Descifrar\n");
    scanf("%d", &n);
    
    while(n < 1 || n > 2) {
        printf("\nDigite una Opción Valida\n");
        printf("1: Cifrar\t2: Descifrar\n");
        scanf("%d", &n);
    }
    return n;
}

int peticionPaso() {
    int n;
    //Ingresar Paso
    printf("\nDigite el paso que desea para el cifrado (Min 1, Max 25):\n");
    scanf("%d", &n);
    
    while(n < 1 || n > 25) {
        printf("\nDigite una Opción Valida\n");
        printf("Digite el paso que desea para el cifrado (Min 1, Max 25):\n");
        scanf("%d", &n);
    }
    return n;
}

void limpiarBuffer() {
    while (getchar() != '\n' && getchar() != EOF);//Limpiar el salto de linea de la entrada anterior
}

void peticionTexto(char str[]) {
    //Ingresar Texto a Procesar
    printf("\nDigite el texto a procesar (Maximo %d caracteres y no debe contener caracteres especiales):\n", MAXSIZE);
    fgets(str, MAXSIZE, stdin);
    
    str[strcspn(str, "\n")] = 0;
}

void cifrar(char str1[], int str2[], int n) {
    for(int i = 0; str1[i] != '\0'; i++) {
            str2[i] = str1[i];
            if(str2[i] >= 'a' && str2[i] <= 'z') {//Identificar si el caracter es una letra minuscula
                str2[i] += n;
                if(str2[i] > 'z') {
                    str2[i] -= ABCSIZE;
                }
            }
            else if(str2[i] >= 'A' && str2[i] <= 'Z') {//Identificar si el caracter es una letra mayuscula
                str2[i] += n;
                if(str2[i] > 'Z') {
                    str2[i] -= ABCSIZE;
                }
            }
            else {
                str2[i] = ESPACIO;//Manda a la burguer todo lo que no sea letra y lo convierte en ' '
            }
        }
    }

void descifrar(char str1[], int str2[], int n) {
    for(int i = 0; str1[i] != '\0'; i++) {
            str2[i] = str1[i];
            if(str2[i] >= 'a' && str2[i] <= 'z') {//Identificar si el caracter es una letra minuscula
                str2[i] -= n;
                if(str2[i] < 'a') {
                    str2[i] += ABCSIZE;
                }
            }
            else if(str2[i] >= 'A' && str2[i] <= 'Z') {//Identificar si el caracter es una letra mayuscula
                str2[i] -= n;
                if(str2[i] < 'A') {
                    str2[i] += ABCSIZE;
                }
            }
            else {
                str2[i] = ESPACIO;//Manda a la burguer todo lo que no sea letra y lo convierte en ' '
            }
        }
    }
    
void impresionAbcdarioCifrado(char str[], int n) {
    for(int i = 0; i < 10; i++) {//Imprime cada letra del abcdario de la primera a la decima entre []
            printf("[%c]", str[i]);
        }
        printf("\nCon paso de %d\n", n);//Le aumenta el valor ascii segun el paso al abcdario
        for(int i = 0; i < 10; i++) {
            str[i] += n;
            if (str[i] > 'Z') {
                str[i] -= ABCSIZE;/*Comprueba que no supere el rango y de hacerlo le resta el total del abcdario para 
                conseguir su equivalente en el retorno del ciclo*/
            }
        }
        for(int i = 0; i < 10; i++) {//Imprime el abcdario con el paso modificado
            printf("[%c]", str[i]);
        }
    }
    
void impresionAbcdarioDescifrado(char str[], int n) {
    for(int i = 0; i < 10; i++) {//Imprime cada letra del abcdario de la primera a la decima entre []
            printf("[%c]", str[i]);
        }
        printf("\nCon paso de %d\n", n);//Le aumenta el valor ascii segun el paso al abcdario
        for(int i = 0; i < 10; i++) {
            str[i] -= n;
            if (str[i] < 'A') {
                str[i] += ABCSIZE;/*Comprueba que no supere el rango y de hacerlo le resta el total del abcdario para 
                conseguir su equivalente en el retorno del ciclo*/
            }
        }
        for(int i = 0; i < 10; i++) {//Imprime el abcdario con el paso modificado
            printf("[%c]", str[i]);
        }
    }
    
void impresionResultado(char opcion[], char str[],  int conversion[]) {
    printf("\nEl %s de:\n" ROJO "%s" DEFECTO "\nEs:\n" VERDE, opcion, str);
    //Imprimir Cifrado o Descifrado
    for(int i = 0; conversion[i] != '\0'; i++) {
        printf("%c", conversion[i]);
    }
}

int main() {
    char abcdario[ABCSIZE];
    char texto[MAXSIZE];
    int conversionTexto[MAXSIZE];
    char resultado[MAXSIZE];
    
    rellenarAbcdario(abcdario);
    
    int opcion = menuOpciones();
    int paso = peticionPaso();
    
    limpiarBuffer();
    
    peticionTexto(texto);
    
    switch(opcion) {//Switch para cifrar o descifrar
        case 1:
            cifrar(texto, conversionTexto, paso);
            impresionAbcdarioCifrado(abcdario, paso);
            strcpy(resultado, "cifrado");
            impresionResultado(resultado, texto, conversionTexto);
        break;
        
        case 2:
            descifrar(texto, conversionTexto, paso);
            impresionAbcdarioDescifrado(abcdario, paso);
            strcpy(resultado, "descifrado");
            impresionResultado(resultado, texto, conversionTexto);
        break;
    }
    
    printf(DEFECTO);
    return 0;
}