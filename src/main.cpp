#include <iostream>
#include <fstream>
#include <string>
#include "imagem.hpp"


using namespace std;

int main(int argc, char ** argv){


	Imagem jose;

	string arquivo = "exemplo.pgm";
	//cin >> arquivo;

	jose.setArquivo(arquivo);
	jose.abrirArquivo();
	jose.lerArquivo();

}
