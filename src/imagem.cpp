#include "imagem.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

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

	arquivoFile.open(camArquivo,ios::in);
}


void Imagem::lerArquivo(){

	string inicioCrip,tamCrip,cifra,tipo,largura,altura,maxCor;
	char comentario,copia[10000000];
	int i=1;

	getline(arquivoFile,tipo,'\n');
	arquivoFile.get(comentario);
	getline(arquivoFile,inicioCrip,' ');
	getline(arquivoFile,tamCrip,' ');
	getline(arquivoFile,cifra,'\n');

	getline(arquivoFile,largura,' ');
	getline(arquivoFile,altura,'\n');
	getline(arquivoFile,maxCor,'\n');

	ofstream arquivoSaida;
	arquivoSaida.open("./imagens/jose.pgm",ios::out);

	ofstream arquivoDaCrip;
	arquivoDaCrip.open("./imagens/crip.txt",ios::out);

	arquivoSaida << tipo << endl;
	arquivoSaida << comentario << inicioCrip << " " << tamCrip << " " << cifra << endl;
	arquivoSaida << largura << " " << altura << endl << maxCor << endl;

	int inicioCripInt = stoi(inicioCrip);
	int tamCripInt = stoi(tamCrip);
	int cifraInt = stoi(cifra);

	while(!arquivoFile.eof()){
		
		arquivoFile.get(copia[i]);
		arquivoSaida << (copia[i]);
		
		i++;
		
	}
	cout << endl;
	int j;
	for(j=(inicioCripInt+1);j <=(inicioCripInt+tamCripInt); j++){
		arquivoDaCrip << (copia[j]+cifraInt) << " ";
	}

}



