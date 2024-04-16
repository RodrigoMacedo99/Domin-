#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include "lista_de.h"
#include "model.h"
#define MAX 28

typedef jogador item_jogador;

typedef struct {
    item_jogador item[MAX];
    int ini, fim;
 //   int tam;
} tp_fila;

void inicializa_fila(tp_fila *f) {
    f->ini = f->fim = MAX-1;
    //f->tam=0;
}

int fila_vazia(tp_fila *f){
    if(f->ini == f->fim) return 1;
    return 0;
}

int proximo (int pos){
    if(pos== MAX-1) return 0;
    return ++pos;
}

int fila_cheia (tp_fila *f){
    if(proximo(f->fim)==f->ini)
        return 1;
    return 0;
}

int insere_fila (tp_fila *f, item_jogador e){
    if(fila_cheia(f)) 
        return 0; //Não foi possível adicionar a fila  
    f->fim = proximo(f->fim);
    f->item[f->fim]=e;
 //   f->tam++;
    return 1;
}

int remove_fila (tp_fila *f, item_jogador *e){
    if(fila_vazia(f)) 
        return 0; //Não foi possível remover da fila
    f->ini = proximo(f->ini);
    *e = f->item[f->ini];
    //f->tam--;
    return 1;
}

/*void inicio_fila(tp_fila *f){
    if(fila_vazia(f)){
        printf("Fila vazia\n");
        return;
    }
    item_jogador e = f->item[f->ini];
    printf("Informações do dado no início da fila:\n");
    printf("ID: %hd\n", e.id_do_jogador);
    printf("Nome: %s\n", e.nome);
}*/

void imprime_fila (tp_fila f){
    item_jogador e;
    printf("\n Nomes dos jogadores:\n\n");
	printf("id| nome  | mao");
	printf("\n--+------+---------------------------");
    while(!fila_vazia(&f)){
        remove_fila(&f, &e);
        printf("\n%hd | %s ", e.id_do_jogador, e.nome);
        imprime_listad(f.item[f.ini].mao, 1);
    }
    printf("\n\n\n\n");
    system("pause");
    system("cls");
}

// Duas opções de código do tamanho_fila     
/*int tamanho_fila(tp_fila *f){
	if (fila_vazia(f)) return 0;
	if (f->ini < f->fim) return f->fim - f->ini;
	return MAX - 1 - f->ini + f->fim + 1;
 }*/
 
 int tamanho_fila(tp_fila f){
    short int cont=0;
	item_jogador e;
    while(!fila_vazia(&f)){
        remove_fila(&f, &e);
        cont++;
    }	
    return cont;
 }
/*  
int tamanho_fila2(tp_fila *f){
   return f->tam;	
}*/

#endif // FILA_H
