#ifndef __PECA_H_
#define __PECA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int lado_direito; // Valor de um lado da peça  
    int lado_esquerdo; // Valor do outro lado da peça  
    short int id_peca; // Para poder embaralhar as peças 
    
}peca;

#endif

#ifndef __JOGADOR_H_
#define __JOGADOR_H_

#include "lista_de.h"

typedef struct {
    char nome[50];
    short int id_do_jogador; // Para saber de quem é a peça da lista principal
    tp_listad *mao;// Declare mao aqui
}jogador;

#endif