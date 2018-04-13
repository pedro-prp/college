#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Pixel {
private:
	char red;
	char green;
	char blue;
	vector<int> redVector;
	vector<int> greenVector;
	vector<int> blueVector;
public:
	
	void setRed(char red);
	char getRed();
	int getRedVector(int i);

	void setGreen(char green);
	char getGreen();
	int getGreenVector(int i);

	void setBlue(char blue);
	char getBlue();
	int getBlueVector(int i);
};



#endif