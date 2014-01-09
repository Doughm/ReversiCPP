#ifndef GAME
#define GAME

#include <string>

class Game
{
public:
	Game();
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

private:
	std::string messageGameOut;
	std::string tempStr;
	char pieces[8][8];
	std::string turn;
	int piecesBlack;
	int piecesWhite;
};

#endif