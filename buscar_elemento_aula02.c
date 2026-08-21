#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarArvoreNula() {
    return NULL;
}

No* criarArvoreNaoNula(int valor) {
    No *novoNo = (No*) malloc(sizeof(No));

    if (novoNo == NULL) {
        printf("Erro: memória insuficiente!\n");
        exit(1);
    }

    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    return novoNo;
}

int buscar(No *arvore, int elemento) {

    if (arvore == NULL) {
        return 0;
    }

    if (arvore->valor == elemento) {
        return 1;
    }
    return buscar(arvore->esquerda, elemento) || buscar(arvore->direita, elemento);
}

int main() {

    No *arvore = criarArvoreNaoNula(10);

    arvore->esquerda = criarArvoreNaoNula(5);
    arvore->direita = criarArvoreNaoNula(20);

    int elemento;

    printf("Qual elemento você quer buscar? ");
    scanf("%d", &elemento);

    if (buscar(arvore, elemento)) {
        printf("Existe na árvore!\n");
    } else {
        printf("Não existe na árvore!\n");
    }

    return 0;
}
