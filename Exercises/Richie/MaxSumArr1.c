/* Dado un Array de números encontrar la suma máxima entre
los valores contenidos dentro del array*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAXSIZE 100

// Updates arrRes with positive numbers from arr and sets arrResLen to the number of positive numbers
void findPositiveNumbersAndUpdateResult(int arr[], int arrLen, int arrRes[], int* arrResLen) {
    int iArrSum = 0;
    for(int i = 0; i < arrLen; i++) {
        if(arr[i] > 0) {
            arrRes[iArrSum] = arr[i];
            iArrSum++;
        }
    }
    *arrResLen = iArrSum;
}

// Finds the maximum negative number in arr and sets maxNeg to this value
void findMaxNegativeNumber(int arr[], int arrLen, int* maxNeg) {
    for(int i = 0; i < arrLen; i++) {
        if(arr[i] < 0 && arr[i] > *maxNeg) {
            *maxNeg = arr[i];
        }
    }
}

// Processes arr by finding positive numbers and the maximum negative number
// Returns true if arr contains only negative numbers, false otherwise
bool processArrayAndCheckForNegatives(int arr[], int arrLen, int arrRes[],int* arrResLen, int* maxNeg) {
    bool containsOnlyNegatives = true;
    findPositiveNumbersAndUpdateResult(arr, arrLen, arrRes, arrResLen);
    findMaxNegativeNumber(arr, arrLen, maxNeg);
    
    if(*arrResLen > 0) {
        containsOnlyNegatives = false;
    }
    
    return containsOnlyNegatives;
}

// Prints the elements of arr
void printArray(int arr[], int arrLen) {
    for(int i = 0; i < arrLen; i++) {
        if(arr[i] != 0) {
            printf("%d", arr[i]);
        }
        if(i < arrLen - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; 
    int tamArr = sizeof(arr) / sizeof(arr[0]);
    int arrSum[MAXSIZE] = {0}; 
    int tamArrSum = 0;
    int maxNeg = INT_MIN;

    bool containsOnlyNegatives = processArrayAndCheckForNegatives(arr, tamArr, arrSum, &tamArrSum, &maxNeg);

    if(containsOnlyNegatives) { // Maximo Negativo
        printf("%d", maxNeg);
    }
    else { // Array de positivos
        printArray(arrSum, tamArrSum);
    }
    return 0;
}