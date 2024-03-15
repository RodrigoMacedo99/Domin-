#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int lado_direito; // Valor de um lado da peça  
    int lado_esquerdo; // Valor do outro lado da peça  
    short int id_peca; // Para poder embaralhar as peças 
    short int id_jogador; // Para saber quem é o dono dessa peça  
}peca;

void criar_pecas (){
    int i, j;
    peca p;
    srand(time(NULL));

    for(i = 0; i <= 6; i++ )
        for(j = 0; j <= 6; j++){
        p.lado_direito = i;
        p.lado_esquerdo = j;
        p.id_peca = rand() % 100;
        printf("lado esquerdo: %d lado direito: %d id_peça: %hd\n", p.lado_esquerdo, p.lado_direito, p.id_peca);
    }
}

int main (){
    criar_pecas();
    return 0;
}