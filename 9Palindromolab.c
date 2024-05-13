#include <stdio.h>
#include <string.h>

#define MAXN 10100
int fibo(){

    int fibo[17];
    fibo[0] = fibo[1] = 0;
    for(int i = 2; i < 17; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}
int isPalindrome(char *word) {
    int tamanho = strlen(word);
    int d = 1;
    if (!(tamanho%2)) {
        for (int i = (tamanho/2)-1, j = (tamanho/2); (i >= 0) && (j <= tamanho-1); i--, j++) {
            if (word[i] != word[j]) {
                d = 0;
                break;
            }
        }
    } else {
        for (int i = (tamanho/2), j = (tamanho/2); (i >= 0) && (j <= tamanho-1); i--, j++) {
            if (word[i] != word[j]) {
                d = 0;
                break;
            }
        }
    }
    return d;
}

int main(){
    int n; scanf("%d ", &n);
    char string[MAXN];
    while(n--){
        fgets(string, MAXN, stdin);
        string[strcspn(string, "\n")] = '\0';
        string[strcspn(string, "\r")] = '\0';
        if(isPalindrome(string)){
            printf("%s eh um palindromo\n", string);
        } else {   
            printf("%s nao eh um palindromo\n", string);
        }
    }   
}