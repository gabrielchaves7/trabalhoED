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

void insereListaRecipientes(Lista *lista, int valor) {
	if (lista->inicio == NULL) {
		No *no = new No();
		no->valor = valor;
		no->ant = NULL;
		no->prox = lista->fim;
		lista->inicio = no;
	}
	else if (lista->fim == NULL) {
		No *no = new No();
		no->valor = valor;
		no->ant = lista->inicio;
		lista->inicio->prox = no;
		no->prox == NULL;
		lista->fim = no;
	}
	else {
		No *no = new No();
		no->valor = valor;

		lista->fim->prox = no;
		no->ant = lista->fim;
		no->prox = NULL;
		lista->fim = no;
	}
}

void iniciaListaRecipientes(Lista *lista) {
	lista->inicio = lista->fim = NULL;
}

void inicia(Lista *lista) {
	No *noInicio = new No();
	noInicio->valor = 0;
	noInicio->ant = NULL;
	lista->fim = NULL;
	noInicio->prox = lista->fim;
	lista->inicio = noInicio;
}

void push_back(Lista *lista, int valor) {
	if (lista->fim == NULL) {
		No *no = new No();
		no->valor = valor;
		no->ant = lista->inicio;
		lista->inicio->prox = no;
		no->prox == NULL;
		lista->fim = no;
	}
	else {
		No *no = new No();
		no->valor = valor;

		lista->fim->prox = no;
		no->ant = lista->fim;
		no->prox = NULL;
		lista->fim = no;
	}		
}

void clear(Lista *lista) {
	No *no, *aux;
	no = lista->inicio;
	while (no != NULL)
	{
		aux = no;
		no = no->prox;
		free(aux);
	}
	lista->inicio = NULL;
	lista->fim = NULL;
}

Lista* copiarLista(Lista *lista) {
	Lista *novaLista = new Lista();

	No* noInicio = new No();
	noInicio->valor = lista->inicio->valor;
	noInicio->ant = NULL;
	novaLista->inicio = noInicio;

	No* iterator = lista->inicio->prox;

	while (iterator != NULL) {
		No* novoNo = new No();
		novoNo->valor = iterator->valor;
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
