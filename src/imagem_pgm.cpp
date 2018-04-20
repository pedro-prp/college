#include "imagem_pgm.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <ctype.h>

using namespace std;

ImagemPgm::ImagemPgm(){
	string arquivo = "";
	string camArquivo = "";
}

ImagemPgm::~ImagemPgm(){

}

void ImagemPgm::lerArquivo(){
	
	string inicioCrip,tamCrip,cifra,tipo,largura,altura,maxCor;
	char comentario,copiaChar;
	vector<char> copiaVector;
	int i=0;

	getline(arquivo,tipo,'\n');
	arquivo.get(comentario);
	getline(arquivo,inicioCrip,' ');
	getline(arquivo,tamCrip,' ');
	getline(arquivo,cifra,'\n');

	getline(arquivo,largura,' ');
	getline(arquivo,altura,'\n');
	getline(arquivo,maxCor,'\n');

	ofstream arquivoSaida;
	arquivoSaida.open("./imagens/jose.pgm",ios::out);

	ofstream arquivoDaCrip;
	arquivoDaCrip.open("./imagens/cripPgm.txt",ios::out);

	arquivoSaida << tipo << endl;
	arquivoSaida << comentario << inicioCrip << " " << tamCrip << " " << cifra << endl;
	arquivoSaida << largura << " " << altura << endl << maxCor << endl;

	setInicioCrip(inicioCrip);
	setTamCrip(tamCrip);
	setCifra(cifra);

	while(!arquivo.eof()){
		
		arquivo.get(copiaChar);
		copiaVector.push_back(copiaChar);
		arquivoSaida << copiaVector[i];
		
		i++;
		
	}
	cout << endl;
	
	int j;
	for(j=getInicioCrip();j<(getInicioCrip()+getTamCrip()); j++){
		arquivoDaCrip << (copiaVector[j]);
	}
	arquivo.close();
	arquivoSaida.close();
	arquivoDaCrip.close();

}

void ImagemPgm::descriptografar(){
	char crip;
	int semcrip=0,i=0;
	int cifraDescrip,tamCripDescrip;

	ifstream arquivoDaCrip;
	arquivoDaCrip.open("./imagens/cripPgm.txt");

	ofstream arquivoDescrip;
	arquivoDescrip.open("./imagens/descripPgm.txt");

	cifraDescrip = stoi(getCifra());
	tamCripDescrip = getTamCrip();

	while(i<tamCripDescrip){
		
		arquivoDaCrip.get(crip);
		

		if(crip == ' ' || crip =='.' || crip == '-'){
			semcrip = (int)crip;
		}
		else{
			if(islower(crip)){

				if(((int)crip-cifraDescrip)<97){
					semcrip=((int)crip-cifraDescrip)+26;
				}
				else{
					semcrip=(int)crip-cifraDescrip;
				}
			}
			else{
				if(((int)crip-cifraDescrip)<65){
					semcrip=((int)crip-cifraDescrip)+26;
				}
				else{
					semcrip=(int)crip-cifraDescrip;
				}
			}
		}
		cout << (char)semcrip;
		arquivoDescrip << (char)semcrip;
		semcrip = 0;
		i++;
	}
	
	cout << endl << endl;
	arquivoDaCrip.close();
	arquivoDescrip.close();
}





