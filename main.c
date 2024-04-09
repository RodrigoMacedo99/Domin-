/*
	Projeto: Jogo de dominó
	Matéria: ALgoritmo e Estrutura de Dados
	Docente: Marcio Soussa
	Dicentes:
	-> Rodrigo de Jesus Macedo
	-> Andre Lucas do Nascimento dos Santos
*/

#include <stdio.h>
#include <stdlib.h>
#include "control.h"
#include "model.h"
#include "pilha.h"


int main() {
    tp_pilha pecas;
    tp_fila jogadores;

    // Inicializando o jogo criando as peças de dominó, embaralhando-as e inicializando a mesa e adicionando os jogadores
    configuracao_inicial(&pecas, &jogadores);
	system("pause");
	printf("\n\n\n Lista de nomes na main:\n\n");
	printf("id| nome");
	printf("\n--+---------");
	imprime_fila(jogadores);
	printf("\n\n\n\nPECAS DO JOGO: ");
	imprime_pilha(pecas);


    return 0;
}
