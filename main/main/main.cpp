// main.cpp : Defines the entry point for the application.
//
#include <list>
#include "tratar_entrada.h"

using namespace std;

int main()
{
	int quantidade;
	char evento;
	inicializarListas();
	while (scanf("%d %c", &quantidade, &evento) != EOF) {
		tratarEntrada(quantidade, evento);
	}
	return 0;
}
