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
    //free(vetor_pecas);
}

//Separar as peças entre os jogadores
void separa_pecas_jogadores(tp_fila *fila_jogadores, tp_pilha *pilha_pecas){
    peca temp;
    jogador j;
    j.mao = inicializa_listad();

    for (int i = 0; i <= tamanho_fila(*fila_jogadores)-1; i++){
        fila_jogadores->item[i].mao = inicializa_listad();
        for(int j = 0; j <= 6; j++){
            pop(pilha_pecas, &temp);
            insere_listad_no_fim(fila_jogadores->item[i].mao, temp);
        }
    }
}

// Organizar a mão de todos os jogadores de forma crescente
void organizar_pecas_jogador(tp_fila *jogador){
    for(int i = 0; i <= tamanho_fila(*jogador); i++){
        select_sort_lista(jogador->item->mao);
    }
}

// Função para imprimir a mesa
void print_mao_jogadores(tp_fila *fila_jogadores) {
    int numero_de_jogadores = tamanho_fila(*fila_jogadores);
    for (int i = 0; i < numero_de_jogadores; i++) {
        printf("Jogador %d:\n", i+1 );
        tp_listad *mao = fila_jogadores->item[i].mao;
        tp_no *atual = mao->ini;
        while (atual != NULL) {
            printf("Peca: %d|%d\n", atual->info.lado_esquerdo, atual->info.lado_direito);
            atual = atual->prox;
        }
        printf("\n");
    }
}

// Função para imprimir a mesa
void printar_mao_jogador(tp_fila *jogador, int vez) {
    tp_listad *mao = jogador->item[vez].mao;
    tp_no *atu = mao->ini;

    // Imprime o nome do jogador
    printf("=========== Mao de %s ============\n", jogador->item[vez].nome);
    
    // Imprime as peças com os lados
    printf("Pecas:");
    while (atu != NULL) {
        printf("[%d:%d] ", atu->info.lado_esquerdo, atu->info.lado_direito);
        atu = atu->prox;
    }
    printf("\n");
    
    // Resetando o nó para o início da lista
    atu = mao->ini;
    
    // Imprime os IDs das peças
    printf("  ID: ");
    while (atu != NULL) {
        printf("[ %d ]", atu->info.id_peca);
        atu = atu->prox;
    }
    printf("\n");
}

//Função para jogar uma peça
/*void jogar_peca(tp_fila *jogador, tp_listad *mesa, int vez){
    peca p;
    remover_listad(jogador->item[vez].mao, p);

    if (p.lado_direito ==  mesa->fim->info.lado_esquerdo){
        insere_listad_no_fim(mesa, p);
    }else if (p.lado_esquerdo ==  mesa->ini->info.lado_direito){
        insere_listad_no_inicio(mesa, p);
    }
}*/

/*void rodada_de_jogadores(tp_fila *fila_jogadores, tp_listad *mesa){
    int numero_de_jogadores = tamanho_fila(*fila_jogadores);
    for (int vez = 0; vez < numero_de_jogadores; vez++){
        jogar_peca(fila_jogadores, mesa, vez);
    }
}
*/

// Função para buscar peça
peca buscar_peca(tp_listad *mao, short int id_peca){
    peca p;
    p.id_peca = id_peca;
    return busca_listade(mao, p)->info;
}

// Função para verificar se o jogador pode jogar
int permissao_de_jogada(tp_listad* mao, tp_listad mesa, short int id_peca){
    peca aux;

    //Encontrando os dados da peça relacionada ao id recebido
    /*aux = buscar_peca(&mao, id_peca);
    if(aux.lado_direito == NULL || aux.lado_esquerdo == NULL){
        mao = inicializa_listad();
    }*/


   // printf("[%d:%d]\n", aux.lado_esquerdo, aux.lado_direito);

    //Se for a primeira jogada
    if(listad_vazia(&mesa)){
        printf("Esta e a primeira jogada!\n");
        Sleep(2000);
        system("cls");
        return 0;
    }

    //Analise das jogadas seguintes a primeira
    if (aux.lado_esquerdo  ==  mesa.ini->info.lado_esquerdo || aux.lado_esquerdo ==  mesa.fim->info.lado_direito){
        printf("teste 1\n");
        Sleep(2000);
        system("cls");
        return 0;
    } else if(aux.lado_direito == mesa.ini->info.lado_esquerdo || aux.lado_direito == mesa.fim->info.lado_direito){
        printf("teste 2\n");
        Sleep(2000);
        system("cls");
        return 0;
    }else {
        printf("Peca incopatível");
        Sleep(2000);
        system("cls");
        return 1;
    }
}

// Tirar da mão e coloca na mesa
int mao_para_mesa (tp_listad *mao, tp_listad *mesa, int posicao_peca, short int id_peca){
    peca p;
    p.id_peca = id_peca;

    system("pause");
    system("cls");

    //Se a jogada for permitida, a peça será realocada da mao para a mesa
    if(permissao_de_jogada(mao, *mesa, id_peca) == 0){
        if(posicao_peca == 2){
            insere_listad_no_fim(mesa, remove_listad_id(mao, busca_listade(mao, p)->info));
            return 0;
        } else if (posicao_peca == 1){
            insere_listad_no_ini(mesa, remove_listad_id(mao, busca_listade(mao, p)->info));
            return 0;
        }
        system("pause");
    }
    return 1;
}

// Função para comprar peça
void comprar_peca(tp_pilha *cava, tp_listad *mao){
    peca p;
    pop(cava, &p);
    insere_listad_no_fim(mao, p);
}

// configuração inicial do jogo
void configuracao_inicial(tp_pilha *pilha_pecas, tp_fila *fila_jogadores) {
    inicializa_pilha(pilha_pecas);
    inicializa_fila(fila_jogadores);
    inicializar_pecas(pilha_pecas);
    inicializar_jogadores(fila_jogadores, introducao());
    separa_pecas_jogadores(fila_jogadores, pilha_pecas);
    //organizar_pecas_jogador(fila_jogadores);
}

// Função para jogar o jogo
void jogo(tp_fila *jogadores, tp_listad *mesa, tp_pilha *cava){
    int vez = 0;  // fazer função para avaliar quem será o primeiro jogaodor e igualar a variavel 'vez' ++++++++++++++++++++++++++++++++
    int opcao; // variavel para armazenar a opção do menu
    short int id_peca; // variavel para armazenar o id da peça
    int posicao_peca, verificar_jogada; // variavel para armazenar a posição da peça e verificar se a jogada foi feita com sucesso

    // Verificar se a mesa está vazia
    if(mesa->ini != NULL || mesa->fim != NULL){
        mesa = inicializa_listad();
    }


    // add função para verificar se o jogo finalizou e colocar no while +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // cental do jogo, onde acontece todas as ações do jogo
    while(1){
            do{
                switch (menu_de_jogadas()){
                    case 1:
                        // printar mesa
                        print_mesa(mesa);
                        printf("\n\n\n\n\n\n\n");
                        system("pause");
                        system("cls");            
                        break;
                    case 2:
                        // printar mão do jogador
                        printar_mao_jogador(jogadores, vez);
                        printf("\n\n\n\n\n\n\n");
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        // comprar peça
                        comprar_peca(cava, jogadores->item[vez].mao);
                        printar_mao_jogador(jogadores, vez);
                        printf("\n\n\n\n\n\n\n");
                        system("pause");
                        system("cls");            
                        break;
                    case 4:
                        // jogar peça
                        system("cls");
                        print_mesa(mesa);
                        printf("\n");
                        printar_mao_jogador(jogadores, vez);
                        escolher_peca(&id_peca);
                        posicao_peca_mesa(&posicao_peca);
                        verificar_jogada = mao_para_mesa(jogadores->item[vez].mao, mesa, posicao_peca, id_peca);
                        system("cls");
                        break;
                    case 5:
                        // sair para o menu principal
                        return;
                        break;
                    default:
                        // caso a opção seja inválida
                        printf("Opcao invalida, tente novamente! [1, 2, 3, 4 ou 5]\n");
                        Sleep(2000);
                        system("cls");
                        break;
                }
            }while(verificar_jogada != 0 || permissao_de_jogada(jogadores->item[vez].mao, *mesa, id_peca) != 0);  // verificar se a jogada foi feita com sucesso
        
        // muda a vez do jogador para o proximo
        vez++;
        if(vez == tamanho_fila(*jogadores))
            vez = 0;
        
    }
}

#endif