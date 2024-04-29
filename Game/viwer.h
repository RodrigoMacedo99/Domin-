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
        printf("\n Digite o nome do jogador %d: ", i);
        scanf("%s", jogadores.nome);
        insere_fila(fila_jogadores, jogadores);
        fflush(stdin);
    }
    printf("\n\nJogadores cadastrados com sucesso!\n\n");
}

void jogar_peca(){

}

//Função de controle do jogo
int menu(){

    int opcao = 0;

    printf("======> ESCOLHA UMA DAS OPCOES ABAIXO <=====\n");
    printf("|            1 - Iniciar novo Jogo           |\n");
    printf("|             2 - Regras do Jogo             |\n");
    printf("|              3 - Sair do jogo              |\n");
    printf("=============================================\n");
    printf("> ");

    scanf("%d", &opcao);
    system("cls");
    return opcao;
}

//menu de jogadas
int menu_de_jogadas(char jogador){
    int opcao = 0;

    printf("======> ESCOLHA UMA DAS OPCOES ABAIXO <======\n");
    printf("|            1 - Mesa do Domino              |\n");
    printf("|            2 - Ver suas pecas              |\n");
    printf("|             3 - Comprar peca               |\n");
    printf("|                4 - Jogar                   |\n");
    printf("|        5 - Voltar ao Menu Principal        |\n");
    printf("=============================================\n");
    printf("> ");
    
    system("cls");
    scanf("%d", &opcao);
    return opcao;
}
#endif
