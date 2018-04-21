#include "imagem_ppm.hpp"
#include "imagem.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <ctype.h>

using namespace std;

ImagemPpm::ImagemPpm(){

}

ImagemPpm::~ImagemPpm(){

}

void ImagemPpm::setAlfabetoDaCifra(char letra){
	this->alfabetoDaCifra.push_back(letra);
}

char ImagemPpm::getAlfabetoDaCifra(int i){
	return alfabetoDaCifra[i];
}

void ImagemPpm::lerArquivo(){
	string inicioCrip,tamCrip,cifra,tipo,largura,altura,maxCor;
	char comentario,copiaChar;
	vector<char> copiaVector;
	vector<unsigned int> pixels;
	unsigned int i=0;

	ofstream arquivoSaida;
	arquivoSaida.open("./imagens/jose.ppm",ios::out);

	ofstream arquivoDaCripPrim;
	ofstream arquivoDaCripSec;
	arquivoDaCripPrim.open("./imagens/cripPpmPrim.txt",ios::out);

	getline(arquivo,tipo,'\n');
	arquivo.get(comentario);
	getline(arquivo,inicioCrip,' ');
	getline(arquivo,tamCrip,' ');
	getline(arquivo,cifra,'\n');
	getline(arquivo,largura,' ');
	getline(arquivo,altura,'\n');
	getline(arquivo,maxCor,'\n');

	arquivoSaida << tipo << endl;
	arquivoSaida << comentario << inicioCrip << " " << tamCrip << " " << cifra << endl;
	arquivoSaida << largura << " " << altura << endl << maxCor << endl;

	setInicioCrip(inicioCrip);
	setTamCrip(tamCrip);
	setCifra(cifra);

	while(!arquivo.eof()){
		arquivo.get(copiaChar);
		pixels.push_back((int)copiaChar);
		arquivoSaida << copiaChar;
	}

	for(i=getInicioCrip();i<getInicioCrip()+(getTamCrip()*3); i+=3){
		arquivoDaCripPrim << pixels[i] << " ";
		arquivoDaCripPrim << pixels[i+1] << " ";
		arquivoDaCripPrim << pixels[i+2] << endl;
	}

	arquivo.close();
	arquivoSaida.close();
	arquivoDaCripPrim.close();

}


void ImagemPpm::separaUltimoNumDaCrip(){
	char numeroChar;
	string tamChar;
	unsigned int i,j;
	string redLast,greenLast,blueLast;
	vector<char> numero;
	ifstream arquivoDaCripPrim;
	arquivoDaCripPrim.open("./imagens/cripPpmPrim.txt");

	ofstream arquivoDaCripSec;
	arquivoDaCripSec.open("./imagens/cripPpmSec.txt");
	
	for(i=1;i<=getTamCrip(); i++){
		
		getline(arquivoDaCripPrim,tamChar,' ');
		for(j=1;j<(tamChar.size());j++){
				numeroChar = tamChar[j];
		}
		redLast = (int)numeroChar;

		
		getline(arquivoDaCripPrim,tamChar,' ');
		for(j=1;j<(tamChar.size());j++){
			numeroChar = tamChar[j];
		}
		greenLast = (int)numeroChar;


		getline(arquivoDaCripPrim,tamChar,'\n');
		for(j=1;j<(tamChar.size());j++){
			numeroChar = tamChar[j];
		}
		blueLast = (int)numeroChar;

		arquivoDaCripSec << (stoi(redLast) + stoi(greenLast) + stoi(blueLast)) << " ";
		
	}
	arquivoDaCripPrim.close();
	arquivoDaCripSec.close();
}

void ImagemPpm::criaVetorDeDescriptografia(){

	unsigned int i=0,flag=0,j=0;
	
	ifstream arquivoDaCripSec;
	arquivoDaCripSec.open("./imagens/cripPpmSec.txt");

	char letraLeitura,letra;
	string cifra;
	cifra = getCifra();

	setAlfabetoDaCifra(' ');

	for(i=0;i<cifra.size();i++){
		letraLeitura = cifra[i];
		setAlfabetoDaCifra(letraLeitura);
	}

	cout << endl;

	for(i=1; i<27 ;i++){
		letra = (i+96);

		for(j=0;j<cifra.size();j++){
			letraLeitura = cifra[j];
			if(letra == letraLeitura){
				flag = 1;
			}
		}


		if(flag == 0) {
			setAlfabetoDaCifra(letra);
		}
		
		flag=0;

	}

	cout << endl;

	arquivoDaCripSec.close();

}

void ImagemPpm::descriptografar(){
	ifstream arquivoDaCripSec;
	arquivoDaCripSec.open("./imagens/cripPpmSec.txt");



	string num;
	char letra;
	int tamCrip = getTamCrip();
	cout << endl;

	vector<char> alfabetoComum;
	alfabetoComum.push_back(' ');

	int i,j;
	for(i=1;i<=26;i++){
		char letra = (i+96);
		alfabetoComum.push_back(letra);
	}

	for(int i=1;i<=tamCrip;i++){
		
		getline(arquivoDaCripSec,num,' ');

		letra = alfabetoComum[stoi(num)];

		for(j=0;j<27;j++){
			
			if(getAlfabetoDaCifra(j)==letra){
				cout << alfabetoComum[j];
			}
		}

	}
	cout << endl;

}


