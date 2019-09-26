// main.cpp : Defines the entry point for the application.
//
#include <list>
#include "tratar_entrada.h"

using namespace std;

int main()
{
	int quantidade;
	char evento;
	Lista *_listaRecipientes = new Lista();
	Lista *_listaResultados = new Lista();;
	Lista *_listaAuxiliar = new Lista();;
	iniciaListaRecipientes(_listaRecipientes);
	iniciaLista(_listaResultados);
	iniciaLista(_listaAuxiliar);

	while (scanf("%d %c", &quantidade, &evento) != EOF) {
		tratarEntrada(quantidade, evento, _listaRecipientes, _listaResultados, _listaAuxiliar);
	}
	return 0;
}
