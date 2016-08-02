#ifndef ASSETLOADER
#define ASSETLOADER

#include <string>
#include <SFML/Graphics.hpp>
#include "window.h"

class AssetLoader
{
public:
	AssetLoader(Window*);
	~AssetLoader();
	void loadBaseAssets();

private:
	Window* window;
};

#endif