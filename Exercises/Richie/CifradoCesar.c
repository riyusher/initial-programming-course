#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXSIZE 100
#define ABCSIZE 26
#define SPACE 32 

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define DEFAULT "\033[0m"



void fillAlphabet(char arr[]) {
    int letter = 'A';
    for(int i = 0; i < ABCSIZE; i++) {
        arr[i] = letter++;
    }
}

typedef enum {
    ENCRYPT,
    DECRYPT
} CipherOption;

CipherOption displayCipherMenuAndGetChoice() {
    int option;
    do {
        printf("\n\tCaesar Cipher\n\n");
        printf("1: Encrypt\t2: Decrypt\n");
        printf("Please enter your choice (1 or 2): ");
        scanf("%d", &option);

        // Clear the input buffer
        while(getchar() != '\n');

        if(option < 1 || option > 2) {
            printf("\nEnter a Valid Option\n");
        }
    } while(option < 1 || option > 2);

    return option == 1 ? ENCRYPT : DECRYPT;
}

int requestCipherStepSize() {
    int n;
    printf("\nEnter the step you want for the cipher (Min 1, Max 25):\n");
    scanf("%d", &n);
    
    while(n < 1 || n > 25) {
        printf("\nEnter a Valid Option\n");
        printf("Enter the step you want for the cipher (Min 1, Max 25):\n");
        scanf("%d", &n);
    }
    // Clear the input buffer
        while(getchar() != '\n');
    return n;
}

void clearBuffer(char array[]) {
    int length = strlen(array);
    if (length > 0 && array[length - 1] == '\n') {
        array[length - 1] = '\0';
    }
}

void readCharArray(char str[]) {
    fgets(str, MAXSIZE, stdin);
    clearBuffer(str);
}

void cipher(char inputString[], int outputString[], int step, CipherOption option) {
    int i;
    for(i = 0; inputString[i] != '\0'; i++) {
        outputString[i] = inputString[i];
        if(isalpha(outputString[i])) {
            outputString[i] += option == ENCRYPT ? step : -step;
            if(islower(outputString[i])) {
                if(option == ENCRYPT ? outputString[i] > 'z' : outputString[i] < 'a') {
                    outputString[i] += option == ENCRYPT ? -ABCSIZE : ABCSIZE;
                }
            }
            else {
                if(option == ENCRYPT ? outputString[i] > 'Z' : outputString[i] < 'A') {
                    outputString[i] += option == ENCRYPT ? -ABCSIZE : ABCSIZE;
                }
            }
        }
        else {
            outputString[i] = SPACE;
        }
    }
    outputString[i] = '\0';
}

void printCipherAlphabet(int n, CipherOption option) {
    char str[ABCSIZE]; 
    fillAlphabet(str);
    for(int i = 0; i < ABCSIZE; i++) {
        printf("[%c]", str[i]);
    }
    printf("\nWith step of %d\n", n);
    for(int i = 0; i < ABCSIZE; i++) {
        str[i] += option == ENCRYPT ? n : -n;
        if(option == ENCRYPT ? str[i] > 'Z' : str[i] < 'A') {
            str[i] += option == ENCRYPT ? -ABCSIZE : ABCSIZE;
        }
    }
    for(int i = 0; i < ABCSIZE; i++) {
        printf("[%c]", str[i]);
    }
}

void printArr(int arr[]) {
    for(int i = 0; arr[i] != '\0'; i++) {
        printf("%c", arr[i]);
    }
}

void printResult(int arr[], CipherOption option) {
    switch(option) {
        case ENCRYPT:
            printf("\nThe Encrypted text is:\n" GREEN);
        break;
        
        case DECRYPT:
            printf("\nThe Decrypted text is:\n" GREEN);
        break;
    }
    printArr(arr);
}

int main() {
    char text[MAXSIZE];
    int textConversion[MAXSIZE];
    
    CipherOption option = displayCipherMenuAndGetChoice();
    int step = requestCipherStepSize();
    
    printf("\nEnter the text to process (Maximum %d characters and should not contain special characters):\n", MAXSIZE);
    readCharArray(text);
    
    cipher(text, textConversion, step, option);
    printCipherAlphabet(step, option);
    printResult(textConversion, option);
    
    printf(DEFAULT);
    return 0;
}