#pragma once

// 게임 관리하는 클래스
class CGameManager
{

private:
	// 게임이 진행 중인지 확인하는 멤버 변수
	bool mIsGameLoop = true;

private:
	// 초기화 해주는 함수
	bool Init();
	// 게임 업데이트 해주는 함수
	void Update();
	// 게임 그려주는 함수
	void Draw();
	//게임 종료시 실행 시키는 함수
	void Release();


public:
	void Run();




private:
	CGameManager();
	~CGameManager();

public:
	static CGameManager* GetInt()
	{
		static CGameManager Instance;
		return &Instance;
	}





};

