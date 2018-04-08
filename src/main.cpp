#include <iostream>
#include <fstream>
#include <string>
#include "imagem.hpp"


using namespace std;

int main(int argc, char ** argv){


	Imagem jose;

	jose.setArquivo("jose.pgm");
	jose.abrirArquivo();
	jose.lerArquivo();



}
