#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char* titulo;
    char* autor;
    char* ano;
    int qnt;
}livros ;

#define INIT_LIVROS(X) livros X = {.qnt = 1}

int verificaLivro(livros livro, livros* biblio, int tm) {
    for(int i = 0; i < tm; i++) {
        if(!strcmp(livro.titulo, biblio[i].titulo)) {
            return i;
        }
    }
    return -1;
}


int main(){
    int n; scanf(" %d", &n);
    int qntTotal = 0;
    livros *biblio = NULL;
    for(int i = 0; i < n; i++){
        char input[200];
        scanf(" %[^\n]s", input);
        INIT_LIVROS(livro);
        char* token = strtok(input, ",");
        livro.titulo = calloc(strlen(token) + 1, sizeof(char));
        strcpy(livro.titulo, token);
        token = strtok(NULL, ",");
        livro.autor = calloc(strlen(token) + 1, sizeof(char));
        strcpy(livro.autor, token);
        token = strtok(NULL, ",");
        livro.ano = calloc(strlen(token) + 1, sizeof(char));
        strcpy(livro.ano, token);
        int Existe = verificaLivro(livro, biblio, qntTotal);
        if(Existe == -1) {
            qntTotal += 1;
            biblio = realloc(biblio, sizeof(livros)*qntTotal);
            biblio[qntTotal-1] = livro;
        } else {
            biblio[Existe].qnt ++;
        }
    }
    printf("Catalogo de Livros:\n");
    for(int i = 0; i < qntTotal; i++){
        printf("Livro %d:\n", i+1);
        if(i != qntTotal-1) {
            printf("Titulo: %s\nAutor:%s\nAno:%s\nQuantidade: %d\n\n", biblio[i].titulo, biblio[i].autor, biblio[i].ano, biblio[i].qnt);
        } else {
            printf("Titulo: %s\nAutor:%s\nAno:%s\nQuantidade: %d", biblio[i].titulo, biblio[i].autor, biblio[i].ano, biblio[i].qnt);
        }
    }
    return 0;
}