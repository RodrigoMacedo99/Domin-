/*
	Projeto: Jogo de dominó
	Matéria: ALgoritmo e Estrutura de Dados
	Docente: Marcio Soussa
	Dicentes:
	-> Rodrigo de Jesus Macêdo
	-> Andre Lucas do Nascimento dos Santos
*/


#include "control.h"
#include "model.h"



int main() {
    tp_pilha pecas;
    tp_fila jogadores;
	tp_listad *mesa = inicializa_listad();

	if(menu() == 1){	
		  // Inicializando o jogo criando as peças de dominó, embaralhando-as e inicializando a mesa e adicionando os jogadores*
    	configuracao_inicial(&pecas, &jogadores);

		imprime_pilha(pecas);
		imprime_fila(jogadores);
	}
	// fazer elif paras as outras opções do menu
  else if(menu() == 2){
      regras_do_jogo();
	  if (regras_do_jogo()== 1){
		  main();

    }
    else if(menu() == 3){
       fechar_programa();
    }
    else{
		printf("Opção inválida, tente novamente!\n");
	}


	return 0;
}