#ifndef CONTROL_C
#define CONTROL_C

#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include <time.h>
#include "pilha.h"
#include "fila.h"
#include "lista_de.h"
#include "viwer.h"

/**
 * Função para criar peças de dominó.
 * Esta função gera peças de dominó aleatórias atribuindo valores aleatórios aos lados esquerdo e direito de cada peça.
 * Também atribui um ID único a cada peça.
 */
void criar_pecas (peca* vetor_pecas[]){
    int i, j;
    srand(time(NULL));

    // Gerando peças de dominó
    for(i = 0; i <= 6; i++ )
        for(j = 0; j <= 6; j++){
        
        peca *p = (peca*) malloc(sizeof(peca));
        p->lado_direito = i;
        p->lado_esquerdo = j;
        p->id_peca = rand() % 1000;
        
        //Atribuindo a peça ao vetor de peças
        vetor_pecas[i*7+j] = p; 
        //printf(" id_peca: %hd\n",  vetor_pecas[i*7+j]->id_peca);
    }
}

/**
 * Função para embaralhar as peças de dominó.
 * Esta função embaralha as peças de dominó de forma aleatória.
 */
void  embaralhar_alg_ord (peca* vetor_pecas[]){
    int i, j, min, tam = 28;
    peca *x;

    for (i=0; i<tam-1; i++){
        min = i;
        for (j=i+1; j<tam; j++){
            if (vetor_pecas[j]->id_peca < vetor_pecas[min]->id_peca)
                min = j;
        }

        //Troca de peças
        x = vetor_pecas[min];
        vetor_pecas[min] = vetor_pecas[i];
        vetor_pecas[i] = x;
    }
}

// Função para inicializar o jogo de dominó
void inicializar_pecas (tp_pilha *pilha_pecas){

    //Alocando memória para o vetor de peças
    peca **vetor_pecas = (peca**) malloc(28 * sizeof(peca*));
    for (int i = 0; i < 28; i++){
        vetor_pecas[i] = malloc(sizeof(peca));
    }

    //Criando e embaralhando as peças
    criar_pecas(vetor_pecas);
    embaralhar_alg_ord(vetor_pecas);
    
    //Empilhando as peças
    for (int i = 0; i < 28; i++){
        push(pilha_pecas, *vetor_pecas[i]);
    }
}
//  libera memoria alocada
/*void libera_memoria(tp_fila *jogadores) {
    item_jogador j;
    while (!fila_vazia(jogadores)) {
        remove_fila(jogadores, &j);
        // Libera a memória para a mão do jogador
        tp_listad *atu = j.mao;
        tp_listad *p;
        while (atu != NULL) {
            p = atu->fim;
            free(atu);
            atu = p;
        }
        // Libera a memória para a estrutura do jogador
        free(j.mao); // assumindo que j.mao foi alocado dinamicamente
    }
}*/

// configuração inicial do jogo
void configuracao_inicial(tp_pilha *pilha_pecas, tp_fila *fila_jogadores) {
    inicializa_pilha(pilha_pecas);
    inicializar_pecas(pilha_pecas);

    inicializa_fila(fila_jogadores);
    inicializar_jogadores(fila_jogadores, introducao());
    item_pilha temp;

	for (int i = 1; i <= tamanho_fila(*fila_jogadores); i++){
        fila_jogadores->item[fila_jogadores->ini].mao = inicializa_listad();
        for(int j = 0; j <= 6; j++){
            pop(pilha_pecas, &temp);
            insere_listad_no_fim(fila_jogadores->item[fila_jogadores->ini].mao, temp);
		}
        printf("Dados de teste\n");
        printf("LISTA %d: \n", i);
        imprime_listad(fila_jogadores->item[fila_jogadores->ini].mao, 1);
    }
    system("pause");
}

void imprime_dados_totais(tp_fila *jogadores){
    int i;
    printf("Entrou.... %x\n", jogadores->ini);
	for (i = 1; i <= tamanho_fila(*jogadores); i++){
        item_jogador j;
        j.mao = inicializa_listad();
        printf("%d || %s: ", i, jogadores->item[jogadores->ini].nome);
        //imprime_listad(jogadores->item[jogadores->ini].mao, 1);
        remove_fila(jogadores, &j);
        insere_fila(jogadores, j);
	}
	
	printf("entrou 2222");
	system("pause");
}

#endif