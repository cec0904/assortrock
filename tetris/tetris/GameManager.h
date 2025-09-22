#pragma once

class CBlock;	// 전방선언

class CGameManager
{
private:

	CBlock* mPBlock;

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