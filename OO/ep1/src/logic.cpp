#include "logic.hpp"
#include <string>

using namespace std;

Logic::Logic(){}

Logic::~Logic(){}

void Logic::aplicacaoPGM(){

	ImagemPgm jose;
	jose.setArquivo(pegarCaminhoDaImagem());
	jose.abrirArquivo();
	jose.lerArquivo();
	
	cabecalhoDaMensagem();
	jose.descriptografar();
}

void Logic::aplicacaoPPM(){
	ImagemPpm joao;
	joao.setArquivo(pegarCaminhoDaImagem());
	joao.abrirArquivo();
	joao.lerArquivo();
	joao.separaUltimoNumDaCrip();
	joao.criaVetorDeDescriptografia();

	cabecalhoDaMensagem();
	joao.descriptografar();
}

string Logic::pegarCaminhoDaImagem(){
	string arquivo;
	cabecalhoDoCaminho();
	cin >> arquivo;
	return arquivo;

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
			setDesejaSair();
			break;
		default:
			printarErroDeOpcao();
	}

}

void Logic::desejaContinuar(){
	printarDesejaContinuar();
	char x;
	cin >> x;
	if(x=='S' || x=='s'){
		setDesejaContinuar(1);
	}
	else{
		setDesejaContinuar(0);
	}

}

void Logic::setDesejaContinuar(int desejaContinuar){
	this->desejaContinuarInt = desejaContinuar;
}

void Logic::setDesejaSair(){
	printarDecisaoPraSair();
	char x;
	cin >> x;
	if(x=='S' || x=='s'){
		this->desejaSairInt = 1;
	}
	else{
		this->desejaSairInt = 0;
	}
}

void Logic::aplicacao(){
	while(desejaContinuarInt==1){
		try{
			menu();
		
			if(desejaSairInt == 0){
				desejaContinuar();
			}
			else{
				setDesejaContinuar(0);
			}
		}
		catch(int exception){
			printarErroDeAbertura();
		}
	}
	printarFinalizacao();
}