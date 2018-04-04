#include <iostream>
#include <fstream>
#include <string>
#include "imagem.hpp"


using namespace std;

int main(int argc, char ** argv){


	Imagem jose;
	string joseArquivo;

	cin >> joseArquivo;

	jose.setArquivo(joseArquivo);

	cout << jose.getCamArquivo() << endl;

	jose.abrirArquivo();

}
