#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int lado_direito; // Valor de um lado da peça  
    int lado_esquerdo; // Valor do outro lado da peça  
    short int id_peca; // Para poder embaralhar as peças 
    short int id_jogador; // Para saber quem é o dono dessa peça  
}peca;

typedef struct {
    char nome[50];
    short int id_jogador_2; // Para saber de quem é a peça da lista princiapal 
    peca mao[7]; //substituir por lista encadeada ou usar a comparação de id's
}jogador;

/**
 * Função para criar peças de dominó.
 * Esta função gera peças de dominó aleatórias atribuindo valores aleatórios aos lados esquerdo e direito de cada peça.
 * Também atribui um ID único a cada peça.
 */
void criar_pecas (peca *vetor_pecas[]){
    int i, j;
    srand(time(NULL));

    // Gerando peças de dominó
    for(i = 0; i <= 6; i++ )
        for(j = 0; j <= 6; j++){
        
        peca *p = malloc(sizeof(peca)); //Alocando memória para a peça
        p->lado_direito = i;
        p->lado_esquerdo = j;
        p->id_peca = rand() % 100;

        //Atribuindo a peça ao vetor de peças
        vetor_pecas[i*7+j] = p;
        //printf(" id_peça: %hd\n",  vetor_pecas[i*7+j]->id_peca);
    }
}

/**
 * Função para embaralhar as peças de dominó.
 * Esta função embaralha as peças de dominó de forma aleatória.
 */
void  embaralhar_alg_ord(peca  *vetor_pecas[]){
    int i, j, min, tam = 28;
    peca *x;

    for (i=0; i<tam-1; i++){
        min = i;
        for (j=i+1; j<tam; j++){
            if (vetor_pecas[j]->id_peca < vetor_pecas[min]->id_peca)
                min = j;
        }

        x = vetor_pecas[min];
        vetor_pecas[min] = vetor_pecas[i];
        vetor_pecas[i] = x;
    }
}

int main (){
    peca **vetor_pecas;
    vetor_pecas = malloc(28 * sizeof(peca*));
    for (int i = 0; i < 28; i++){
        vetor_pecas[i] = malloc(sizeof(peca));
    }
    
    criar_pecas(vetor_pecas);
    embaralhar_alg_ord(vetor_pecas);
    
    for (int i = 0; i < 28; i++){
        printf(" id_peça: %hd\n",  vetor_pecas[i]->id_peca);
    }

    return 0;
}