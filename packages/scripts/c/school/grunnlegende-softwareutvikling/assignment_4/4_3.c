#include "stdio.h"
#include "string.h"

int main() {
    char word1[20];
    char word2[20];

    scanf("%s", word1);
    scanf("%s", word2);

    if(strcmp(word1, word2) == 0){
        printf("The words are equal\n");
    } else {
        printf("The words are not equal\n");
    }

    if(strstr(word2, word1) != NULL){
        printf("Word 1 is a substring of word 2");
    } else if(strstr(word1, word2) != NULL){
        printf("Word 2 is a substring of word 1");
    } else {
        printf("No substrings found");
    }

    return 0;
}