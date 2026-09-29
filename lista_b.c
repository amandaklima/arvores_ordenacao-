#include <stdio.h>
#include <stdlib.h>

typedef struct arvvar {
    int info;
    struct arvvar* prim;
    struct arvvar* prox;
} ArvVar;

// Exercício 1
int pares (ArvVar* a) {
    if (a == NULL) {
        return 0;
    }
    int eh_par = (a->info % 2 == 0) ? 1 : 0;
    return eh_par + pares(a->prim) + pares(a->prox);
}

// Exercício 2
int folhas (ArvVar* a) {
    if (a == NULL) {
        return 0;
    }
    if (a->prim == NULL) {
        return 1 + folhas(a->prox);
    }
    return folhas(a->prim) + folhas(a->prox);
}

// Exercício 3
int um_filho (ArvVar* a) {
    if (a == NULL) {
        return 0;
    }
    int tem_um_unico_filho = 0;
    if (a->prim != NULL && a->prim->prox == NULL) {
        tem_um_unico_filho = 1;
    }
    return tem_um_unico_filho + um_filho(a->prim) + um_filho(a->prox);
}

// Exercício 4
int igual (ArvVar* a, ArvVar* b) {
    if (a == NULL && b == NULL) {
        return 1;
    }
    if (a == NULL || b == NULL) {
        return 0;
    }
    return (a->info == b->info) && igual(a->prim, b->prim) && igual(a->prox, b->prox);
}

// Exercício 5
ArvVar* copia (ArvVar* a) {
    if (a == NULL) {
        return NULL;
    }
    
    ArvVar* novo = (ArvVar*) malloc(sizeof(ArvVar));
    if (novo == NULL) {
        exit(1);
    }
    
    novo->info = a->info;
    novo->prim = copia(a->prim);
    novo->prox = copia(a->prox);
    
    return novo;
}