#ifndef _VIWER_H_
#define _VIWER_H_ 

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "model.h"

int apresenta_menu_principal(){

    return opcao;
}

int quantidade_jogadores(){

    int opcao = 0;

    printf("--- BEM VINDO AO JOGO DE DOMINO ---\n\n");
    printf("Selecione a quantidade de jogadores: [2] [4]\n");

    scanf("%d", &opcao);
    return opcao;
}

void nome_jogadores(int quantidade_jogadores, char *nome_jogadores[] ){

    for(int i = 0; i < quantidade_jogadores; i++){
        printf("Digite o nome do jogador %d: ", i+1);
        scanf("%s", nome_jogadores[i]);
    }
}

int menu_de_jogada(char *nome_jogador){
    int opcao = 0;

    printf("Vez do jogador %s\n", nome_jogador);

    printf("Escolha uma opcao abaixo:\n");
    printf("1 - Mesa do Domino");
    printf("2 - Ver suas pecas");
    printf("3 - Comprar peca");
    printf("4 - Jogar");
    
    scanf("%d", &opcao);
    return opcao;
}

#endif