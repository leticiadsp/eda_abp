#include <bits/stdc++.h>
using namespace std;

typedef struct no{
    int valor;
    struct no *esq;
    struct no *dir;
}tno;

tno *inserir (tno *raiz, int chave){
    if(raiz == NULL){
        tno *novo = (tno *)malloc(sizeof(tno));
        novo->valor = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if(chave < raiz->valor) raiz->esq = inserir (raiz->esq, chave);
    else raiz->dir = inserir (raiz->dir, chave);
    return raiz;

}

int buscar(tno *raiz, int chave){
    if(raiz == NULL) return INT_MAX;

    int sub = abs(chave - raiz->valor);//dif estre a chave e o nó atual
    int esq = buscar(raiz->esq, chave);//menor dif encontrada na subarvore esquerda
    int dir =  buscar(raiz->dir, chave);//menor dif encontrada na subarvore direita

    return min({sub, esq, dir});

}

tno *minimo(tno *raiz){
    while(raiz->esq != NULL){
        raiz = raiz->esq;
    }
    return raiz;

}

tno *remover(tno *raiz, int chave){
    if(raiz == NULL) return NULL;

    if(chave < raiz->valor) raiz->esq = remover(raiz->esq, chave);
    else if (chave > raiz->valor)raiz->dir = remover(raiz->dir, chave);
    else{
        if(raiz->esq == NULL){
            tno *temp = raiz->dir;
            free(raiz);
            return temp;
        }
        if(raiz->dir == NULL){
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

void imprimir(tno *raiz){
    if(raiz == NULL)return;

    imprimir(raiz->esq);
    printf("%d ", raiz->valor);
    imprimir(raiz->dir);



}


int main(){
    tno *raiz = NULL;
    int n;
    cin >> n;
    int minimo = 0;


    vector<int>v(n);
    vector<int>v2(n + 1);

    for(int i = 0; i < n; i++)cin >> v[i];
    for(int i = 0; i < n + 1; i++)cin >> v2[i];
    
    for(int i = 0; i < n + 1; i++) raiz = inserir(raiz, v2[i]);

    imprimir(raiz);

    for(int i = 0; i < n; i++) {
        minimo+=buscar(raiz, v[i]);
    }

    cout << minimo << endl;

}