/* Dado un Array de números encontrar la suma máxima entre
los valores contenidos dentro del array*/
#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

bool maxSumArr(int arr[], int arrLen, int arrRes[],int* arrResLen, int* maxNeg) {
    bool flag = true;
    int iArrSum = 0;
    *arrResLen = 0;
    
    /* Ciclo que itera n cantidad de veces donde n es el tamaño
    del array*/
    for(int i = 0; i < arrLen; i++) {
        /* Si el valor es positivo guardarlo dentro de un
        array auxiliar para su impresion*/
        if(arr[i] > 0) {
            arrRes[iArrSum] = arr[i];
            iArrSum++;
            // Actualizar bandera indicando que se encontró un positivo
            if(flag == true) {
                flag = false;
            }
        }
        // Actualizar el valor del maximo negativo contenido
        if(arr[i] < 0 && arr[i] > *maxNeg) {
            *maxNeg = arr[i];
        }
        *arrResLen = iArrSum;
    }
    return flag;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; int tamArr = sizeof(arr) / sizeof(arr[0]);
    int arrSum[MAXSIZE] = {0}; int tamArrSum;
    int maxNeg = -10000;

    int negativos = maxSumArr(arr, tamArr, arrSum, &tamArrSum, &maxNeg);

    /* Condicional donde según se haya encontrado un positivo o no
    imprimir la respuesta*/
    if(negativos) { // Maximo Negativo
        printf("%d", maxNeg);
        return 0;
    }
    else { // Array de positivos
        for(int i = 0; i < tamArrSum; i++) {
            if(arrSum[i] != 0) {
                printf("%d", arrSum[i]);
            }
            if(i < tamArrSum - 1) {
                printf(", ");
            }
        }
        printf("\n");
        return 0;
    }
}