#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <iostream>
#include <string>

class UserInterface{

public:
	UserInterface();
	~UserInterface();

	void printarBoasVindas();
	void printarMenu();
	void printarFinalizacao();
	void printarErroDeOpcao();
	void printarDesejaContinuar();
	void printarDecisaoPraSair();
	void cabecalhoDaMensagem();
	void cabecalhoDoCaminho();
};

#endif