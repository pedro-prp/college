#ifndef IMAGEM_PGM_HPP
#define IMAGEM_PGM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;


class ImagemPgm {

private:
	string arquivo;
	string camArquivo;
	ifstream arquivoFilePgm;
	int tamCripInt;
	int inicioCripInt;
	int cifraInt;

public:

	ImagemPgm();
	~ImagemPgm();


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

	void lerArquivo();

	void descriptografar();
};

#endif