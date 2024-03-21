#ifndef CONTROL_C
#define CONTROL_C

#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include <time.h>
#include "pilha.h"
#include "fila.h"
#include "viwer.h"


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
        p->id_peca = rand() % 1000;

        //Atribuindo a peça ao vetor de peças
        vetor_pecas[i*7+j] = p;
        //printf(" id_peça: %hd\n",  vetor_pecas[i*7+j]->id_peca);
    }
}

/**
 * Função para embaralhar as peças de dominó.
 * Esta função embaralha as peças de dominó de forma aleatória.
 */
void  embaralhar_alg_ord (peca  *vetor_pecas[]){
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

// Função para inicializar o jogo de dominó
void inicializar_mesa (tp_pilha *pilha_pecas){
   
    //Alocando memória para o vetor de peças
    peca **vetor_pecas = NULL;
    vetor_pecas = malloc(28 * sizeof(peca*));
    for (int i = 0; i < 28; i++){
        vetor_pecas[i] = malloc(sizeof(peca));
    }
    
    //Criando e embaralhando as peças
    criar_pecas(vetor_pecas);
    embaralhar_alg_ord(vetor_pecas);
    
    //Empilhando as peças
    for (int i = 0; i < 28; i++){
        push(pilha_pecas, *vetor_pecas[i]);
        //printf(" id_peça: %hd\n",  vetor_pecas[i]->id_peca);
        fflush(stdin);
    }

    free(vetor_pecas);
}

void inicializar_jogadores (tp_fila *fila_jogadores, int quantidade_jogadores){

    jogador jogadores;

    for(int i = 1; i <= quantidade_jogadores; i++){        
        //Atribuindo o id do jogador
        jogadores.id_do_jogador = i;

        //Recebendo o nome do jogador
        printf("\n Digite o nome do jogador %d: ", jogadores.id_do_jogador);
        scanf("%s", jogadores.nome);
        int o = insere_fila(fila_jogadores, jogadores);
        printf("\n %d", o);
        fflush(stdin);
    }
}

// Função para centralizar o jogo
 void configuracao_inicial (){

    tp_pilha pilha_pecas;
    inicializa_pilha(&pilha_pecas);
    inicializar_mesa(&pilha_pecas);
    imprime_pilha(pilha_pecas);
    printf("\n primeiro \n");
    fflush(stdin);

    
    tp_fila fila_jogadores;
    printf("\n segundo \n");
    
    inicializa_fila(&fila_jogadores);
    //inicializar_jogadores(&fila_jogadores,  introducao());
    add_nome_jogadores(introducao(), &fila_jogadores);
    printf("\n terceiro \n");
    imprime_fila(fila_jogadores);
 }
#endif