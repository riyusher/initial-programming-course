#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

int maxSumArr(int arr[], int arraySize, int* startIndex, int* endIndex) {
    if(arraySize < 2) {
        printf("Error: The array must contain at least two elements.\n");
        exit(1);
    }

    int maxSum = INT_MIN;

    // Loop over all possible subarray sizes, starting from 2
    for(int subArraySize = 2; subArraySize <= arraySize; subArraySize++) {
        // Loop over all possible start indices for the current subarray size
        for(int i = 0; i <= arraySize - subArraySize; i++) {
            int sum = 0;
            // Calculate the sum of the subarray starting at index i and of size subArraySize
            for(int j = i; j < i + subArraySize; j++) {
                sum += arr[j];
            }
            // If the sum of the current subarray is greater than the maximum sum found so far,
            // update the maximum sum and the start and end indices of the subarray
            if(sum > maxSum) {
                maxSum = sum;
                *startIndex = i;
                *endIndex = i + subArraySize - 1;
            }
        }
    }
    
    return maxSum;
}

void printMaxSumSubarray(int arr[], int startIndex, int endIndex, int maxSum) {
    printf("The subarray with the maximum sum is: ");
    for(int i = startIndex; i <= endIndex; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\nWhich sums to: %d\n", maxSum);
}

int main() {
    int arr[] = {-2, -5, 1, -3, 4}; 
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    int startIndex, endIndex = 0; 

    int maxSum = maxSumArr(arr, arraySize, &startIndex, &endIndex);
    printMaxSumSubarray(arr, startIndex, endIndex, maxSum);
    
    return 0;
}