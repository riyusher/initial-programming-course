#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 30

// Clears the input buffer
void clearInputBuffer(char array[]) {
    int length = strlen(array);
    if (length > 0 && array[length - 1] == '\n') {
        array[length - 1] = '\0';
    }
}

// Cleans the char string by removing non-numeric characters
void cleanCharString(char string[]) {
    int writeIndex = 0;
    for(int readIndex = 0; string[readIndex] != '\0'; readIndex++) {
        if(isdigit(string[readIndex])) {
            string[writeIndex] = string[readIndex];
            writeIndex++;
        }
    }
    string[writeIndex] = '\0';
}

// Reads a char array from the user
void readCharArray(char request[]) {
    fgets(request, MAXLEN, stdin);
    clearInputBuffer(request);
}

// Validates the card number using the Luhn algorithm
bool validateCard(char string[]) {
    int stringLen = strlen(string);
    int sum = 0; 
    bool flag = false; 

    for(int i = stringLen - 1; i >= 0; i--) {
        int tempNum = string[i] - '0';
        
        // Double every second digit and subtract 9 if the result is greater than 9
        if (flag) {
            tempNum *= 2;
            if(tempNum > 9) {
                tempNum -= 9;
            }
        }
        sum += tempNum;
        flag = !flag;
    }
    // The card number is valid if the sum is a multiple of 10
    return (sum % 10 == 0);
}

int main() {
    char cardNumber[MAXLEN] = {0};
    printf("\n\tCard Validator\n\n");

    printf("Enter the Card Number\n");
    readCharArray(cardNumber);
    cleanCharString(cardNumber);

    if(validateCard(cardNumber)) {
        printf("The card is Valid\n");
    }
    else {
        printf("The card is Invalid\n");
    }

    return 0;
}