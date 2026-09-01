#include <stdio.h>
#include <stdlib.h>

typedef struct Arv {
    int valor;
    struct Arv *esquerda;
    struct Arv *direita;
} Arv;

Arv* criarArvoreNula() {
    return NULL;
}

Arv* criarArvoreNaoNula(int valor) {
    Arv *novoNo = (Arv*) malloc(sizeof(Arv));

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

    Arv *arvore1 = criarArvoreNula();
    Arv *arvore2 = criarArvoreNaoNula(10);

    arvore2->esquerda = criarArvoreNaoNula(5);
    arvore2->direita = criarArvoreNaoNula(20);

    printf("Raiz: %d\n", arvore2->valor);
    printf("Filho esquerdo: %d\n", arvore2->esquerda->valor);
    printf("Filho direito: %d\n", arvore2->direita->valor);

    return 0;
}
