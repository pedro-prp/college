#include "imagem_pgm.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>


using namespace std;

int main(int argc, char ** argv){


	ImagemPgm jose;

	string arquivo = "exemplo.pgm";
	//cin >> arquivo;

	jose.setArquivo(arquivo);
	jose.abrirArquivo();
	jose.lerArquivo();
	jose.descriptografar();

}
