#ifndef __PECA_H_
#define __PECA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int lado_direito; // Valor do lado direito da peça
    int lado_esquerdo; // Valor do lado esquerdo da peça 
    short int id_peca; // Para poder embaralhar as peças 
    
}peca;

#endif

#ifndef __JOGADOR_H_
#define __JOGADOR_H_

#include "lista_de.h"

typedef struct {
    char nome[50]; //Nome do jogador
    short int id_do_jogador; //id da peça
    tp_listad *mao; //Lista duplamaente encadeada para colocar a mao dos jogadores
}jogador;

#endif