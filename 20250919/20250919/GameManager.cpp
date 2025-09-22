#include "GameManager.h"

CGameManager::~CGameManager()
{

}

void CGameManager::GameRun()
{
	if (!Init)
	{
		assert(0);
	}

	while (true)
	{
		Update();
		Draw();
		Release();
	}
}

bool CGameManager::Init()
{
	return false;
}


void CGameManager::Update()
{

}
void CGameManager::Draw()
{
	cout << "TEXTRPG" << endl;
}
void CGameManager::Release()
{

}