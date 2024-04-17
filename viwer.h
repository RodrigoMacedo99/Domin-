#ifndef _VIWER_H_
#define _VIWER_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "pilha.h"
#include "fila.h"
#include "lista_de.h"
#include "model.h"


int introducao(){

    int opcao;
    while(1){
        printf("\n<=======>BEM VINDO AO JOGO DE DOMINO <=======>\n\n");
        printf("Selecione a quantidade de jogadores: [2] [4]\n");
        printf("> ");
        scanf("%d", &opcao);
        if(opcao == 2 || opcao == 4){
            break;
        }else{  
            printf("\n\nOpcao invalida, tente novamente!\n\n");
            Sleep(1000);
            system("cls");
        }
    }
	system("cls");
	
    return opcao;
}

void inicializar_jogadores (tp_fila *fila_jogadores, int quantidade_jogadores){

    jogador jogadores;
    for(int i = 1; i <= quantidade_jogadores; i++){        
        //Atribuindo o id do jogador
        jogadores.id_do_jogador = i;

        //Recebendo o nome do jogador
        fila_jogadores->item[i].mao = inicializa_listad();
        printf("\n Digite o nome do jogador %d: ", jogadores.id_do_jogador);
        scanf("%s", jogadores.nome);
        insere_fila(fila_jogadores, jogadores);
        fflush(stdin);
    }
    printf("\n\nJogadores cadastrados com sucesso!\n\n");
    
	Sleep(1000);
	system("cls");
}

#endif
