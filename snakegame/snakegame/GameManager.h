#pragma once
#include "Snake.h";

class CSnake;

class CGameManager
{
private:
	CSnake* mPSnake;

	bool Init();


	void HideCursor();

	void Input();
	void Draw();
	void Update();


public:
	CGameManager();
	~CGameManager();


public:
	void GameRun();



			

};

