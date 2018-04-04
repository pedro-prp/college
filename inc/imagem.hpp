#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Imagem {

private:
	string arquivo;
	string camArquivo;

public:

	Imagem();
	~Imagem();


	void setArquivo(string arquivo);
	string getArquivo();
	
	string getCamArquivo();

	void abrirArquivo();
	
};

#endif