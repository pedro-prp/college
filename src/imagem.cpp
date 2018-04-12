#include "imagem.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <ctype.h>

using namespace std;

Imagem::Imagem(){
	string arquivo = "";
	string camArquivo = "";
}

Imagem::~Imagem(){

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
	arquivoDaCrip << cifraInt << " " << tamCripInt << endl;
	for(j=(inicioCripInt);j<(inicioCripInt+tamCripInt); j++){
		arquivoDaCrip << (copiaVector[j]);
	}
	arquivoFile.close();
	arquivoSaida.close();
	arquivoDaCrip.close();

}

void Imagem::descriptografar(){
	char crip;
	int semcrip=0,i=0;
	string cifra,tamCrip;
	int cifraInt,tamCripInt;

	ifstream arquivoDaCrip;
	arquivoDaCrip.open("./imagens/crip.txt");

	ofstream arquivoDescrip;
	arquivoDescrip.open("./imagens/descrip.txt");

	getline(arquivoDaCrip,cifra,' ');
	getline(arquivoDaCrip,tamCrip,'\n');

	cifraInt = stoi(cifra);
	tamCripInt = stoi(tamCrip);

	while(i<tamCripInt){
		
		arquivoDaCrip.get(crip);
		

		if(crip == ' ' || crip =='.' || crip == '-'){
			semcrip = (int)crip;
		}
		else{
			if(islower(crip)){

				if(((int)crip-cifraInt)<97){
					semcrip=((int)crip-cifraInt)+26;
				}
				else{
					semcrip=(int)crip-cifraInt;
				}
			}
			else{
				if(((int)crip-cifraInt)<65){
					semcrip=((int)crip-cifraInt)+26;
				}
				else{
					semcrip=(int)crip-cifraInt;
				}
			}
		}
		cout << (char)semcrip;
		arquivoDescrip << (char)semcrip;
		semcrip = 0;
		i++;
	}
	
	cout << endl << endl;
}





