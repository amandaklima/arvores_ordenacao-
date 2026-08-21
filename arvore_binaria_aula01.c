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

int main() {

    No *arvore1 = criarArvoreNula();
    No *arvore2 = criarArvoreNaoNula(10);

    arvore2->esquerda = criarArvoreNaoNula(5);
    arvore2->direita = criarArvoreNaoNula(20);

    printf("Raiz: %d\n", arvore2->valor);
    printf("Filho esquerdo: %d\n", arvore2->esquerda->valor);
    printf("Filho direito: %d\n", arvore2->direita->valor);

    return 0;
}
