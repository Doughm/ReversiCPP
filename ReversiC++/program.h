#ifndef PROGRAM
#define PROGRAM

#include "window.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

Window window;

class Program
{
private:
	void assetLoader(std::string const&);

public:
	void start();
};

#endif