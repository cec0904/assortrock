#pragma once
#include "GameInfo.h"
class CSnake
{
private:
	POS head;



	// 머리 몸통
public:
	CSnake();
	~CSnake();
	
	void Move(int dir);

	POS GetHead()
	{
		return head;
	}


};

//class CGameManager 
//{
//
//
//public:
//	void GameRun();
//};