#include <iostream>

struct no {
	int valor;
	struct no* ant;
	struct no* prox;
};
typedef struct no No;
struct lista {
	No *inicio, *fim;
};

typedef struct lista Lista;

No* inicializaNovoNo(int valor) {
	No *no = new No();
	no->valor = valor;
	return no;
}

void iniciaListaRecipientes(Lista *lista) {
	lista->inicio = lista->fim = NULL;
}

void iniciaLista(Lista *lista) {
	No *noInicio = inicializaNovoNo(0);
	noInicio->ant = NULL;
	lista->fim = NULL;
	noInicio->prox = lista->fim;
	lista->inicio = noInicio;
}

void limpaLista(Lista *lista) {
	lista->fim = NULL;
	lista->inicio->prox = lista->fim;
}


void inserirElementoNoFim(Lista *lista, int valor) {
	if (lista->fim == NULL) {
		No *no = inicializaNovoNo(valor);
		no->ant = lista->inicio;
		lista->inicio->prox = no;
		no->prox == NULL;
		lista->fim = no;
	}
	else {
		No *no = inicializaNovoNo(valor);

		lista->fim->prox = no;
		no->ant = lista->fim;
		no->prox = NULL;
		lista->fim = no;
	}
}

void insereElementoNaLista(Lista *lista, int valor) {
	if (lista->inicio == NULL) {
		No *no = inicializaNovoNo(valor);
		no->ant = NULL;
		no->prox = lista->fim;
		lista->inicio = no;
	}
	else {
		inserirElementoNoFim(lista, valor);
	}
}

Lista* copiarLista(Lista *lista) {
	Lista *novaLista = new Lista();

	No *noInicio = inicializaNovoNo(lista->inicio->valor);
	noInicio->ant = NULL;
	novaLista->inicio = noInicio;

	No* iterator = lista->inicio->prox;

	while (iterator != NULL) {
		No *novoNo = inicializaNovoNo(iterator->valor);
		novoNo->prox = NULL;

		if (novaLista->fim == NULL) {
			novaLista->fim = novoNo;
			novaLista->inicio->prox = novoNo;
		}
		else {
			novaLista->fim->prox = novoNo;
			novoNo->ant = novaLista->fim;
			novaLista->fim = novoNo;
		}

		iterator = iterator->prox;
	}

	return novaLista;
}
