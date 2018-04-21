#include "logic.hpp"

Logic::Logic(){}

Logic::~Logic(){}

void Logic::aplicacaoPGM(){

	ImagemPgm jose;
	string arquivo = "exemplo.pgm";
	jose.setArquivo(arquivo);
	jose.abrirArquivo();
	jose.lerArquivo();
	jose.descriptografar();
}

void Logic::aplicacaoPPM(){
	ImagemPpm joao;
	string arquivoPpm = "lena.ppm";
	joao.setArquivo(arquivoPpm);
	joao.abrirArquivo();
	joao.lerArquivo();
	joao.separaUltimoNumDaCrip();
	joao.criaVetorDeDescriptografia();
	joao.descriptografar();
}

void Logic::menu(){
	printarBoasVindas();
	printarMenu();
	int menu;
	cin >> menu;

	switch (menu){
		case 1:
			aplicacaoPGM();
			break;
		case 2:
			aplicacaoPPM();
			break;
		case 3:
			printarFinalizacao();
			break;
		default:
			printarErroDeOpcao();
	}
	


}