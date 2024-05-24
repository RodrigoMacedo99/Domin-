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


// Função para imprimir a mesa
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

// Função para embaralhar as peças
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

//Separar as peças entre os jogadores
void separa_pecas_jogadores(tp_fila *fila_jogadores, tp_pilha *pilha_pecas){
    peca temp;

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
    tp_no *atu = jogador->item[vez].mao->ini;

    if (listad_vazia(jogador->item[vez].mao)) {
        printf("Mao vazia\n");
        return;
    }

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
    atu = jogador->item[vez].mao->ini;

    // Imprime os IDs das peças
    printf("  ID: ");
    while (atu != NULL) {
        printf("[ %d ]", atu->info.id_peca);
        atu = atu->prox;
    }
    printf("\n");
}

// Função para buscar peça
peca buscar_peca(tp_listad *mao, short int id_peca){
    peca p;
    p.id_peca = id_peca;
    return busca_listade(mao, p)->info;
}

// Função para verificar se o jogador pode jogar
int permissao_de_jogada(tp_listad *mao, tp_listad *mesa, short int id_peca){
    peca aux;
    aux = buscar_peca(mao, id_peca);

    //Se for a primeira jogada
    if(listad_vazia(mesa)){
        system("cls");
        return 1;
    }

    //Analise das jogadas seguintes a primeira
    if (aux.lado_esquerdo  ==  mesa->ini->info.lado_esquerdo || aux.lado_direito  ==  mesa->ini->info.lado_esquerdo){
        system("cls");
        return 1;
    } else if(aux.lado_direito == mesa->fim->info.lado_direito || aux.lado_esquerdo == mesa->fim->info.lado_direito){
        system("cls");
        return 2;
    }else {
        system("cls");
        return 0;
    }
}

// Tirar da mão e coloca na mesa
int mao_para_mesa (tp_listad *mao, tp_listad *mesa, short int id_peca){
    peca p;

    // Verifica se a jogada é permitida
    int verificar_jogada = permissao_de_jogada(mao, mesa, id_peca);
    if( verificar_jogada == 0){
        return 1; 
    }

    // Verifica se a peça existe na mão do jogador
    if (busca_listade(mao, p) == NULL) {
        printf("A peca com id %d nao existe na mao.\n", id_peca);
        return 1;
    }

    // Busca a peça na mão pelo id
    p = buscar_peca(mao, id_peca);

    // Insere a peça na mesa
    int resultado_insercao = 1; 
    if(verificar_jogada == 2){
        resultado_insercao = insere_listad_no_fim(mesa, p);
    } else if (verificar_jogada == 1){
        resultado_insercao = insere_listad_no_ini(mesa, p);
    } else if (listad_vazia(mesa)){
        resultado_insercao = insere_listad_no_ini(mesa, p);
    }

    // Verifica se a inserção foi bem sucedida
    if (resultado_insercao != 0) {
        printf("Falha ao inserir a peca na mesa.\n");
        return 1;  
    }

    // Remove a peça da mão após inseri-la na mesa
    if(remove_listad(mao, p) != 0){
        printf("Falha ao remover a peca com id %d da mao.\n", id_peca);
        return 1;  
    }

    // Imprime o estado atual da mesa se a peça foi a primeira inserida
    if (listad_vazia(mesa)){
        imprime_listad(mesa, 1);
    }

    return 0;
}

// Função para comprar peça
int comprar_peca(tp_pilha *cava, tp_listad *mao){
    peca p;
    pop(cava, &p);
    insere_listad_no_fim(mao, p);
    return 0;
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
    int vez = 0;  
    short int id_peca;
    int verificar_jogada; 

    // Verificar se a mesa está vazia e inicializá-la se necessário
    if(mesa->ini != NULL && mesa->fim != NULL){
        mesa = inicializa_listad();
        if (mesa == NULL) {
        }
    }

    // Loop principal do jogo
    while(1){
        do{
            printf("                  [ %s ]\n", jogadores->item[vez].nome);
            switch (menu_de_jogadas()){
                case 1:
                    // Printar mesa
                    print_mesa(mesa);
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    // Printar mão do jogador
                    printar_mao_jogador(jogadores, vez);
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    // Comprar peça
                    if (comprar_peca(cava, jogadores->item[vez].mao) != 0) {
                        printf("Falha ao comprar peça.\n");
                    }
                    print_mesa(mesa);
                    printar_mao_jogador(jogadores, vez);
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    // Jogar peça
                    system("cls");
                    print_mesa(mesa);
                    printar_mao_jogador(jogadores, vez);
                    escolher_peca(&id_peca);
                    verificar_jogada = mao_para_mesa(jogadores->item[vez].mao, mesa, id_peca);
                    if (verificar_jogada != 0) {
                        printf("\nJogada invalida\n");
                        Sleep(2000);
                    }
                    system("cls");
                    break;
                case 5:
                    // Sair para o menu principal
                    return;
                default:
                    // Opção inválida
                    printf("Opcao invalida, tente novamente! [1, 2, 3, 4 ou 5]\n");
                    Sleep(2000);
                    system("cls");
                    break;
            }
        } while(verificar_jogada != 0);

        // Muda a vez do jogador para o próximo
        vez++;
        if(vez == tamanho_fila(*jogadores)) vez = 0;
    }
}

#endif