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

#define MIN_STEP_SIZE 1
#define MAX_STEP_SIZE 25

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
    int stepSize;
    printf("\nEnter the step you want for the cipher (Min %d, Max %d):\n", MIN_STEP_SIZE, MAX_STEP_SIZE);
    while(scanf("%d", &stepSize) != 1 || stepSize < MIN_STEP_SIZE || stepSize > MAX_STEP_SIZE) {
        printf("\nEnter a Valid Option\n");
        printf("Enter the step you want for the cipher (Min %d, Max %d):\n", MIN_STEP_SIZE, MAX_STEP_SIZE);
        while(getchar() != '\n');
    }
    
    while(getchar() != '\n');
    return stepSize;
}

char shiftCharacter(char character, int step, CipherOption option) {
    character += option == ENCRYPT ? step : -step;
    if(islower(character)) {
        if(option == ENCRYPT ? character > 'z' : character < 'a') {
            character += option == ENCRYPT ? -ABCSIZE : ABCSIZE;
        }
    }
    else {
        if(option == ENCRYPT ? character > 'Z' : character < 'A') {
            character += option == ENCRYPT ? -ABCSIZE : ABCSIZE;
        }
    }
    return character;
}

void cipher(char inputString[], int outputString[], int step, CipherOption option) {
    int i;
    for(i = 0; inputString[i] != '\0'; i++) {
        if(isalpha(inputString[i])) {
            outputString[i] = shiftCharacter(inputString[i], step, option);
        }
        else {
            outputString[i] = SPACE;
        }
    }
    outputString[i] = '\0';
}

void printCipherText(int cipherText[]) {
    for(int i = 0; cipherText[i] != '\0'; i++) {
        printf("%c", cipherText[i]);
    }
}

void printResult(int cipherText[], CipherOption option) {
    switch(option) {
        case ENCRYPT:
            printf("\nThe Encrypted text is:\n" GREEN);
        break;
        
        case DECRYPT:
            printf("\nThe Decrypted text is:\n" GREEN);
        break;
    }
    printCipherText(cipherText);
    printf(DEFAULT);
}

void readPlainText(char str[]) {
    printf("\nEnter the text to encrypt or decrypt (Maximum %d characters and should not contain special characters):\n", MAXSIZE);
    fgets(str, MAXSIZE, stdin);
    clearBuffer(str);
}

void processText() {
    char text[MAXSIZE];
    int textConversion[MAXSIZE];
    
    CipherOption option = displayCipherMenuAndGetChoice();
    int step = requestCipherStepSize();
    
    readPlainText(text);
    
    cipher(text, textConversion, step, option);
    printCipherAlphabet(step, option);
    printResult(textConversion, option);
}

int main() {
    processText();
    return 0;
}