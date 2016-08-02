//ReversiC++ 1.11
//
//Programer Douglas Harvey-Marose
//
//  Version Changes 1.11
//  complete refactor of the program
//
//  Version Changes 1.1
//  updated the used engine to verson 1.2
//  game speed is now independent from the frame rate
//  
// - Known isues -
//   none that I could find

#include "gametimer.h"
#include "convert.h"
#include "game.h"
#include "assetloader.h"
#include "window.h"
#include <SFML/Graphics.hpp>
#include <string>

#pragma comment(linker, "/ENTRY:mainCRTStartup")

int main()
{
	Window* window = new Window();
	GameTimer gameTimer;
	LoadINI loadINI("engine.ini");
	AssetLoader assetLoader(window);
	Game game(window);

	assetLoader.loadBaseAssets();
	game.setupBoard();
	gameTimer.restartClock();

	while (window->isOpen())
	{
		if (gameTimer.getElapsedTimeMicroseconds() >= game.getGameSpeed())
		{
			game.mouseInput();
			game.mouseInputReset();

			if (game.gameEnd() == false)
			{
				game.mouseInputGame();
				game.updatePieceGraphics();
				game.updateUI();
			}
			else
			{
				game.setMarqueeWon();
			}

			gameTimer.restartClock();
		}

		//updates the window
		window->drawAll();
	}

	delete window;
    return 0;
}