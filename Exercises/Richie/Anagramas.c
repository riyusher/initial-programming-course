#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define DEFECT "\033[0m"

#define MAXSIZE 100
#define ABCSIZE 26

void clearBuffer(char array[]) {
    int length = strlen(array);
    if (length > 0 && array[length - 1] == '\n') {
        array[length - 1] = '\0';
    }
}

void readCharArray(char string[]) {
    fgets(string, MAXSIZE, stdin);
    clearBuffer(string);
}

void cleanAndLowercaseString(char string[]) {
    int targetIndex = 0;
    for(int sourceIndex = 0; string[sourceIndex] != '\0'; sourceIndex++) {
        if(isalpha(string[sourceIndex])) {
            string[targetIndex] = tolower(string[sourceIndex]);
            targetIndex++;
        }
    }
    string[targetIndex] = '\0';
}

void bubbleSort(char string[]) {
    int size = strlen(string);
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (string[i] > string[i + 1]) {
                char aux = string[i];
                string[i] = string[i + 1];
                string[i + 1] = aux;
            }
        }
    }
}

bool areAnagrams(char string1[], char string2[]) {
    char copy1[MAXSIZE], copy2[MAXSIZE];

    cleanAndLowercaseString(string1);
    cleanAndLowercaseString(string2);

    if(strlen(string1) != strlen(string2)) {
        return false;
    }

    strcpy(copy1, string1);
    strcpy(copy2, string2);
    
    bubbleSort(copy1);
    bubbleSort(copy2);
    
    for (int i = 0; i != '\0'; i++) {
        if (copy1[i] != copy2[i]) {
            return false;
        }
    }
    
    return true;
}

void printResult(char string1[], char string2[], bool result) {
    if (result) {
        printf("The words " GREEN "%s " DEFECT "and " GREEN "%s " DEFECT "are anagrams.\n", string1, string2);
    } else {
        printf("The words " RED "%s " DEFECT "and " RED "%s " DEFECT "are not anagrams.\n", string1, string2);
    }
}

int main() {
    char anagram1[MAXSIZE];
    char anagram2[MAXSIZE];
    
    printf("\n\tAnagram Identifier\n\n");
    
    printf("Enter the first word:\n");
    readCharArray(anagram1);
    
    printf("Enter the second word:\n");
    readCharArray(anagram2);
    
    printResult(anagram1, anagram2, areAnagrams(anagram1, anagram2));
   
    return 0;
}