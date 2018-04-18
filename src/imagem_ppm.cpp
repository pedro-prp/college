#include "imagem_ppm.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <ctype.h>

using namespace std;

ImagemPpm::ImagemPpm(){
	string arquivo = "";
	string camArquivo = "";
}

ImagemPpm::~ImagemPpm(){

}


void ImagemPpm::setArquivo(string arquivo){
	this->arquivo = arquivo;
	camArquivo = "./imagens/" + arquivo;
}

string ImagemPpm::getArquivo(){
	return this->arquivo;
}

int ImagemPpm::getInicioCrip(){
	return inicioCripInt;
}

int ImagemPpm::getTamCrip(){
	return tamCripInt;
}

string ImagemPpm::getCifra(){
	return cifra;
}

void ImagemPpm::setInicioCrip(int inicioCripInt){
	this->inicioCripInt = inicioCripInt;
}

void ImagemPpm::setTamCrip(int tamCripInt){
	this->tamCripInt = tamCripInt;	
}

void ImagemPpm::setCifra(string cifra){
	this->cifra = cifra;
}

void ImagemPpm::setAlfabetoDaCifra(char letra){
	this->alfabetoDaCifra.push_back(letra);
}

char ImagemPpm::getAlfabetoDaCifra(int i){
	return alfabetoDaCifra[i];
}


void ImagemPpm::abrirArquivo(){

	arquivoFilePpm.open(camArquivo,ios::in);
	
}

void ImagemPpm::lerArquivo(){
	string inicioCrip,tamCrip,cifra,tipo,largura,altura,maxCor;
	char comentario,copiaChar;
	vector<char> copiaVector;
	int i=0;

	ofstream arquivoSaida;
	arquivoSaida.open("./imagens/jose.ppm",ios::out);

	ofstream arquivoDaCripPrim;
	ofstream arquivoDaCripSec;
	arquivoDaCripPrim.open("./imagens/cripPpmPrim.txt",ios::out);
	arquivoDaCripSec.open("./imagens/cripPpmSec.txt",ios::out);

	getline(arquivoFilePpm,tipo,'\n');
	arquivoFilePpm.get(comentario);
	getline(arquivoFilePpm,inicioCrip,' ');
	getline(arquivoFilePpm,tamCrip,' ');
	getline(arquivoFilePpm,cifra,'\n');
	getline(arquivoFilePpm,largura,' ');
	getline(arquivoFilePpm,altura,'\n');
	getline(arquivoFilePpm,maxCor,'\n');

	arquivoSaida << tipo << endl;
	arquivoSaida << comentario << inicioCrip << " " << tamCrip << " " << cifra << endl;
	arquivoSaida << largura << " " << altura << endl << maxCor << endl;

	setInicioCrip(stoi(inicioCrip));
	setTamCrip(stoi(tamCrip));
	setCifra(cifra);

	while(!arquivoFilePpm.eof()){

		arquivoFilePpm.get(copiaChar);
		setRed(copiaChar);
		arquivoSaida << getRed();

		arquivoFilePpm.get(copiaChar);
		setGreen(copiaChar);
		arquivoSaida << getGreen();

		arquivoFilePpm.get(copiaChar);
		setBlue(copiaChar);
		arquivoSaida << getBlue();

	}
	// salva no cripPrim Ex.: R G B
	for(i=((inicioCripInt)/3);i<((inicioCripInt/3)+tamCripInt); i++){
		arquivoDaCripPrim << getRedVector(i) << " " << getGreenVector(i) << " " <<getBlueVector(i) << endl;
	}

	arquivoFilePpm.close();
	arquivoSaida.close();
	arquivoDaCripPrim.close();
	arquivoDaCripSec.close();

}


void ImagemPpm::separaUltimoNumDaCrip(){
	char numeroChar;
	string tamChar;
	int i,j;
	string redLast,greenLast,blueLast;
	vector<char> numero;
	ifstream arquivoDaCripPrim;
	arquivoDaCripPrim.open("./imagens/cripPpmPrim.txt");

	ofstream arquivoDaCripSec;
	arquivoDaCripSec.open("./imagens/cripPpmSec.txt");
	
	for(i=1;i<=tamCripInt; i++){
		
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

	int i=0,flag=0,j=0;
	
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
	
	for(int a=0;a<27;a++){
		cout << getAlfabetoDaCifra(a);
		cout << a;
	}
	cout << endl;

	arquivoDaCripSec.close();

}

void ImagemPpm::descriptografar(){

	ifstream arquivoDaCripSec;
	arquivoDaCripSec.open("./imagens/CripPpmSec.txt");

	string num;
	int tamCrip = getTamCrip();
	cout << endl;
	

	for(int i=1;i<=tamCrip;i++){
		
		getline(arquivoDaCripSec,num,' ');

			cout << getAlfabetoDaCifra(stoi(num)) << " ";
		num="";
	}
	cout << endl;

	arquivoDaCripSec.close();

}

