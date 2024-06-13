#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    char *cpf;
    int idade;
    float saldo;
    float credito;
    float divida;
} pessoa;

#define INITPERSONA(x) pessoa x = {.divida = 0}

/**
 * Função principal do programa.
 * Lê os dados de várias pessoas e verifica se estão endividadas.
 * Imprime os dados de todas as pessoas e, em seguida, imprime os dados das pessoas endividadas.
 * 
 * @return 0 se o programa for executado com sucesso.
 */
int main(void) {
    int n; scanf(" %d", &n); // Lê o número de pessoas a serem lidas
    pessoa *endividados = NULL; // Ponteiro para o array de pessoas endividadas
    int cnt = 0, index = 0; // Variáveis de controle
    for(int i = 0; i < n; i++){
        char buffer[62]; // Buffer para armazenar a linha de entrada
        scanf(" %[^\n]s", buffer); // Lê a linha de entrada
        INITPERSONA(nova); // Inicializa uma nova pessoa com divida igual a 0
        char* token = strtok(buffer, ","); // Divide a linha em tokens usando a vírgula como delimitador
        nova.nome = malloc((strlen(token)+1) * sizeof(char)); // Aloca memória para o nome da pessoa
        strcpy(nova.nome, token); // Copia o nome para a estrutura da pessoa
        token = strtok(NULL, ","); // Avança para o próximo token
        token += 1; // Ignora o espaço em branco após a vírgula
        nova.cpf = malloc((strlen(token)+1) * sizeof(char)); // Aloca memória para o CPF da pessoa
        strcpy(nova.cpf, token); // Copia o CPF para a estrutura da pessoa
        token = strtok(NULL, ","); // Avança para o próximo token
        nova.idade = atoi(token+1); // Converte a idade para inteiro e atribui à estrutura da pessoa
        token = strtok(NULL, ","); // Avança para o próximo token
        nova.saldo = atof(token+1); // Converte o saldo para float e atribui à estrutura da pessoa
        token = strtok(NULL, ","); // Avança para o próximo token
        nova.credito = atof(token+1); // Converte o crédito para float e atribui à estrutura da pessoa
        nova.divida = nova.credito > nova.saldo ? nova.credito - nova.saldo : 0; // Calcula a dívida da pessoa
        if(nova.divida) {
            cnt++; // Incrementa o contador de pessoas endividadas
            endividados = realloc(endividados, sizeof(pessoa)*cnt); // Realoca o array de pessoas endividadas
            endividados[index] = nova; // Adiciona a pessoa endividada ao array
            index++; // Incrementa o índice do array
        }
        printf("Dados da pessoa %d:\nNome: %s\nCPF: %s\nIdade: %d\nSaldo: %.2f\nCredito: %.2f\n\n", i+1, nova.nome, nova.cpf, nova.idade, nova.saldo, nova.credito); // Imprime os dados da pessoa
    }
    int c = 0;
    printf("Pessoas endividadas:\n");
    for(int i = 0; i < cnt; i++){
        c=1;
        if(i != cnt - 1) {
            printf("Nome: %s\nCPF: %s\nDivida: %.2f\n\n", endividados[i].nome, endividados[i].cpf, endividados[i].divida); // Imprime os dados da pessoa endividada
        }
        else {
            printf("Nome: %s\nCPF: %s\nDivida: %.2f", endividados[i].nome, endividados[i].cpf, endividados[i].divida); // Imprime os dados da última pessoa endividada sem quebra de linha
        }
        free(endividados[i].nome); // Libera a memória alocada para o nome da pessoa
        free(endividados[i].cpf); // Libera a memória alocada para o CPF da pessoa
    }
    free(endividados); // Libera a memória alocada para o array de pessoas endividadas
    if (!c) {
        printf("Nenhuma pessoa endividada encontrada."); // Imprime mensagem caso não haja pessoas endividadas
    }
    return 0;
}