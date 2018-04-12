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

string ImagemPpm::getCamArquivo(){
	return camArquivo;
}



void ImagemPpm::abrirArquivo(){

	arquivoFilePpm.open(camArquivo,ios::in);
	
}
