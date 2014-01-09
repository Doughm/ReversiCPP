//ReversiC++ 1.1
//
//Programer Douglas Harvey-Marose
//
//  Version Changes 1.1
//  updated the used engine to verson 1.2
//  game speed is now independent from the frame rate
//  
// - Known isues -
//   none that I could find

#include "program.h"
#include "gametimer.h"
#include "convert.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#pragma comment(linker, "/ENTRY:mainCRTStartup")

int main()
{
	Program program;
	program.start();
    return 0;
}

void Program::assetLoader(std::string const& asset)
{
	if(asset == "main")
	{
        window.setFont("arial.ttf");
        window.setBackgroundColor(sf::Color::Black);
        window.addRectangle("sidebar", sf::Vector2f(480, 0), 160, 480, sf::Color::Magenta);
        window.addRectangle("resetbutton", sf::Vector2f(485, 425), 150, 50, sf::Color::Blue);
        window.addRectangle("passbutton", sf::Vector2f(485, 370), 150, 50, sf::Color::Blue);
        window.addText("turn", sf::Vector2f(490, 200), sf::Color::Black, 17, "Black Players Turn");
        window.addText("blackpieces", sf::Vector2f(490, 50), sf::Color::Black, 17, "Black Pieces 0");
        window.addText("whitepieces", sf::Vector2f(490, 100), sf::Color::White, 17, "White Pieces 0");
        window.addText("reset", sf::Vector2f(525, 430), sf::Color::Yellow, 26, "Reset");
        window.addText("pass", sf::Vector2f(530, 380), sf::Color::Yellow, 26, "Pass");
        window.batchAddCircle(64, "piece", sf::Vector2f(), sf::Color::Black, 25);
        window.batchAddRectangle(64, "square", sf::Vector2f(), 58, 58, sf::Color::Green);
	}
}


void Program::start()
{
	assetLoader("main");
	Game game;
    GameTimer gameTimer;
    LoadINI loadINI("engine.ini");
	std::string tempStr;
    float gameSpeed;
	std::string mouseClick;

	//loads game speed
    if (loadINI.inFile("GameSpeed"))
    {
		gameSpeed = Convert::stringToFloat(loadINI.getValue("GameSpeed"));
        gameSpeed = 1000000 / gameSpeed;
    }
    else
    {
        gameSpeed = 30;
        gameSpeed = 1000000 / gameSpeed;
    }
            
    //moves all the pieces into place
    for (int i = 0; i < 64; i++)
    {
		window.moveEntity("square" + Convert::intToString(i + 1), sf::Vector2f((i % 8) * 60 + 1, (i / 8) * 60 + 1));
        window.moveEntity("piece" + Convert::intToString(i + 1), sf::Vector2f((i % 8) * 60 + 5, (i / 8) * 60 + 5));
        window.makeInvisible("piece" + Convert::intToString(i + 1));
    }

    gameTimer.restartClock();

	while(window.isOpen())
	{
		//game logic
		if (gameTimer.getElapsedTimeMicroseconds() >= gameSpeed)
        {
			//reads the mouse for input
			mouseClick.clear();
			mouseClick.append(window.inputMouseClick());

            //tells if the game has ended
            if (game.gameEnd() == false)
            {
                //mouse input
                if (mouseClick == "Leftbutton")
                {
					tempStr.clear();
                    tempStr = window.batchIsWithin("square", window.mousePositionView());
                    if (tempStr.find("square") != std::string::npos)
                    {
                        game.placePiece(window.batchNumber(tempStr) - 1);
                    }
                    else if (window.isWithin("passbutton", window.mousePositionView()))
                    {
                        game.switchTurn();
                    }
					else if (window.isWithin("resetbutton", window.mousePositionView()))
					{
						game.resetBoard();
					}
                }
                //update the pieces
                for (int i = 0; i < 64; i++)
                {
                    if (game.getPlaced(i))
                    {
                        window.makeVisible("piece" + Convert::intToString(i + 1));
                    }
                    if (game.getColor(i) == "White")
                    {
                        window.setColor("piece" + Convert::intToString(i + 1), sf::Color::White);
                    }
                    else if (game.getColor(i) == "Black")
                    {
                        window.setColor("piece" + Convert::intToString(i + 1), sf::Color::Black);
                    }
                    else if (game.getColor(i) == "empty")
                    {
                        window.makeInvisible("piece" + Convert::intToString(i + 1));
                    }
                }

                //updates the UI
                window.setText("blackpieces", "Black Pieces " + Convert::intToString(game.getPiecesBlack()));
                window.setText("whitepieces", "White Pieces " + Convert::intToString(game.getPiecesWhite()));

                if (game.getTurn() == "Black")
                {
                    window.setText("turn", "Black Players Turn");
                    window.setColor("turn", sf::Color::Black);
                }
                else if (game.getTurn() == "White")
                {
                    window.setText("turn", "White Players Turn");
                    window.setColor("turn", sf::Color::White);
                }
            }
            else if (game.gameEnd() == true)
            {
                if (game.getPiecesBlack() > game.getPiecesWhite())
                {
                    window.setText("turn", "Black Player Wins!");
                }
                else if (game.getPiecesBlack() < game.getPiecesWhite())
                {
                    window.setText("turn", "White Player Wins!");
                }
            }

			gameTimer.restartClock();
        }

		//updates the window
		window.drawAll();
	}
}