#include "assetloader.h"

AssetLoader::AssetLoader(Window * passedWindow)
{
	window = passedWindow;
}

AssetLoader::~AssetLoader()
{
	window = NULL;
}

//loads in the staring assests
void AssetLoader::loadBaseAssets()
{
	window->setFont("arial.ttf");
	window->setFont("arial.ttf");
	window->setBackgroundColor(sf::Color::Black);
	window->addRectangle("sidebar", sf::Vector2f(480, 0), 160, 480, sf::Color::Magenta);
	window->addRectangle("resetbutton", sf::Vector2f(485, 425), 150, 50, sf::Color::Blue);
	window->addRectangle("passbutton", sf::Vector2f(485, 370), 150, 50, sf::Color::Blue);
	window->addText("turn", sf::Vector2f(490, 200), sf::Color::Black, 17, "Black Players Turn");
	window->addText("blackpieces", sf::Vector2f(490, 50), sf::Color::Black, 17, "Black Pieces 0");
	window->addText("whitepieces", sf::Vector2f(490, 100), sf::Color::White, 17, "White Pieces 0");
	window->addText("reset", sf::Vector2f(525, 430), sf::Color::Yellow, 26, "Reset");
	window->addText("pass", sf::Vector2f(530, 380), sf::Color::Yellow, 26, "Pass");
	window->batchAddCircle(64, "piece", sf::Vector2f(), sf::Color::Black, 25);
	window->batchAddRectangle(64, "square", sf::Vector2f(), 58, 58, sf::Color::Green);
}