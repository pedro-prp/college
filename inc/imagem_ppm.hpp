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
	int inicioCripInt;
	int tamCripInt;
	int cifraInt;

public:

	ImagemPpm();
	~ImagemPpm();


	void setArquivo(string arquivo);
	string getArquivo();

	void setInicioCrip(int inicioCripInt);
	void setTamCrip(int tamCripInt);
	void setCifra(int cifraInt);

	int getInicioCrip();
	int getTamCrip();
	int getCifra();
	
	string getCamArquivo();

	void abrirArquivo();

};

#endif