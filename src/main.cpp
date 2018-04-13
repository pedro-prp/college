#include "imagem_pgm.hpp"
#include "imagem_ppm.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>


using namespace std;

int main(int argc, char ** argv){


	ImagemPgm jose;
	string arquivo = "exemplo.pgm";
	jose.setArquivo(arquivo);
	jose.abrirArquivo();
	jose.lerArquivo();
	jose.descriptografar();

	

	ImagemPpm joao;
	string arquivoPpm = "exemplo.ppm";
	joao.setArquivo(arquivoPpm);
	joao.abrirArquivo();
	joao.lerArquivo();
	joao.separaUltimoNumDaCrip();
	//joao.descriptografar();

}
