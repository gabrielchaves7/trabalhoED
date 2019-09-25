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

int inicia(Lista *lista) {
	lista->inicio = lista->fim = NULL;
}


