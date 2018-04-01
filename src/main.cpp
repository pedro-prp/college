#include <iostream>
#include <fstream>
#include  <string>

using namespace std;

int main(int argc, char ** argv){
	
	ifstream imagem;
	imagem.open("../imagens/feep.pgm",ios::in);

	ofstream imagem2;
	imagem2.open("../imagens/jose.pgm",ios::out);


	string line = "";
	string check ="#";
	int i=1,x=1;
	
	while(i<12) {
		
		getline(imagem,line);

		imagem2 << line << endl;
		i++;
		line = "";
	}


	imagem.close();
	imagem2.close();


	return 0;
}