#include "imagem.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>


using namespace std;

int main(int argc, char ** argv){


	Imagem jose;

	string arquivo = "exemplo.pgm";
	//cin >> arquivo;

	jose.setArquivo(arquivo);
	jose.abrirArquivo();
	int cifra = jose.lerArquivo();
	jose.descriptografar(cifra);

}
