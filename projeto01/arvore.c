// todas as funções descritas no arvore.h 
#include <stdio.h>
#include <stdlib.h>
#include <arvore.h>>

typedef struct Arv {
    int valor;
    struct Arv *esquerda;
    struct Arv *direita;
} Arv;

Arv* arv_criavazia() {
    return NULL;
}

Arv* arv_cria(int valor) {
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


int arv_pertence(Arv *arvore, int elemento) {

    if (arvore == NULL) {
        return 0;
    }
    if (arvore->valor == elemento) {
        return 1;
    }
    return arv_buscar(arvore->esquerda, elemento) || arv_buscar(arvore->direita, elemento);
}