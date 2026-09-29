#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv;

void imprime (Arv* a) {
    if (a != NULL) {
        imprime(a->esq);
        printf("%d ", a->info);
        imprime(a->dir);
    }
}

Arv* busca (Arv* r, int v) {
    if (r == NULL || r->info == v) {
        return r;
    }
    
    if (v < r->info) {
        return busca(r->esq, v);
    } else {
        return busca(r->dir, v);
    }
}

Arv* insere (Arv* a, int v) {
    if (a == NULL) {
        Arv* novo = (Arv*) malloc(sizeof(Arv));
        novo->info = v;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    
    if (v < a->info) {
        a->esq = insere(a->esq, v);
    } else if (v > a->info) {
        a->dir = insere(a->dir, v);
    }
    
    return a;
}

Arv* retira (Arv* r, int v) {
    if (r == NULL) {
        return NULL;
    }
    
    if (v < r->info) {
        r->esq = retira(r->esq, v);
    } else if (v > r->info) {
        r->dir = retira(r->dir, v);
    } else {
        if (r->esq == NULL) {
            Arv* temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            Arv* temp = r->esq;
            free(r);
            return temp;
        }
        
        Arv* temp = r->esq;
        while (temp->dir != NULL) {
            temp = temp->dir;
        }
        
        r->info = temp->info;
        r->esq = retira(r->esq, temp->info);
    }
    
    return r;
}