/* Dado un array de enteros encontrar la suma máxima
de elementos continuos contenidos*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int maxSumArr(int arr[], int tamArr, int* iMinSubArr, int* iMaxSubArr) {
     // Indices que se remplazaran por los indices del subarray que cumpla con la condición
    int maxSum = -10000;

    // Condicional para saber si el tamaño del array es 1, > 1, o 0
    if(tamArr == 1) { // Caso donde el array solo contenga un dato
        printf("El Subarray con la suma máxima es: ");
        printf("%d", arr[0]);
        printf("\nPara el cual su suma da: %d\n", arr[0]);
        exit;
    }
    else if(tamArr > 1) {
        /*Ciclo mayor que se repite hasta que tamaño del subarray supere
        el tamaño del array a comparar*/
        for(int tamSubArr = 2; tamSubArr <= tamArr; tamSubArr++) {
            /* Ciclo medio que se repite hasta que indice maximo de 
            el subarray a comparar supere el tamaño del array a comparar*/
            for (int i = 0; i <= tamArr - tamSubArr; i++) {
                // Inicializamos la variable suma siempre en 0 cada ciclo;
                int sum = 0; 
                /* Ciclo que itera N cantidad de veces donde N es el
                tamaño actual del subarray a comparar (tamaño inicial
                sería 2 por la condición de elementos continuos) y ademas
                guarda el valor del indice que en cual se encuentra el subarray
                actual*/
                /* Ademas guarda el valor del indice actual y por ello no requiero
                otra variable que haga esto*/
                for (int j = i; j < i + tamSubArr; j++) {                                     
                /* A variable suma se le suma el elemento actual del indice del 
                subarray comparado actual*/
                    sum += arr[j];
                }
                /* Condicional que se activa cuando la suma del subarray actual
                es mayor a la maxima suma registrada*/
                if(sum > maxSum) {// Actualizamos la respuesta y valor de maxSum
                    maxSum = sum;
                    /* Actualizamos el valor del indice inicial y final del sub array 
                    que cumplió con la condiciónpara su impresión */
                    *iMinSubArr = i;
                    *iMaxSubArr = i + tamSubArr - 1;
                }
            }
            /*Al romperse el ciclo de subarrays aumentar el tamaño de el subarray a comparar
            y el indice inicial se actualizaría a 0 por que está inicializado en el for*/
        }
        return maxSum;
    }
}

int main() {
    int arr[] = {-2, -5, 1, -3, 4}; int ArrLen = sizeof(arr) / sizeof(arr[0]);
    int imSA, iMSA = 0; // Indice Menor y Mayor del SubArray

    int result = maxSumArr(arr, ArrLen, &imSA, &iMSA);
    // Imprimir Respuesta
    if (ArrLen == 1) {
        return 0;
    }
    else {
        printf("El Subarray con la suma máxima es: ");
    for(int i = imSA; i <= iMSA; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\nPara el cual su suma da: %d\n", result);
    }
    
    return 0;
}
