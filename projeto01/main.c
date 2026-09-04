// imprimir arvore final na pré ordem, 
// verificar se "e" está na arvore ,
// veriticar  se "z" está na ávore,
// liberar a subarvore cuja raiz é "e"(imprimir arvore na pré ordem),
// calcular a altura(h) e 
//calcular qtd de nós
// buscar "e"

#include <stdio.h>
#include "arvore.h"

int main()
{
    Arv *d = arv_cria('d', NULL, NULL);
    Arv *g = arv_cria('g', NULL, NULL);
    Arv *h = arv_cria('h', NULL, NULL);

    Arv *e = arv_cria('e', g, h);

    Arv *b = arv_cria('b', d, e);

    Arv *f = arv_cria('f', NULL, NULL);
    Arv *c = arv_cria('c', NULL, f);

    Arv *a = arv_cria('a', b, c);

    printf("Arvore em pre-ordem: ");
    arv_imprime(a);
    printf("\n");

    if (arv_pertence(a, 'e')) {
        printf("\"e\" pertence a arvore.\n");
    } else {
        printf("\"e\" nao pertence a arvore.\n");
    }

    if (arv_pertence(a, 'z')) {
        printf("\"z\" pertence a arvore.\n");
    } else {
        printf("\"z\" nao pertence a arvore.\n");
    }

    printf("\nAltura da arvore: %d\n", arv_altura(a));

    printf("Quantidade de nos: %d\n", arv_qtd_nos(a));

    if (arv_pertence(a, 'e')) {
        printf("\"e\" foi encontrado na arvore.\n");
    } else {
        printf("\"e\" nao foi encontrado na arvore.\n");
    }

    a = arv_libera(a);

    return 0;
}
