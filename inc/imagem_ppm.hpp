#ifndef IMAGEM_PPM_HPP
#define IMAGEM_PPM_HPP

#include "pixel.hpp"
#include "imagem.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class ImagemPpm : public Pixel, public Imagem{
private:
	
	vector<char> alfabetoDaCifra;


public:

	ImagemPpm();
	~ImagemPpm();

	void lerArquivo();

	void separaUltimoNumDaCrip();

	void criaVetorDeDescriptografia();

	void setAlfabetoDaCifra(char letra);

	char getAlfabetoDaCifra(int i);

	void descriptografar();

};

#endif