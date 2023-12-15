#include "stdio.h"
#include "string.h"

int main(){
    char word[20];
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzæøå";
    scanf("%s", word);
    for (int i = 0; i < strlen(alphabet); ++i) {
        int occurance = 0;
        for (int j = 0; j < strlen(word); ++j) {
            if(word[j]==alphabet[i]){
                occurance++;
            }
        }
        if(occurance>0){
            printf("'%c' : %i\n",alphabet[i], occurance);
        }
    }
    return 0;
}