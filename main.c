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

	printf("\n\n\n\ Lista de nomes na main:\n");
	printf("id| nome");
	printf("\n--+---------");
	imprime_fila(jogadores);
	
	printf("\n\n\n\nPECAS DO JOGO: ");
	imprime_pilha(pecas);
    return 0;
}
