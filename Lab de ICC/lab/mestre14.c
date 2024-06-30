#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *palavra = (char *) malloc(200 * sizeof(char));
    scanf(" %s", palavra);
    palavra = realloc(palavra, (strlen(palavra)+1) * sizeof(char));
    char *arquivo = (char *) malloc(200 * sizeof(char));
    scanf(" %s", arquivo);
    arquivo = realloc(arquivo, (strlen(arquivo)+1) * sizeof(char));
    FILE *arq = fopen(arquivo, "rb");
    
    if (arq == NULL) {
        printf("Não deu para abrir.\n");
        return 0;
    }
    fseek(arq, 0, SEEK_END);
    size_t tmn = ftell(arq);
    fseek(arq, 0, SEEK_SET);

    char *buffer = (char *) malloc(tmn * sizeof(char));
    fread(buffer, tmn, 1, arq);
    fclose(arq);

    buffer[tmn] = '\0';

    char *palavraPulada = strstr(buffer, palavra);
    while(palavraPulada != NULL) {
        if(*(palavraPulada + strlen(palavra)) == 32) {
            memmove(palavraPulada, palavraPulada + strlen(palavra) + 1, strlen(palavraPulada + strlen(palavra)) + 1);
        } else {
            memmove(palavraPulada, palavraPulada + strlen(palavra), strlen(palavraPulada + strlen(palavra)) + 1);
        }
        palavraPulada = strstr(buffer, palavra);
    }

    printf("%s", buffer);
    free(buffer);
    free(palavra);
    free(arquivo);

    return 0;
}
