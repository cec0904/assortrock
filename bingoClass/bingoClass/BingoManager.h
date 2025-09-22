#pragma once
#include "Player.h"
#include "Ai.h"
#include <array>

using namespace std;





class CBingoManager
{
public:

	int* nPLineCount = 0;
	int* nAiLineCount = 0;


private:
	

	

	

	bool mIsGameOver = false;

	void Init();

	void BingoLineCount();

	
	void StarCheck();
	

	

	void Draw();

	

public:

	int nPBoard[25] = {};
	int nAiBoard[25] = {};

	CBingoManager();
	~CBingoManager();

	

public:
	void GameRun();

};

