#include "GameManager.h"
#include "GameInfo.h"

CGameManager::CGameManager()
{
}



CGameManager::~CGameManager()
{
}

void CGameManager::Run()
{
	if (Init())
	{
		cout << "초기화가 실패했습니다." << endl;
		assert(0);
	}

	while (mIsGameLoop)
	{
		// 게임 실행
		Update();
		Draw();
	}

	// 게임 종료 후 해제 할 것 있으면 여기서 해주겠다
	Release();
}

bool CGameManager::Init()
{
	srand((unsigned int)time(0));




	return true;
}

void CGameManager::Update()
{
}

void CGameManager::Draw()
{
}

void CGameManager::Release()
{
}
