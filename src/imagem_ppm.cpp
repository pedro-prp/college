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

int ImagemPpm::getCifra(){
	return cifraInt;
}

void ImagemPpm::setInicioCrip(int inicioCripInt){
	this->inicioCripInt = inicioCripInt;
}

void ImagemPpm::setTamCrip(int tamCripInt){
	this->tamCripInt = tamCripInt;	
}

void ImagemPpm::setCifra(int cifraInt){
	this->cifraInt = cifraInt;
}


void ImagemPpm::abrirArquivo(){

	arquivoFilePpm.open(camArquivo,ios::in);
	
}