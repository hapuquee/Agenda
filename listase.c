#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

typedef struct elem{
    void* dado;
    struct elem *prox;
}elem; 

/*criar elemento*/

elem* criar_elem(void* dado){
    elem* novo =malloc(sizeof(elem));
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

typedef struct t_lse lse;
struct t_lse{
    elem* prim;
    elem* ult;
    int tam;
    imprimir_lse imprimir;
    comparar_lse compara;
};

lse* criar_lse(imprimir_lse imprimir, comparar_lse comparar){
    lse *l = malloc(sizeof(lse));
    l->prim = l->ult = NULL;
    l->tam = 0;
    l->imprimir = imprimir;
    l->compara = comparar;
}

void inserir_lse(lse *l, void* dado){
    elem* novo = criar_elem(dado);

    if(l->prim == NULL){
        l->prim = l->ult = novo;
    }
    else{
        novo->prox = l->prim;
        l->prim = novo;
    }
    l->tam++;
}

void inserir_final_lse(lse* lse, void* dado ){
    elem* novo = criar_elem(dado);

    lse->ult->prox = novo;
    lse->ult = novo;
    lse->tam++;
}

void* remover_lse(lse *l){
    void* dado = NULL;
    elem *removivel = l->prim;

    if(l->prim != NULL){
        dado = removivel->dado;
        l->prim = removivel->prox;
        free(removivel);
        l->tam--;
    }
    return dado;
}

void* remover_elem(void* elemento, lse* l){
    elem *x, *ant;
    void* dado = NULL;

    x = l->prim;

    while(l->compara(x->dado, elemento) != 0){
        ant = x;
        x = x->prox;
    }

    if(x == l->prim){
        dado = x->dado;
        l->prim = x->prox;
        free(x);
    }
    else{
        dado = x->dado;
        ant->prox = x->prox;
        l->tam--;
        free(x);
    }

    return dado;
}

void remover_prim(lse *l){
    elem* x;

    x = l->prim;
    l->prim = x->prox;
    free(x);
}

void* acessar_lse(lse *l, int pos){
    pos = pos%l->tam;
    elem *cam = l->prim;
    void* dado = NULL;
    if(l->prim){
        int i = 1;
        while(i<pos){
            cam = cam->prox;
            i++;
        }
        dado = cam->dado;
    }
    return dado;
    
}

void imprimi_lse(lse *l){
    elem *cam = l->prim;

    while(cam){
        l->imprimir(cam->dado);
        cam = cam->prox;
    }
}

void inserir_ordenado_lse(lse* l, void* carga){
    elem* cam = l->prim, *ant;
    
    while((cam != NULL) && (l->compara(cam->dado, carga) < 0)){
        ant = cam;
        cam = cam->prox;
    }
    if(cam == l->prim){//inicio
        inserir_lse(l, carga);
    }
    else if( cam == NULL){
        //insere no final
        inserir_final_lse(l, carga);
    }
    else{
        //meio
        elem* novo = criar_elem(carga);
        ant->prox = novo;
        novo->prox = cam;
        l->tam++;
    }
}

int tamanho(lse* l){
    return l->tam;
}

void* primeiro(lse* l){
    return l->prim->dado;
}

void alterar_elem(void* antigo, void* novo, lse* l){
    elem* x;

    x = l->prim;

    while(l->compara(x->dado, antigo)!=0){
        x = x->prox;
    }

    if(x != NULL){
        remover_elem(x->dado, l);
    }
    inserir_ordenado_lse(l,novo);
}
