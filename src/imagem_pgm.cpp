#include "imagem_pgm.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <ctype.h>

using namespace std;

ImagemPgm::ImagemPgm(){
	string arquivo = "";
	string camArquivo = "";
}

ImagemPgm::~ImagemPgm(){

}



void ImagemPgm::setArquivo(string arquivo){
	this->arquivo = arquivo;
	camArquivo = "./imagens/" + arquivo;
}

string ImagemPgm::getArquivo(){
	return this->arquivo;
}

string ImagemPgm::getCamArquivo(){
	return camArquivo;
}

int ImagemPgm::getInicioCrip(){
	return inicioCripInt;
}

int ImagemPgm::getTamCrip(){
	return tamCripInt;
}

int ImagemPgm::getCifra(){
	return cifraInt;
}

void ImagemPgm::setInicioCrip(int inicioCripInt){
	this->inicioCripInt = inicioCripInt;
}

void ImagemPgm::setTamCrip(int tamCripInt){
	this->tamCripInt = tamCripInt;	
}

void ImagemPgm::setCifra(int cifraInt){
	this->cifraInt = cifraInt;
}



void ImagemPgm::abrirArquivo(){

	arquivoFilePgm.open(camArquivo,ios::in);
}


void ImagemPgm::lerArquivo(){
	
	string inicioCrip,tamCrip,cifra,tipo,largura,altura,maxCor;
	char comentario,copiaChar;
	vector<char> copiaVector;
	int i=0;

	getline(arquivoFilePgm,tipo,'\n');
	arquivoFilePgm.get(comentario);
	getline(arquivoFilePgm,inicioCrip,' ');
	getline(arquivoFilePgm,tamCrip,' ');
	getline(arquivoFilePgm,cifra,'\n');

	getline(arquivoFilePgm,largura,' ');
	getline(arquivoFilePgm,altura,'\n');
	getline(arquivoFilePgm,maxCor,'\n');

	ofstream arquivoSaida;
	arquivoSaida.open("./imagens/jose.pgm",ios::out);

	ofstream arquivoDaCrip;
	arquivoDaCrip.open("./imagens/crip.txt",ios::out);

	arquivoSaida << tipo << endl;
	arquivoSaida << comentario << inicioCrip << " " << tamCrip << " " << cifra << endl;
	arquivoSaida << largura << " " << altura << endl << maxCor << endl;

	setInicioCrip(stoi(inicioCrip));
	setTamCrip(stoi(tamCrip));
	setCifra(stoi(cifra));

	while(!arquivoFilePgm.eof()){
		
		arquivoFilePgm.get(copiaChar);
		copiaVector.push_back(copiaChar);
		arquivoSaida << copiaVector[i];
		
		i++;
		
	}
	cout << endl;
	
	int j;
	for(j=(inicioCripInt);j<(inicioCripInt+tamCripInt); j++){
		arquivoDaCrip << (copiaVector[j]);
	}
	arquivoFilePgm.close();
	arquivoSaida.close();
	arquivoDaCrip.close();

}

void ImagemPgm::descriptografar(){
	char crip;
	int semcrip=0,i=0;
	int cifraDescrip,tamCripDescrip;

	ifstream arquivoDaCrip;
	arquivoDaCrip.open("./imagens/crip.txt");

	ofstream arquivoDescrip;
	arquivoDescrip.open("./imagens/descrip.txt");

	cifraDescrip = getCifra();
	tamCripDescrip = getTamCrip();

	while(i<tamCripDescrip){
		
		arquivoDaCrip.get(crip);
		

		if(crip == ' ' || crip =='.' || crip == '-'){
			semcrip = (int)crip;
		}
		else{
			if(islower(crip)){

				if(((int)crip-cifraDescrip)<97){
					semcrip=((int)crip-cifraDescrip)+26;
				}
				else{
					semcrip=(int)crip-cifraDescrip;
				}
			}
			else{
				if(((int)crip-cifraDescrip)<65){
					semcrip=((int)crip-cifraDescrip)+26;
				}
				else{
					semcrip=(int)crip-cifraDescrip;
				}
			}
		}
		cout << (char)semcrip;
		arquivoDescrip << (char)semcrip;
		semcrip = 0;
		i++;
	}
	
	cout << endl << endl;
	arquivoDaCrip.close();
	arquivoDescrip.close();
}





