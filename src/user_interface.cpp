#include "user_interface.hpp"
#include <iostream>
#include <string>

using namespace std;

UserInterface::UserInterface(){}

UserInterface::~UserInterface(){}

void UserInterface::printarBoasVindas(){
	cout << "|x|---------------------------------------------|x|" << endl;
	cout << "|x|                Boas Vindas                  |x|" << endl;
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
	cout << endl <<"Isso é tudo pessoal." << endl << endl;
}
void UserInterface::printarErroDeOpcao(){
	cout << "opção inválida" << endl;
}

void UserInterface::printarDesejaContinuar(){
	cout << "Você deseja continuar?<S/n>";
}

void UserInterface::printarDecisaoPraSair(){
	cout << "Deseja mesmo sair?<S/n>";
}

void UserInterface::cabecalhoDaMensagem(){
	cout << endl <<"   Mensagem: ";
}

void UserInterface::cabecalhoDoCaminho(){
	cout <<"   Caminho do arquivo: ";
}