#include <stdio.h>
#include <stdlib.h>

/* Definicao da estrutura basica de um no de arvore binaria[cite: 1] */
typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv;

/* 
 * Exercício 1:
 * Função que conta e retorna a quantidade de nós que armazenam números pares[cite: 1].
 * Protótipo: int pares (Arv* a);[cite: 1]
 */
int pares (Arv* a) {
    // Caso base: se a árvore ou subárvore for vazia, retorna 0
    if (a == NULL) {
        return 0;
    }
    
    // Verifica se o valor contido no nó atual é par (resto da divisão por 2 igual a 0)
    int eh_par = (a->info % 2 == 0) ? 1 : 0;
    
    // Retorna a contagem do nó atual somada recursivamente às subárvores esquerda e direita
    return eh_par + pares(a->esq) + pares(a->dir);
}

/* 
 * Exercício 2:
 * Função que conta e retorna a quantidade de folhas de uma árvore binária[cite: 1].
 * Uma folha é um nó que não possui ponteiros para filhos (esq e dir são NULL)[cite: 1].
 * Protótipo: int folhas (Arv* a);[cite: 1]
 */
int folhas (Arv* a) {
    // Caso base: nó nulo não é uma folha
    if (a == NULL) {
        return 0;
    }
    
    // Condição de folha: ambos os ponteiros de filhos são nulos
    if (a->esq == NULL && a->dir == NULL) {
        return 1;
    }
    
    // Soma recursiva das folhas encontradas nas subárvores esquerda e direita
    return folhas(a->esq) + folhas(a->dir);
}

/* 
 * Exercício 3:
 * Função que conta e retorna a quantidade de nós que possuem exatamente um filho[cite: 1].
 * Protótipo: int um_filho (Arv* a);[cite: 1]
 */
int um_filho (Arv* a) {
    // Caso base: árvore vazia não possui nós
    if (a == NULL) {
        return 0;
    }
    
    // Verifica se possui exatamente um filho (esquerda existe e direita não, ou vice-versa)
    int tem_um_filho = ((a->esq != NULL && a->dir == NULL) || (a->esq == NULL && a->dir != NULL)) ? 1 : 0;
    
    // Soma o resultado do nó atual com o processamento das subárvores esquerda e direita
    return tem_um_filho + um_filho(a->esq) + um_filho(a->dir);
}

/* 
 * Exercício 4:
 * Função que compara se duas árvores binárias são idênticas em estrutura e valores[cite: 1].
 * Retorna 1 se forem iguais e 0 caso contrário[cite: 1].
 * Protótipo: int igual (Arv* a, Arv* b);[cite: 1]
 */
int igual (Arv* a, Arv* b) {
    // Se ambas forem nulas, são consideradas iguais neste ramo
    if (a == NULL && b == NULL) {
        return 1;
    }
    
    // Se apenas uma for nula (e a outra não), as árvores são diferentes
    if (a == NULL || b == NULL) {
        return 0;
    }
    
    // Verifica se a informação do nó atual é igual
    // e chama a função recursivamente para validar as subárvores correspondentes
    return (a->info == b->info) && igual(a->esq, b->esq) && igual(a->dir, b->dir);
}
/* 
 * Exercício 5:
 * Função que cria e retorna uma cópia exata de uma árvore binária dada[cite: 2].
 * Protótipo: Arv* copia (Arv* a);[cite: 2]
 */
Arv* copia (Arv* a) {
    // Caso base: se a árvore original for vazia (NULL), a cópia também será vazia (NULL)
    if (a == NULL) {
        return NULL;
    }
    
    // Aloca dinamicamente memória para o novo nó da árvore copiada
    Arv* novo = (Arv*) malloc(sizeof(Arv));
    if (novo == NULL) {
        // Trata falha na alocação de memória, se necessário
        exit(1);
    }
    
    // Copia a informação armazenada no nó atual
    novo->info = a->info;
    
    // Cria recursivamente as cópias das subárvores esquerda e direita
    novo->esq = copia(a->esq);
    novo->dir = copia(a->dir);
    
    // Retorna o ponteiro para o novo nó criado
    return novo;
}
