#ifndef IMAGEM_PGM_HPP
#define IMAGEM_PGM_HPP

#include "imagem.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;


class ImagemPgm : public Imagem{
	
public:

	ImagemPgm();
	~ImagemPgm();

	void lerArquivo();

	void descriptografar();
};

#endif