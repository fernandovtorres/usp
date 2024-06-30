#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = (char *) malloc(15 * sizeof(char));
    scanf(" %s", buffer);
    buffer = realloc(buffer, (strlen(buffer)+1) * sizeof(char));
    FILE *arq = fopen(buffer, "rb");
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    char c;
    fread(&c, sizeof(char), 1, arq);
    while(!feof(arq)) {
        printf("%c", c);
        fread(&c, sizeof(char), 1, arq);
    }
    fclose(arq);
    free(buffer);
    return 0;
}
