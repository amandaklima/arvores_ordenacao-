#include <stdio.h>

// remoção de nó 
// se tem um filho é só cortar, se tem mais de um precisa de um ponteiro pro pai e um pro filho, se tiver mais de um filho é o elemento mais a esqueda da subarvore direita (antecessor  ou sucessor)
//questão de prova

typedef struct Arv {
    int info;
    struct Arv *esq;
    struct Arv *dir;
} Arv;

Arv* retira(Arv* r, int v ){
    if(r==NULL)
       return NULL;
    else if (v < r -> info)
        r->esq = retira(e->, v);
    else if ( v-> r -> info)
        r->dir = retira(r->dir, v);
    else if (r->esq ==NULL && r->dir ==NULL)
        free(r);
        r==NULL;
    else if (r-> esq ==NULL && r->dir ==NULL){
        Arv*t;
        t=r;
        r=r->dir;
        free(t);
    else if( r->esq !=NULL && r->dir==NULL){
        Arv*t;
        t=esq
        r=r->esq;
        free(t);
    }
    else { 
        Arv*t;
        t=r->esq;
        while (t->dir !=NULL)
        {
            t=t->dir;
        }
        r->info= t->info;
        t->info = v;
        r->esq = retira(r->esq, v);    
    }    
}
