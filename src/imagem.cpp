#include "imagem.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

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
	char comentario,copiaChar;
	vector<char> copiaVector;
	int i=0;

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
		
		arquivoFile.get(copiaChar);
		copiaVector.push_back(copiaChar);
		arquivoSaida << copiaVector[i];
		
		i++;
		
	}
	cout << endl;
	int j;
	arquivoDaCrip << cifraInt << endl;
	for(j=(inicioCripInt);j<(inicioCripInt+tamCripInt); j++){
		arquivoDaCrip << (copiaVector[j]);
	}
	arquivoFile.close();
	arquivoSaida.close();
	arquivoDaCrip.close();

}

void Imagem::descriptografar(){
	char crip;
	vector<char> cripVector;
	string cifraChar="";
	int cifraInt=0,i=0;
	char semcrip;

	ifstream arquivoDaCrip;
	arquivoDaCrip.open("./imagens/crip.txt");

	ofstream arquivoDescrip;
	arquivoDescrip.open("./imagens/descrip.txt");

	getline(arquivoDaCrip,cifraChar,'\n');
	cifraInt = stoi(cifraChar);

	cout << cifraInt << endl;
/*
	while(!arquivoDaCrip.eof()){
		arquivoDaCrip.get(crip[i]);
		
		cout << crip[i];
		cout << cifraInt;
		
		if((crip[i]-cifraInt)<65)
			semcrip=(crip[i]-cifraInt)+26;
		else
			semcrip=crip[i]-cifraInt;

		cout << semcrip;
	}
	cout << endl;
*/
}





