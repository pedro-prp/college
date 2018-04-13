#include "pixel.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

void Pixel::setRed(char red){
	this->red = red;
	this->redVector.push_back((unsigned int)red);
}
char Pixel::getRed(){
	return red;
}

int Pixel::getRedVector(int i){
	return (unsigned)redVector[i];

}



void Pixel::setGreen(char green){
	this->green = green;
	this->greenVector.push_back((unsigned int)green);
}
char Pixel::getGreen(){
	return green;
}

int Pixel::getGreenVector(int i){
	return (unsigned)greenVector[i];
}



void Pixel::setBlue(char blue){
	this->blue = blue;
	this->blueVector.push_back((unsigned int)blue);
}
char Pixel::getBlue(){
	return blue;
}

int Pixel::getBlueVector(int i){
	return (unsigned)blueVector[i];
}


