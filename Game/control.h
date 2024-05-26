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
void criar_pecas(peca vetor_pecas[]) {
    int i, j, k = 0;

    // Gerando peças de dominó
    for (i = 0; i <= 6; i++) {
        for (j = i; j <= 6; j++) {
            vetor_pecas[k].id_peca = k;
            vetor_pecas[k].lado_esquerdo = i;
            vetor_pecas[k].lado_direito = j;
            k++;
        }
    }
}

// Função para embaralhar as peças
void embaralha(peca vetor_pecas[]) {
    for (int i = 0; i < 28; i++) {
        int j = rand() % 28;
        // Swap para a permutação dos elementos
        peca temp = vetor_pecas[i];
        vetor_pecas[i] = vetor_pecas[j];
        vetor_pecas[j] = temp;
    }
}

// Função para inicializar o jogo de dominó
void inicializar_pecas(tp_pilha *pilha_pecas) {
    // Criando e embaralhando as peças
    peca vetor_pecas[28];
    criar_pecas(vetor_pecas);
    embaralha(vetor_pecas);

    // Empilhando as peças
    for (int i = 0; i < 28; i++) {
        push(pilha_pecas, vetor_pecas[i]);
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

// Função para imprimir a mesa do jogador
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
        printf("[%d:%d]", atu->info.lado_esquerdo, atu->info.lado_direito);
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

// Função para imprimir a mesa
void alterar_id_peca(tp_listad *mao) {
    tp_no *aux;
    int id = 1;
    for (aux = mao->ini; aux != NULL; aux = aux->prox) {
        aux->info.id_peca = id;
        id++;
    } 
}

// Organizar a mão de todos os jogadores de forma crescente
void organizar_pecas_jogador(tp_fila *jogador){
    for(int i = 0; i <= tamanho_fila(*jogador)-1; i++){
        select_sort_lista(jogador->item[i].mao);
        alterar_id_peca(jogador->item[i].mao);
        //printar_mao_jogador(jogador, i);
    }
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

void inverte_peca(peca *p, tp_listad *mesa){
    if(mesa->ini->info.lado_esquerdo == p->lado_esquerdo || mesa->ini->info.lado_direito == p->lado_direito){
        int temp = p->lado_esquerdo;
        p->lado_esquerdo = p->lado_direito;
        p->lado_direito = temp;
    }else if(mesa->ini->info.lado_esquerdo == p->lado_esquerdo || mesa->ini->info.lado_direito == p->lado_direito) {
        return inverte_peca(p, mesa); // recursão para garantir que a peça seja invertida em caso de bug
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

    // Busca a peça na mão pelo id
    p = buscar_peca(mao, id_peca);

    // Inverte a peça se necessário
    if(!listad_vazia(mesa)){
        inverte_peca(&p, mesa);
    }

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
    if(pilha_vazia(cava)){
        printf("Cava vazia\n");
        return 1;
    }
    pop(cava, &p);
    insere_listad_no_fim(mao, p);
    return 0;
}

int verificar_jogo(tp_listad *mao){
    if(listad_vazia(mao)){
        return 1;
    }
    return 0;
}

// configuração inicial do jogo
void configuracao_inicial(tp_pilha *pilha_pecas, tp_fila *fila_jogadores) {
    inicializa_pilha(pilha_pecas);
    inicializa_fila(fila_jogadores);
    inicializar_pecas(pilha_pecas);
    inicializar_jogadores(fila_jogadores, introducao());
    separa_pecas_jogadores(fila_jogadores, pilha_pecas);
    organizar_pecas_jogador(fila_jogadores);
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
                    
                    // Verifica se id da peça é válido
                    if(escolher_peca(&id_peca) == 0){
                        verificar_jogada = mao_para_mesa(jogadores->item[vez].mao, mesa, id_peca);

                        // Verifica se a peça existe na mão do jogador
                        if (verificar_jogada != 0) {
                            printf("\nJogada invalida\n");
                            Sleep(2000);
                        }
                    }else{
                        verificar_jogada = 1;
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
            
        // Organiza as peças do jogador
        organizar_pecas_jogador(jogadores);

        } while(verificar_jogada != 0);

        // Verifica se o jogo acabou
        if(verificar_jogo(jogadores->item[vez].mao)){
            system("cls");
            printf("                       Parabens %s, voce venceu!\n", jogadores->item[vez].nome);
            venceu();
            Sleep(5000);
            system("cls");
            return;
        };

        // Muda a vez do jogador para o próximo
        vez++;
        if(vez == tamanho_fila(*jogadores)) vez = 0;
    }
}

#endif