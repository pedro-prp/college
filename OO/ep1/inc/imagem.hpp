#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Imagem{
private:
	string camArquivo;
	unsigned int tamCripInt;
	unsigned int inicioCripInt;
	unsigned int cifraInt;
	string cifra;

protected:
	ifstream arquivo;

public:
	Imagem();
	~Imagem();

	void setArquivo(string arquivo);
	string getArquivo();

	void setInicioCrip(string inicioCrip);
	void setTamCrip(string tamCripInt);
	void setCifra(string cifra);

	int getInicioCrip();
	int getTamCrip();
	string getCifra();
	
	string getCamArquivo();

	void abrirArquivo();

	void lerArquivo();
	void descriptografador();

};


#endif

