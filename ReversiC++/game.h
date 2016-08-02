#ifndef GAME
#define GAME

#include "gametimer.h"
#include "convert.h"
#include "game.h"
#include "assetloader.h"
#include "window.h"
#include <SFML/Graphics.hpp>
#include <string>

class Game
{
public:
	Game(Window*);
	~Game();
	void resetBoard();
	void placePiece(int);
	bool getPlaced(int);
	std::string getColor(int);
	int getPiecesBlack();
	int getPiecesWhite();
	void updatePieceAmount();
	void switchTurn();
	std::string getTurn();
	bool lineChange(int, int);
	bool isSandwitched(std::string const&, int, int);
	void swapPieces(std::string const&, int, int);
	bool gameEnd();
	float getGameSpeed();
	void setupBoard();
	void mouseInput();
	void mouseInputGame();
	void mouseInputReset();
	void updatePieceGraphics();
	void updateUI();
	void setMarqueeWon();

private:
	Window* window;
	std::string messageGameOut;
	std::string tempStr;
	char pieces[8][8];
	std::string turn;
	int piecesBlack;
	int piecesWhite;
	float gameSpeed;
	std::string mouseClick;

	bool isSandwitchedRight(int, int);
	bool isSandwitchedLeft(int, int);
	bool isSandwitchedDown(int, int);
	bool isSandwitchedUp(int, int);
	bool isSandwitchedDownRight(int, int);
	bool isSandwitchedDownLeft(int, int);
	bool isSandwitchedUpLeft(int, int);
	bool isSandwitchedUpRight(int, int);
	void swapPiecesRight(int, int);
	void swapPiecesLeft(int, int);
	void swapPiecesDown(int, int);
	void swapPiecesUp(int, int);
	void swapPiecesDownRight(int, int);
	void swapPiecesDownLeft(int, int);
	void swapPiecesUpLeft(int, int);
	void swapPiecesUpRight(int, int);
};

#endif