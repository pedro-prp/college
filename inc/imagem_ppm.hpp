#ifndef IMAGEM_PPM_HPP
#define IMAGEM_PPM_HPP

#include "pixel.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class ImagemPpm : public Pixel{
private:
	
	string arquivo;
	string camArquivo;
	ifstream arquivoFilePpm;
	unsigned int inicioCripInt;
	unsigned int tamCripInt;
	string cifra;
	vector<char> alfabetoDaCifra;


public:

	ImagemPpm();
	~ImagemPpm();


	void setArquivo(string arquivo);
	string getArquivo();

	void setInicioCrip(int inicioCripInt);
	void setTamCrip(int tamCripInt);
	void setCifra(string cifra);

	int getInicioCrip();
	int getTamCrip();
	string getCifra();
	
	string getCamArquivo();

	void abrirArquivo();

	void lerArquivo();

	void separaUltimoNumDaCrip();

	void criaVetorDeDescriptografia();

	void setAlfabetoDaCifra(char letra);

	char getAlfabetoDaCifra(int i);

	void descriptografar();

};

#endif