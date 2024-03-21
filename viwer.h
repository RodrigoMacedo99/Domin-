#ifndef _VIWER_H_
#define _VIWER_H_ 

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "model.h"

int apresenta_menu_principal(){

    int opcao = 0;

    printf("--- BEM VINDO AO JOGO DE DOMINO DO GRUPO GCC ---\n\n");
    printf("Escolha uma opcao abaixo:\n");
    printf("1 - Iniciar novo Jogo");


    scanf("%d", &opcao);

    return opcao;
}

int introducao(){

    int opcao;

    printf("--- BEM VINDO AO JOGO DE DOMINO ---\n\n");
    printf("Selecione a quantidade de jogadores: [2] [4]\n");

    scanf("%d", &opcao);
    return opcao;
}

void add_nome_jogadores(int quantidade_jogadores, tp_fila *fila_jogadores){
    jogador jogador_dados;

    for(int i = 1; i < quantidade_jogadores; i++){
        //Atribuindo o id do jogador
        jogador_dados.id_do_jogador = i;

        //Recebendo o nome do jogador
        printf("\n Digite o nome do jogador: ");
        scanf("%s", jogador_dados.nome);
        insere_fila(fila_jogadores, jogador_dados);
        fflush(stdin);
    }

    //Imprimindo mensagem de sucesso
    printf("Jogadores cadastrados com sucesso!\n");
    }

int menu_de_jogada(jogador *jogador_vez[]){
    int opcao = 0;

    // Mostrando o jogador da vez
    printf("Vez do jogador %s\n", jogador_vez[0]->nome);

    // Mostrando as opções de jogada
    printf("Escolha uma opcao abaixo:\n");
    printf("1 - Mesa do Domino\n");
    printf("2 - Ver suas pecas\n");
    printf("3 - Comprar peca\n");
    printf("4 - Jogar\n");
    
    scanf("%d", &opcao);
    return opcao;
}

#endif
