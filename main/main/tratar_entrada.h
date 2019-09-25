// main.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "lista.h"

std::list<int> listaRecipientes;
std::list<int> listaResultados;
std::list<int> listaAuxiliar;


Lista _listaRecipientes;
Lista _listaResultados;
Lista _listaAuxiliar;



void inicializarListas() {
	inicia(&_listaRecipientes);
	inicia(&_listaResultados);
	inicia(&_listaAuxiliar);
}


bool verificaElementoJaExisteNaLista(int elemento) {
	/*No *no;
	no = _listaResultados.inicio;
	while (no->prox != NULL) {
		if (no->valor == elemento) {
			return true;
		}
		else {
			no = no->prox;
		}
	}

	return false;*/

	std::list<int>::iterator it;
	it = std::find(listaResultados.begin(), listaResultados.end(), elemento);
	if (it != listaResultados.end())
		return true;

	return false;
}

void adicionaNovasCombinacoesDeQuantidades() {
	for (int recipiente : listaRecipientes) {
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
	}
}

void tratarEntrada(int quantidade, char evento) {
	bool parar = false;
	int numeroOperacoes = 1;
	switch (evento)
	{
	case 'i':
		printf("\n Inclusão\n");
		listaRecipientes.push_back(quantidade);
		break;
	case 'p':		
		listaResultados.clear();
		listaAuxiliar.clear();
		listaAuxiliar.push_back(0);
		while (parar == false) {						
			adicionaNovasCombinacoesDeQuantidades();
			if (verificaElementoJaExisteNaLista(quantidade)) {
				printf("O numero de operações necessárias foi: %d", numeroOperacoes);
				parar = true;
			}

			listaAuxiliar = listaResultados;

			numeroOperacoes++;
		}
		
		printf("\n Medir\n");
		break;
	case 'r':
		listaRecipientes.remove(quantidade);
		printf("\n Quebrou\n");
		break;
	default:
		break;
	}
}