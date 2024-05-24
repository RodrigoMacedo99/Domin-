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
	
	//Logo do jogo
	logo();

    //Menu do jogo
	while(1){
		switch (menu())
		{
		case 1:
            // Inicializando o jogo criando as peças de dominó, embaralhando-as e inicializando a mesa e adicionando os jogadores
			configuracao_inicial(&pecas, &jogadores);
			//imprime_pilha(pecas);
			//printf("mao dos jogadores: \n");
			//imprime_listad(jogadores.item[0].mao, 1);
			//imprime_listad(jogadores.item[1].mao, 2);
			//printf("liata: %d\n", jogadores.item[1].mao->tamanho);
			// Função jogo, o coração do do código 
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