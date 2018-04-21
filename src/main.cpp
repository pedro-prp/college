#include "imagem_pgm.hpp"
#include "user_interface.hpp"
#include "imagem_ppm.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>


using namespace std;

int main(int argc, char ** argv){

	UserInterface josezin;
	josezin.printarBoasVindas();
	josezin.printarMenu();


	ImagemPgm jose;
	string arquivo = "blocks.pgm";
	jose.setArquivo(arquivo);
	jose.abrirArquivo();
	jose.lerArquivo();
	jose.descriptografar();

	

	ImagemPpm joao;
	string arquivoPpm = "lena.ppm";
	joao.setArquivo(arquivoPpm);
	joao.abrirArquivo();
	joao.lerArquivo();
	joao.separaUltimoNumDaCrip();
	joao.criaVetorDeDescriptografia();
	joao.descriptografar();

}
