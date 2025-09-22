#pragma once
#include "GameInfo.h"


class CGameManager
{
	// 싱글톤
	// 객체를 계속 만들어서 쓰는게 아니라
	// 하나만 만들어서 넣고 쓰고 넣고 쓰고
private:
	CGameManager();
	~CGameManager();
	
public:
	static CGameManager* GetInst()
	{
		// .보다 -> 이게 더 편하다
		static CGameManager Inst;
		return &Inst;
	}

	

private:
	// 게임 초기화 Init
	bool Init();
	void Update();
	void Draw();
	void Release();
public:
	void GameRun();

};

