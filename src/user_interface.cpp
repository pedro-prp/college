#include "user_interface.hpp"
#include <iostream>
#include <string>

using namespace std;

UserInterface::UserInterface(){}

UserInterface::~UserInterface(){}

void UserInterface::printarBoasVindas(){
	cout << "|x|---------------------------------------------|x|" << endl;
	cout << "|x|     Boas Vindas ao meu programa fudido      |x|" << endl;
	cout << "|x|---------------------------------------------|x|" << endl;
}

void UserInterface::printarMenu(){
	cout << "|x|             Escolha sua opção               |x|" << endl;
	cout << "|x|                                             |x|" << endl;
	cout << "|x| 1.Descriptografar uma imagem PGM            |x|" << endl;
	cout << "|x| 2.Descriptografar uma imagem PPM            |x|" << endl;
	cout << "|x| 3.Sair                                      |x|" << endl;
	cout << "|x|_____________________________________________|x|" << endl;
	cout << "   opção:";
}

void UserInterface::printarFinalizacao(){
	cout << "Tchau Amiguinho" << endl;
}
void UserInterface::printarErroDeOpcao(){
	cout << "Tu errou coleguinha" << endl;
}

void UserInterface::printarDesejaContinuar(){
	cout << "Você deseja continuar?<S/n>";
}

void UserInterface::printarDecisaoPraSair(){
	cout << "Deseja mesmo sair?<S/n>";
}