#ifndef IMAGEM_PPM_HPP
#define IMAGEM_PPM_HPP

#include "imagem_ppm.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class ImagemPpm{
private:
	string arquivo;
	string camArquivo;
	ifstream arquivoFilePpm;

public:

	ImagemPpm();
	~ImagemPpm();


	void setArquivo(string arquivo);
	string getArquivo();
	
	string getCamArquivo();

	void abrirArquivo();
};

#endif