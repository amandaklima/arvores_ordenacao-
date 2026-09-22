#include <stdio.h>

typedef struct Arv {
    int valor;
    struct Arv *esq;
    struct Arv *dir;
} Arv;


void imprime (Arv*a){
    if(a!=NULL){
        imprime(a->esq);
        printf("%d,a->info");
        imprime(a->dir);
    }
}
