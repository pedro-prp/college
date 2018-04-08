#include "imagem.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Imagem::Imagem(){
	cout << "construtor de Imagem" << endl;
	string arquivo = "";
	string camArquivo = "";
}

Imagem::~Imagem(){
	cout << "Destrutor de Imagem" << endl;
}



void Imagem::setArquivo(string arquivo){
	this->arquivo = arquivo;
	camArquivo = "./imagens/" + arquivo;
}

string Imagem::getArquivo(){
	return this->arquivo;
}

string Imagem::getCamArquivo(){
	return camArquivo;
}



void Imagem::abrirArquivo(){

	arquivoFile.open(camArquivo);
}


void Imagem::lerArquivo(){
	char copia;
	
	while(!arquivoFile.eof()){
		arquivoFile.get(copia);
		cout << copia;
	}
}
