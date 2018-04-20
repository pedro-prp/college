#include "imagem.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Imagem::Imagem(){}

Imagem::~Imagem(){}

void Imagem::setArquivo(string arquivo){
	camArquivo = "./imagens/" + arquivo;
}

string Imagem::getCamArquivo(){
	return camArquivo;
}

int Imagem::getInicioCrip(){
	return inicioCripInt;
}

int Imagem::getTamCrip(){
	return tamCripInt;
}

string Imagem::getCifra(){
	return cifra;
}

void Imagem::setInicioCrip(string inicioCripInt){
	this->inicioCripInt = stoi(inicioCripInt);
}

void Imagem::setTamCrip(string tamCripInt){
	this->tamCripInt = stoi(tamCripInt);	
}

void Imagem::setCifra(string cifra){
	this->cifra = cifra;
}


void Imagem::abrirArquivo(){

	arquivo.open(camArquivo,ios::in);
}
