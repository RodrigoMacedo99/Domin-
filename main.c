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

    return 0;
}
