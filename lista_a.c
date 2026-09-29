#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv;

/* Exercício 1 */
int pares (Arv* a) {
    if (a == NULL) {
        return 0;
    }
    
    int eh_par = (a->info % 2 == 0) ? 1 : 0;
    return eh_par + pares(a->esq) + pares(a->dir);
}

/* Exercício 2 */
int folhas (Arv* a) {
    if (a == NULL) {
        return 0;
    }
    
    if (a->esq == NULL && a->dir == NULL) {
        return 1;
    }
    
    return folhas(a->esq) + folhas(a->dir);
}

/* Exercício 3 */
int um_filho (Arv* a) {
    if (a == NULL) {
        return 0;
    }
    
    int tem_um_filho = ((a->esq != NULL && a->dir == NULL) || (a->esq == NULL && a->dir != NULL)) ? 1 : 0;
    return tem_um_filho + um_filho(a->esq) + um_filho(a->dir);
}

/* Exercício 4 */
int igual (Arv* a, Arv* b) {
    if (a == NULL && b == NULL) {
        return 1;
    }
    
    if (a == NULL || b == NULL) {
        return 0;
    }
    
    return (a->info == b->info) && igual(a->esq, b->esq) && igual(a->dir, b->dir);
}

/* Exercício 5 */
Arv* copia (Arv* a) {
    if (a == NULL) {
        return NULL;
    }
    
    Arv* novo = (Arv*) malloc(sizeof(Arv));
    if (novo == NULL) {
        exit(1);
    }
    
    novo->info = a->info;
    novo->esq = copia(a->esq);
    novo->dir = copia(a->dir);
    
    return novo;
}