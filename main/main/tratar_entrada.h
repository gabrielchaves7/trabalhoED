#pragma once

#include <iostream>
#include "lista.h"

bool verificaElementoJaExisteNaLista(Lista *_lista, int elemento) {	
	No *no;
	no = _lista->inicio;
	while (no != NULL) {
		if (no->valor == elemento) {
			return true;
		}
		else {
			no = no->prox;
		}
	}

	return false;
}

void adicionaNovasCombinacoesDeQuantidades(Lista *_listaRecipientes, Lista *_listaResultados, Lista *_listaAuxiliar) {
	No *noListaRecipientes;
	noListaRecipientes = _listaRecipientes->inicio;

	No *noListaAuxiliar;
	noListaAuxiliar = _listaAuxiliar->inicio;


	while (noListaRecipientes != NULL) {
		while (noListaAuxiliar != NULL) {
			int soma = noListaRecipientes->valor + noListaAuxiliar->valor;
			int subtracao = noListaRecipientes->valor - noListaAuxiliar->valor;
			if (subtracao > 0 && !verificaElementoJaExisteNaLista(_listaResultados, subtracao)) {
				inserirElementoNoFim(_listaResultados, subtracao);
			}

			if (soma > 0 && !verificaElementoJaExisteNaLista(_listaResultados, soma)) {
				inserirElementoNoFim(_listaResultados, soma);
			}

			noListaAuxiliar = noListaAuxiliar->prox;
		}

		noListaAuxiliar = _listaAuxiliar->inicio;

		noListaRecipientes = noListaRecipientes->prox;
	}
}

void tratarEntrada(int quantidade, char evento, Lista *_listaRecipientes, Lista *_listaResultados, Lista *_listaAuxiliar) {
	bool parar = false;
	int numeroOperacoes = 1;
	switch (evento)
	{
	case 'i':
		printf("\n Inclusão\n");
		insereElementoNaLista(_listaRecipientes, quantidade);
		break;
	case 'p':		
		limpaLista(_listaResultados);
		limpaLista(_listaAuxiliar);

		while (parar == false) {					
			adicionaNovasCombinacoesDeQuantidades(_listaRecipientes, _listaResultados, _listaAuxiliar);
			if (verificaElementoJaExisteNaLista(_listaResultados, quantidade)) {
				printf("O numero de operações necessárias foi: %d", numeroOperacoes);
				parar = true;
			}

			_listaAuxiliar = copiarLista(_listaResultados);			
			numeroOperacoes++;
		}
		
		printf("\n Medir\n");
		break;
	case 'r':
		//listaRecipientes.remove(quantidade);
		printf("\n Quebrou\n");
		break;
	default:
		break;
	}
}

