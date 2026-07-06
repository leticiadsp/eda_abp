#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
}tno;

tno *inserir(tno *raiz, int chave){
    if(raiz == NULL){
        tno *novo = (tno *)malloc(sizeof(tno));
        novo->valor = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if(chave < raiz->valor)raiz->esq = inserir(raiz->esq, chave);
    else raiz->dir = inserir(raiz->dir, chave);

    return raiz;

}

tno *minimo(tno *raiz){
    while(raiz->esq != NULL) raiz = raiz->esq;

    return raiz;

}

tno *buscar(tno *raiz, int chave){
    if(raiz== NULL)return NULL;

    if(raiz->valor == chave)return raiz;

    if(chave < raiz->valor)return buscar(raiz->esq, chave);
    else return buscar(raiz->dir, chave);

}

tno *remover(tno *raiz, int chave){
    if(raiz == NULL)return NULL;

    if(chave < raiz->valor) raiz->esq = remover(raiz->esq, chave);
    else if(chave > raiz->valor)raiz->dir = remover(raiz->dir, chave);
    else {
        if(raiz->esq == NULL){
            tno *temp = raiz->dir;
            free(raiz);
            return temp;
        } else if(raiz->dir == NULL){
            tno *temp = raiz->esq;
            free(raiz);
            return temp;
        } 
        tno *suc = minimo(raiz->dir);
        raiz->valor = suc->valor;
        raiz->dir = remover(raiz->dir, suc->valor);
        
    }
    return raiz;
}

void inorder(tno *raiz){
    if(raiz == NULL)return;

    inorder(raiz->esq);
    printf("%d ", raiz->valor);
    inorder(raiz->dir);
}

int folha(tno *raiz){
    if(raiz == NULL) return 0;

    if(raiz->dir == NULL && raiz->esq == NULL) return 1;

    return folha(raiz->dir) + folha(raiz->esq);
}

int nos(tno *raiz){
    if(raiz == NULL)return 0;

    return 1 + nos(raiz->esq) + nos(raiz->dir);
}

int altura(tno *raiz){
    if(raiz == NULL)return -1;

    int a = altura(raiz->esq);
    int b = altura(raiz->dir);

    //1 = raiz
    return 1 + (a > b? a : b);

}

int ehABP(tno *raiz, int min, int max){
    if(raiz == NULL)return 1;

    if(raiz->valor <= min || raiz->valor >= max) return 0;
    return ehABP(raiz->esq, min, raiz->valor) && ehABP(raiz->dir, raiz->valor, max);

}


int main(){
    tno *raiz = NULL;

    int vals[5] = {24, 65, 78, 55, 10};
    for(int i = 0; i < 5; i++) {
        raiz = inserir(raiz, vals[i]);
    }
    inorder(raiz);
    printf("\n");

    tno *resultado = buscar(raiz, 55);
    if(resultado != NULL)printf("encontrado: %d\n", resultado->valor);
    else printf("nao encontrado\n");

    resultado = buscar(raiz, 734);
    if(resultado != NULL)printf("encontrado: %d\n", resultado->valor);
    else printf("nao encontrado\n");

    int folhas = folha(raiz);
    printf("qtd de folhas: %d\n", folhas);

    int qtdno = nos(raiz);
    printf("qtds de nos: %d\n", qtdno);

    int ehab = ehABP(raiz, INT_MIN, INT_MAX);
    printf("eh abp? %d\n", ehab);

    int alt = altura(raiz);
    printf("altura da arvore = %d\n", alt);

    raiz = remover(raiz, 55);
    inorder(raiz);
    printf("\n");

}