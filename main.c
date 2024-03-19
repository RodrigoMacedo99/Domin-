#include <stdio.h>
#include <stdlib.h>
#include "control.h"
#include "model.h"
#include "pilha.h"



// Função para inicializar o jogo
void inicializar_jogo();


int main(){
    tp_pilha pilha_pecas;
    inicializa_pilha(&pilha_pecas);
    inicializar_jogo(&pilha_pecas);
    imprime_pilha(pilha_pecas);

    return 0;
}
