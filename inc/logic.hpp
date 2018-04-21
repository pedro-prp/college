#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <iostream>
#include "user_interface.hpp"
#include "imagem_ppm.hpp"
#include "imagem_pgm.hpp"
#include "imagem.hpp"

class Logic : public UserInterface {
public:
	Logic();
	~Logic();
	void aplicacaoPGM();
	void aplicacaoPPM();
	void menu();
	string pegarCaminhoDaImagem();
	void aplicacao();


};

#endif