//Link do vídeo
//https://youtu.be/GIlIoS4G5oE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//defiinindo algumas limitações
#define MAX_COMPRIMENTO_LINHA 1000
#define MAX_COMPRIMENTO_PALAVRA 20

//estruturando os dados chamados na arvore
typedef struct no {
    int folha;
    int linhas[MAX_COMPRIMENTO_LINHA];
    struct no *filhos[256];
} No;

//função que cria um novo nó 
No *novo_no() {
    int i;
    No *novo = (No *) malloc(sizeof(No));
    novo->folha = 0;
    for (i = 0; i < MAX_COMPRIMENTO_LINHA; i++) {
        novo->linhas[i] = 0;
    }
    for (i = 0; i < 256; i++) {
        novo->filhos[i] = NULL;
    }
    return novo;
}

//função que inseri a palavra e o numero da linha dentro da arvore
void inserir(No *raiz, char *palavra, int numero_linha) {
    int i, indice;
    for (i = 0; palavra[i]; i++) {
        indice = (int) palavra[i];
        if (!raiz->filhos[indice]) {
            raiz->filhos[indice] = novo_no();
        }
        raiz = raiz->filhos[indice];
    }
    raiz->folha = 1;
    raiz->linhas[numero_linha] = 1;
}

//função que imprime as palavras em ordem alfabetica 
void imprimir_palavras(No *raiz, char *palavra, int indice) {
    int i, j;
    if (raiz->folha) {
        palavra[indice] = '\0';
        printf("A palavra (%s) foi encontrado nas linhas: ", palavra);
        for (i = 0; i < MAX_COMPRIMENTO_LINHA; i++) {
            if (raiz->linhas[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    for (i = 0; i < 256; i++) {
        if (raiz->filhos[i]) {
            palavra[indice] = (char) i;
            imprimir_palavras(raiz->filhos[i], palavra, indice + 1);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *arquivo = fopen("texto.txt", "r"); //definindo um tipo de dado para o arquivo ser lido

    //Caso o arquivo não esteja no computador
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }   


    //definindo os tipos de dados
    No *root = novo_no();
    char line[MAX_COMPRIMENTO_LINHA], word[MAX_COMPRIMENTO_PALAVRA], print_word[MAX_COMPRIMENTO_PALAVRA];;
    int line_number = 0;

    // Lê cada linha do arquivo
    while (fgets(line, MAX_COMPRIMENTO_LINHA, arquivo)) {
        line_number++;
        int i = 0, j = 0;
        
        // Insere na as palavras contidas nas linhas árvore Patricia
        while (line[i]) {
            if (isalnum(line[i])) {
                word[j++] = tolower(line[i]);
            } else {
                word[j] = '\0';
                if (j >= 3) {
                    inserir(root, word, line_number);
                }
                j = 0;
            }
            i++;
        }

        // Insere a última palavra com mais de 3 letras  na árvore, se houver
        if (j >= 3) {
            word[j] = '\0';
            inserir(root, word, line_number);
        }
    }

    // Fecha a leitrura do arquivo
    fclose(arquivo);

    // Imprime as palavras em ordem alfabetica junto com as linhas onde as mesma foram encontradas
    imprimir_palavras(root, print_word, 0);

    return 0;
}
