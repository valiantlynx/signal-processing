#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void sort(int nums[]){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (nums[j] > nums[j+1]){
                int tempNum = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tempNum;
            }
        }
    }
}

void string_reverse(char word[]){
    char temp;
    for (int i = 0; i < strlen(word)/2; ++i) {
        // sort in reverse according to index
        temp = word[i];
        word[i] = word[strlen(word)-i-1];
        word[strlen(word)-i-1] = temp;
    }
}

bool is_palindrome(char word[]){
    bool is_palindrome = 1;
    for (int i = 0; i < strlen(word)/2; ++i) {
        if (word[i] != word[strlen(word)-i-1]){
            is_palindrome = 0;
            break;
        }
    }
    return is_palindrome;
}


int main() {
    char word[20];

    scanf("%s", word);
    printf("The word contains %llu letters\n", strlen(word));
    string_reverse(word);
    if (is_palindrome(word)){
        printf("The word is a palindrome\n");
    } else {
        printf("The word is not a palindrome\n");
    }
    printf("The word reversed is '%s'\n", word);

    return 0;
}