// main.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

std::list<int> listaRecipientes;

void tratarEntrada(int quantidade, char evento) {
	switch (evento)
	{
	case 'i':
		printf("\n Inclusão\n");
		listaRecipientes.push_back(quantidade);
		break;
	case 'p':
		for (int val : listaRecipientes)
			std::cout << val << ",";
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