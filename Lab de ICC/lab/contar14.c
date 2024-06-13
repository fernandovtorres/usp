#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcasestrDoPai(const char *buffer, const char *needle) {
    size_t tmnBuffer = strlen(buffer);
    size_t tamanho_agulha = strlen(needle);

    char *buffer_minusculo = malloc(tmnBuffer + 1);
    char *needle_minusculo = malloc(tamanho_agulha + 1);

    for(size_t i = 0; i < tmnBuffer; i++) {
        buffer_minusculo[i] = tolower((unsigned char)buffer[i]);
    }
    buffer_minusculo[tmnBuffer] = '\0';

    for(size_t i = 0; i < tamanho_agulha; i++) {
        needle_minusculo[i] = tolower((unsigned char)needle[i]);
    }
    needle_minusculo[tamanho_agulha] = '\0';

    char *resultado = strstr(buffer_minusculo, needle_minusculo);

    if (resultado) {
        resultado = (char *)(buffer + (resultado - buffer_minusculo));
    }

    free(buffer_minusculo);
    free(needle_minusculo);

    return resultado;
}

int main() {
    char *nomeArquivo = (char *) malloc(200 * sizeof(char));
    scanf(" %s", nomeArquivo);
    nomeArquivo = realloc(nomeArquivo, (strlen(nomeArquivo)+1) * sizeof(char));
    FILE *arq = fopen(nomeArquivo, "r");
    char *flag = (char *) malloc(200 * sizeof(char));
    scanf(" %s", flag);
    flag = realloc(flag, (strlen(flag)+1) * sizeof(char));
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    fseek(arq, 0, SEEK_END);
    size_t tmn = ftell(arq);
    fseek(arq, 0, SEEK_SET);
    char *buffer = (char *) malloc(tmn * sizeof(char));
    fread(buffer, tmn, 1, arq);
    buffer[tmn] = '\0';
    char *ptr = strcasestrDoPai(buffer, flag);
    int qnt = 0;
    while (ptr != NULL) {
        if(ptr[-1] == 32 && (((ptr[strlen(flag)] < 65 || ptr[strlen(flag)] > 90)) && (ptr[strlen(flag)] < 97 || ptr[strlen(flag)] > 122))){
            qnt++;
        }
        ptr = strcasestrDoPai(ptr + 1, flag);
    }
    printf("quantidade: %d\n", qnt);
    free(nomeArquivo);
    free(flag);
    fclose(arq);
    return 0;
}