// main.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "lista.h"

//std::list<int> listaRecipientes;
//std::list<int> listaResultados;
//std::list<int> listaAuxiliar;

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

	/*std::list<int>::iterator it;
	it = std::find(listaResultados.begin(), listaResultados.end(), elemento);
	if (it != listaResultados.end())
		return true;

	return false;*/
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
				push_back(_listaResultados, subtracao);
			}

			if (soma > 0 && !verificaElementoJaExisteNaLista(_listaResultados, soma)) {
				push_back(_listaResultados, soma);
			}

			noListaAuxiliar = noListaAuxiliar->prox;
		}

		noListaAuxiliar = _listaAuxiliar->inicio;

		noListaRecipientes = noListaRecipientes->prox;
	}

	/*for (int recipiente : listaRecipientes) {
		for (int recipientesFormado : listaAuxiliar) {
			int soma = recipiente + recipientesFormado;
			int subtracao = recipiente - recipientesFormado;
			if (subtracao > 0 && !verificaElementoJaExisteNaLista(subtracao)) {
				listaResultados.push_back(subtracao);
			}

			if (soma > 0 && !verificaElementoJaExisteNaLista(soma)) {
				listaResultados.push_back(soma);
			}
		}
	}*/
}

void tratarEntrada(int quantidade, char evento, Lista *_listaRecipientes, Lista *_listaResultados, Lista *_listaAuxiliar) {
	bool parar = false;
	int numeroOperacoes = 1;
	switch (evento)
	{
	case 'i':
		printf("\n Inclusão\n");
		insereListaRecipientes(_listaRecipientes, quantidade);
		//listaRecipientes.push_back(quantidade);
		break;
	case 'p':		
		/*listaResultados.clear();
		listaAuxiliar.clear();
		listaAuxiliar.push_back(0);*/
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

