#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}tno;

tno *constroi(){
    int dado;

    scanf("%d", &dado);

    if(dado == -1)
        return NULL;

    tno *novo = (tno *)malloc (sizeof(tno));//alocando memoria para um novo no 
    novo->info = dado;//campo info do nó recebera o valor do dado 
    novo->esq = constroi();//constroi o lado esquerdo
    novo->dir = constroi();//constroi o lado direito

    return novo;
}

tno *inserir(tno *raiz, int valor){
    if(raiz == NULL){
        tno *novo = (tno *) malloc(sizeof(tno));
        novo->info = valor;//raiz
        novo->esq = NULL;//lado esquerdo 
        novo->dir = NULL;//lado direito
        return novo;
    }
    //se ja tiver valor na raiz
    //se o novo valor for menor que o valor da raiz -> insere ele na esquerda
    if(valor < raiz->info) raiz->esq = inserir(raiz->esq, valor);
    //senao insere ele na direita
    else raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

tno *buscar(tno *raiz, int valor){
    if(raiz == NULL) return NULL;
    if(valor == raiz->info) return raiz;
    if(valor < raiz->info) return buscar(raiz->esq, valor);
    //se nao entrar em nenhum dos if's-> procura o valor no lado direito
    return buscar(raiz-> dir, valor);

}


int main(){
    tno *raiz = NULL;//começa com memoria = null
    //nao existe no nenhum ainda

    raiz = inserir(raiz,10);
    //raiz == NULL -> cria nó
    //memoria alocada = [NÓ1]
    //info = 10, esq = NULL, dir = NULL;
    raiz = inserir(raiz,5);
    // 5 < 10
    //esquerda esta NULL -> cria novo nó
    //memoria: [NÓ1] 10
            //    /
            //  [NÓ2] 5
    raiz = inserir(raiz,20);


}