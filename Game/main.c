/*
	Projeto: Jogo de dominó
	Matéria: Algoritmo e Estrutura de Dados
	Docente: Marcio Soussa
	Dicentes:
	-> Rodrigo de Jesus Macêdo
	-> Andre Lucas do Nascimento dos Santos
*/


#include "control.h"
#include "model.h"

int main() {
    tp_pilha pecas;
    tp_fila jogadores;
	tp_listad *mesa;
	mesa = inicializa_listad();
	
	// Logo do jogo
	logo();

    //Menu do jogo
	while(1){
		switch (menu())
		{
		case 1:
            // Inicializando o jogo
			configuracao_inicial(&pecas, &jogadores);
			// Jogo
            jogo(&jogadores, mesa, &pecas);
			break;
		case 2:
			// Mostra as regras do jogo
			regras_do_jogo();
			break;
		case 3:
			// Fecha o jogo
			fechar_jogo();
			break;
		default:
			printf("Opcao invalida, tente novamente!\n");
			Sleep(2000);
			system("cls");
			break;
		}
	}
}