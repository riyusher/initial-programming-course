#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 100
#define printInvalidCardMessage printf("\nThe entered card is not valid\n");

void readCharArray(char cardNumber[]) {
    fgets(cardNumber, MAXSIZE, stdin);
}

bool isCardNumberValid(char cardNumber[]) {
    if(strlen(cardNumber) < 13) {
        return false;
    }
    return true;
}

void cleanCardNumber(char cardNumber[]) {
    int writeIndex = 0;
    for(int readIndex = 0; cardNumber[readIndex] != '\0'; readIndex++) {
        if(isdigit(cardNumber[readIndex])) {
            cardNumber[writeIndex] = cardNumber[readIndex];
            writeIndex++;
        }
    }
    cardNumber[writeIndex] = '\0';
}

typedef enum {
    VISA,
    MASTERCARD,
    AMERICAN_EXPRESS,
    INVALID
} CardType;

bool startsWithRange(const char *str, int start, int end, int numChars) {
    char prefixStr[MAXSIZE] = {0};
    strncpy(prefixStr, str, numChars);
    int prefix = atoi(prefixStr);
    return prefix >= start && prefix <= end;
}

bool startsWith(const char *str, const char *prefix) {
    while(*prefix) {
        if(*prefix++ != *str++)
            return false;
    }
    return true;
}

CardType identifyCardType(char cardNumber[]) {
    int cardLength = strlen(cardNumber);

    switch(cardLength) {
        case 13:
            if(startsWith(cardNumber, "4")) {
                return VISA;
            }
            break;
        case 16:
            if(startsWith(cardNumber, "4")) {
                return VISA;
            }
            else if(startsWithRange(cardNumber, 51, 55, 2)) {
                return MASTERCARD;
            }
            else if(startsWithRange(cardNumber, 2221, 2227, 4)) {
                return MASTERCARD;
            }
            break;
        case 15:
            if(startsWithRange(cardNumber, 34, 37, 2)) {
                return AMERICAN_EXPRESS;
            }
            break;
    }
    return INVALID;
}

void printResult(CardType cardType) {
    switch(cardType) {
        case VISA:
            printf("The card is a VISA card\n");
            break;
        case MASTERCARD:
            printf("The card is a MASTERCARD card\n");
            break;
        case AMERICAN_EXPRESS:
            printf("The card is an AMERICAN EXPRESS card\n");
            break;
        case INVALID:
            printInvalidCardMessage
            break;
    }
}

int main() {
    char cardNumber[MAXSIZE] = {0};

    printf("\n\tCard Identifier\n\n");
    printf("Enter the card number to process\n");
    readCharArray(cardNumber);
    if (!isCardNumberValid(cardNumber)) {
        printInvalidCardMessage
        return 0;
    }
    cleanCardNumber(cardNumber);
    printResult(identifyCardType(cardNumber));
    
    return 0;
}