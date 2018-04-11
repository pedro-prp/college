#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include "imagem.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;


class Imagem {

private:
	string arquivo;
	string camArquivo;
	ifstream arquivoFile;

public:

	Imagem();
	~Imagem();


	void setArquivo(string arquivo);
	string getArquivo();
	
	string getCamArquivo();

	void abrirArquivo();

	void lerArquivo();

	//void descriptografar();
};

#endif