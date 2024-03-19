#ifndef __MODEL_H_
#define __MODEL_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int lado_direito; // Valor de um lado da peça  
    int lado_esquerdo; // Valor do outro lado da peça  
    short int id_peca; // Para poder embaralhar as peças 
    short int id_jogador; // Para saber quem é o dono dessa peça  
}peca;

typedef struct {
    char nome[50];
    short int id_jogador_2; // Para saber de quem é a peça da lista princiapal 
    //peca mao[7]; //substituir por lista encadeada ou usar a comparação de id's
}jogador;

#endif