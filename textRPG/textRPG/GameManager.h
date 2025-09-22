#pragma once
#include "GameInfo.h"


class CGameManager
{
private:
	class CPlayer* mPlayer = nullptr;

	class CMonster* mMonster = nullptr;

	int mInputMessage = 0;

	int mStageLevel = 1;
private:
	//게임 초기화 Init
	bool Init();

	void GameProgressDraw();


	//게임 로직 업데이트 update
	void Update();
	//게임 그려주기	Draw
	void Draw();
	//게임 끝 해제해주기 Release
	void Release();
	// 입력받기
	void Input();

public:
	void GameRun();

	int GetInputMessage()
	{
		return mInputMessage;
	}
	void NextStage();


#pragma region Monster
	bool CreateMonster();

	bool IsValidMonster();

	void DeleteMonster();

	CMonster* GetMonster()
	{
		return mMonster;
	}
	
#pragma endregion

private:
	//싱글톤 
	DECLARE_SINGLETON(CGameManager)

};

