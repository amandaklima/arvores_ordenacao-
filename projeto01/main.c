// imprimir arvore final na pré ordem, 
// verificar se "e" está na arvore ,
// veriticar  se "z" está na ávore,
// liberar a subarvore cuja raiz é "e"(imprimir arvore na pré ordem),
// calcular a altura(h) e 
//calcular qtd de nós

// buscar "e"

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


int main() {

    Arv  = arv_cria(10);

    a->esquerda = arv_cria(5);
    a->direita = arv_cria(20);

    char elemento = "z";

    if (arv_pertence( Arv*a , elemento)) {
        printf(" 'z' Existe na árvore!\n");
    } else {
        printf(" 'z'Não existe na árvore!\n");
    }

    return 0;
}
