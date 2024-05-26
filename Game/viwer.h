#ifndef _VIWER_H_
#define _VIWER_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "pilha.h"
#include "fila.h"
#include "lista_de.h"
#include "model.h"

//Função de inicialização  retorna a quantidade de jogadores
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
 
// Função para inicializar os jogadores
void inicializar_jogadores (tp_fila *fila_jogadores, int quantidade_jogadores){

    jogador jogadores;

    for(int i = 1; i <= quantidade_jogadores; i++){
        //Atribuindo o id do jogador
        jogadores.id_do_jogador = i;

        //Recebendo o nome do jogador
        printf("\n Digite o nome do jogador %d: ", i);
        scanf("%s", jogadores.nome);
        insere_fila(fila_jogadores, jogadores);
    }
    printf("\n\nJogadores cadastrados com sucesso!\n\n");
    Sleep(2000);
    system("cls");
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

//Função para mostrar as regras do jogo
int regras_do_jogo(){
    int opcao ;
    printf("============================================> REGRAS DO JOGO <============================================\n");
    printf("| 1. O jogo de domino e jogado por 2 a 4 jogadores.                                                      |\n");
    printf("| 2. Cada jogador recebe 7 pecas.                                                                        |\n");
    printf("| 3. O jogador que tiver a peca dupla seis comeca o jogo.                                                |\n");
    printf("| 4. O jogador seguinte deve jogar uma peca que tenha um dos lados igual ao da peca que esta na mesa.    |\n");
    printf("| 5. Se um jogador nao tiver uma peca para jogar, ele deve comprar uma peca do monte.                    |\n");
    printf("| 6. O jogo termina quando um jogador coloca todas as suas pecas na mesa ou quando o jogo fica bloqueado.|\n");
    printf("==========================================================================================================\n\n");
    printf("Deseja voltar ao menu principal? [1] sim [2] nao\n");
    scanf("%d", &opcao);

    if(opcao == 1){
        system("cls");
        return 1;
        }else if(opcao == 2){
            system("cls");
            regras_do_jogo();
        }else if (opcao != 1 || opcao != 2){
            system("cls"); 
            printf("Opcao invalida, tente novamente!\n");
            regras_do_jogo();
        }
}

// Função para mostrar a mão do jogador
void print_mesa(tp_listad *mao){
    printf("=============== Mesa ================\n");
    imprime_listad(mao, 1);
}

//  Função para escolher a peça que deseja jogar
int escolher_peca(short int *id_peca){
    printf("Digite o id da peca que deseja jogar: \n");
    printf("> ");
    scanf("%hd", id_peca);
    if(*id_peca < 0 || *id_peca > 27){
        printf("Opcao invalida, tente novamente!\n");
        Sleep(2000);
        system("cls");
        return 1;
    }
    return 0;
} 

//menu de jogadas// Preciso fazer a entrada que dei com os nomes dos jogadores como entrada para essa função
int menu_de_jogadas(){
    int opcao = 0;

    printf("======> ESCOLHA UMA DAS OPCOES ABAIXO <======\n");
    printf("|            1 - Mesa do Domino              |\n");
    printf("|            2 - Ver suas pecas              |\n");
    printf("|             3 - Comprar peca               |\n");
    printf("|                4 - Jogar                   |\n");
    printf("|      5 - Sair|Voltar ao Menu Principal     |\n");
    printf("=============================================\n");
    printf("> ");
    
    scanf("%d", &opcao);
    system("cls");
    return opcao;
    // e utlizar essa função como entrada para a função de jogar_peca, Mostrar mesa ,comprar peca ver mao e jogar 
}

// inicialização do jogo
void logo(){
    printf("Projeto: Jogo de domino\n");
    printf("Materia: Algoritmo e Estrutura de Dados\n");
    printf("Docente: Marcio Soussa\n");
    printf("Dicentes:\n");
    printf("-> Rodrigo de Jesus Macedo\n");
    printf("-> Andre Lucas do Nascimento dos Santos\n");

    //logo do jogo em ascii
    printf(" .----------------.  .----------------.  .----------------.  .----------------.  .-----------------. .----------------. \n");  
    printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");  
    printf("| |  ________    | || |     ____     | || | ____    ____ | || |     _____    | || | ____  _____  | || |     ____     | |\n");  
    printf("| | |_   ___ `.  | || |   .'    `.   | || ||_   \\  /   _|| || |    |_   _|   | || ||_   \\|_   _| | || |   .'    `.   | |\n");  
    printf("| |   | |   `. \\ | || |  /  .--.  \\  | || |  |   \\/   |  | || |      | |     | || |  |   \\ | |   | || |  /  .--.  \\  | |\n");  
    printf("| |   | |    | | | || |  | |    | |  | || |  | |\\  /| |  | || |      | |     | || |  | |\\ \\| |   | || |  | |    | |  | |\n");  
    printf("| |  _| |___.' / | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |     _| |_    | || | _| |_\\   |_  | || |  \\  `--'  /  | |\n");  
    printf("| | |________.'  | || |   `.____.'   | || ||_____||_____|| || |    |_____|   | || ||_____||\\____| | || |   `.____.'   | |\n");  
    printf("| |              | || |              | || |              | || |              | || |              | || |              | |\n");  
    printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");  
    printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");  

    Sleep(5000);
    system("color 0A");
    system("cls");
    system("cls");
}

// Menssagem ao fechar jogo
void fechar_jogo(){
	printf("                                               Obrigado por jogar!\n");
	printf("                                     Espero que joguemos outra partida no futuro\n");

    printf(" .----------------.  .----------------.  .----------------.  .----------------.  .-----------------. .----------------. \n");  
    printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");  
    printf("| |  ________    | || |     ____     | || | ____    ____ | || |     _____    | || | ____  _____  | || |     ____     | |\n");  
    printf("| | |_   ___ `.  | || |   .'    `.   | || ||_   \\  /   _|| || |    |_   _|   | || ||_   \\|_   _| | || |   .'    `.   | |\n");  
    printf("| |   | |   `. \\ | || |  /  .--.  \\  | || |  |   \\/   |  | || |      | |     | || |  |   \\ | |   | || |  /  .--.  \\  | |\n");  
    printf("| |   | |    | | | || |  | |    | |  | || |  | |\\  /| |  | || |      | |     | || |  | |\\ \\| |   | || |  | |    | |  | |\n");  
    printf("| |  _| |___.' / | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |     _| |_    | || | _| |_\\   |_  | || |  \\  `--'  /  | |\n");  
    printf("| | |________.'  | || |   `.____.'   | || ||_____||_____|| || |    |_____|   | || ||_____||\\____| | || |   `.____.'   | |\n");  
    printf("| |              | || |              | || |              | || |              | || |              | || |              | |\n");  
    printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");  
    printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");  

	exit(0);
}


void venceu(){

    printf("                                                                                \n");
    printf("                                                                                \n");
    printf("              ..:::.                                        .::::.              \n");
    printf("            :~!~~~!7!:                                    .~!!~!!77~.           \n");
    printf("          .!7!:.   :7?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7?7!7:    .~??.          \n");
    printf("          ~?7       ^~!7~^^~!7777777777777777777777777!7J7^^       ~?7          \n");
    printf("          ~?!         ^7~^^^!!!!!!!!!!!!!!!!!!!!!!!!!!!?J!         ^?7          \n");
    printf("          .!?^        ^7!^^^!!!!!!!!!!!!!!!!!!!!!!!!!!!?J~        :7?:          \n");
    printf("           .!?!:      :7!^^^!!!!!!!!!!!!!!!!!!!!!!!!!!!?J^      .~??:           \n");
    printf("             ^!7!:    .!!~^^~7!!!!!!!!!!!!!!!!!!!!!!!!7JJ.    :~77~.            \n");
    printf("               :~77~:  ~7!^^~!!!!!!!!!!!!!!!!!!!!!!!!!?J!  .^!7!^.              \n");
    printf("                 .^!7!^:!!~^^!!!!!!!!!!!!!!!!!!!!!!!!7JJ::!77~:                 \n");
    printf("                    :~77!7!^^~7!!!!!!!!!!!!!!!!!!!!!!?J7!?!:                    \n");
    printf("                      ^7?!7!^^!!!!!!!!!!!!!!!!!!!!!!?J?7J~                      \n");
    printf("                   .~!!7!.~7~^~!!!!!!!!!!!!!!!!!!!!?J7.^7!!7.                   \n");
    printf("                    .::.   ~7!^~!!!!!!!!!!!!!!!!!7JJ!.  .:::                    \n");
    printf("                            :!7~~!!!!!!!!!!!!!!7?J?^                            \n");
    printf("                             .^!777!!!!!!!!77?JJ?~.                             \n");
    printf("                                :~7????????JJ?~:                                \n");
    printf("                                  :7???????JJ:                                  \n");
    printf("                                   .~77777?!.                                   \n");
    printf("                                    .????JJ.                                    \n");
    printf("                                    ^7!!!7J!                                    \n");
    printf("                                   :!!!!!!7J:                                   \n");
    printf("                                  :!~!!!!!!7?^                                  \n");
    printf("                                .~!^^!7!!!!!7?!:                                \n");
    printf("                              ^~!~~~~!!!!!!!!!777~                              \n");
    printf("                           7??Y555555555555555555PJY7                           \n");
    printf("                          .PPGGPPPPPPPPPPPPPPPGGGBB#5                           \n");
    printf("                          .PGBP!^~~!!!!!!!!!!7JJJGG#5                           \n");
    printf("                          .PBBP!~!!!!!!!!!!77?JJJGG#5                           \n");
    printf("                          .PBBP777777777??JJJJJJYGG#5                           \n");
    printf("                           PBGGGPPGGGGGGGGGGGGGGGGG#5                           \n");
    printf("                        .?JGBBBBBBBBBBBBBBBBBBBBBBB#G?7                         \n");
    printf("                      . ^GGGGGGGGGGGGGGGGGGGGGGGGGGGGBG. .                      \n");
    printf("                     ......................................                     \n");
    printf("                                                                                \n");
    printf("                                                                                \n");
}
#endif