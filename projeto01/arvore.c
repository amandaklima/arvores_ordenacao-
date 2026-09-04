#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arv {
    char valor;
    Arv *esquerda;
    Arv *direita;
};

Arv *arv_criavazia()
{
    return NULL;
}

/*
    c   -> valor armazenado no nó
    sae -> subárvore esquerda
    sad -> subárvore direita
*/
Arv *arv_cria(char c, Arv *sae, Arv *sad)
{
    Arv *novoNo;

    novoNo = (Arv *) malloc(sizeof(Arv));

    if (novoNo == NULL) {
        printf("Erro: memoria insuficiente!\n");
        exit(1);
    }

    novoNo->valor = c;
    novoNo->esquerda = sae;
    novoNo->direita = sad;

    return novoNo;
}

int arv_vazia(Arv *a)
{
    if (a == NULL) {
        return 1;
    }

    return 0;
}

int arv_pertence(Arv *a, char c)
{
    if (a == NULL) {
        return 0;
    }

    if (a->valor == c) {
        return 1;
    }

    return arv_pertence(a->esquerda, c) ||
           arv_pertence(a->direita, c);
}

Arv *arv_libera(Arv *a)
{
    if (a != NULL) {
        arv_libera(a->esquerda);
        arv_libera(a->direita);
        free(a);
    }

    return NULL;
}

void arv_imprime(Arv *a)
{
    if (a != NULL) {
        printf("%c ", a->valor);

        arv_imprime(a->esquerda);
        arv_imprime(a->direita);
    }
}

int arv_altura(Arv *a)
{
    int alturaEsquerda;
    int alturaDireita;

    if (a == NULL) {
        return 0;
    }

    alturaEsquerda = arv_altura(a->esquerda);
    alturaDireita = arv_altura(a->direita);

    if (alturaEsquerda > alturaDireita) {
        return alturaEsquerda + 1;
    }

    return alturaDireita + 1;
}

int arv_qtd_nos(Arv *a)
{
    if (a == NULL) {
        return 0;
    }

    return 1
           + arv_qtd_nos(a->esquerda)
           + arv_qtd_nos(a->direita);
}
