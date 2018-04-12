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
	ifstream arquivoFile;

public:

	ImagemPgm();
	~ImagemPgm();


	void setArquivo(string arquivo);
	string getArquivo();
	
	string getCamArquivo();

	void abrirArquivo();

	void lerArquivo();

	void descriptografar();
};

#endif