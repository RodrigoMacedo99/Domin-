/*
	Projeto: Jogo de dominó
	Matéria: ALgoritmo e Estrutura de Dados
	Docente: Marcio Soussa
	Dicentes:
	-> Rodrigo de Jesus Macedo
	-> Andre Lucas do Nascimento dos Santos
*/


#include "control.h"
#include "model.h"

int main() {
    tp_pilha pecas;
    tp_fila jogadores;
	tp_listad *mesa = inicializa_listad();

    // Inicializando o jogo criando as peças de dominó, embaralhando-as e inicializando a mesa e adicionando os jogadores*
    configuracao_inicial(&pecas, &jogadores);

	imprime_pilha(pecas);
	//imprime_fila(jogadores);

	printf("jogadores %d | %s", jogadores.ini, jogadores.item[0].nome);
	//imprime_listad(jogadores.item[jogadores.ini].mao, 1);
	imprime_dados_totais(&jogadores);

	return 0;
}