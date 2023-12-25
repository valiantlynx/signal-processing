#include <stdio.h>
#include <ctype.h>
#include <string.h>

void string_upper(char word[]) {
    int i = 0;
    while (word[i]){
        word[i] = toupper(word[i]);
        i++;
    }
}

void string_lower(char word[]) {
    int i = 0;
    while (word[i]){
        word[i] = tolower(word[i]);
        i++;
    }
}

void half_slit(char word[], char word1[], char word2[]) {
    int len = strlen(word);
    int len1 = len/2;
    int len2 = len -len1;
    strncpy(word1, word, len1);
    word1[len1] = '\0';
    strncpy(word2, word+len1, len2);
    word2[len2] = '\0';
}


int main() {
    char word[20];
    char word1[20];
    char word2[20];

    scanf("%s", word);
    half_slit(word, word1, word2);
    string_upper(word);
    printf("The word in uppercase is '%s'\n", word);
    string_lower(word);
    printf("The word in lowercase is '%s'\n", word);
    printf("The word split in two is '%s - %s'", word1, word2);
}