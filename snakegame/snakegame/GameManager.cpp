#include "GameManager.h"
#include "Snake.h";
#include <iostream>
#include "GameInfo.h"

#include <Windows.h>

#include <conio.h> // 이 친구를 추가해야 입력을 받을 수 있다.

using namespace std;

// 입력



/*
	c++ 동적할당은

	new 키워드로 생성한다.

	delete 로 해제한다.
*/

//enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
//eDirection dir;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	if (mPSnake)
	{
		delete mPSnake;
	}
}




bool CGameManager::Init()
{
	mPSnake = new CSnake;
	if (mPSnake == nullptr)
	{
		return false;
	}
	HideCursor();

	//int* arr = new int[100];
	//delete arr;

	return true;
}

void CGameManager::HideCursor()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void CGameManager::Input()
{

	//_kbhit();		// 키보드가 눌렸는지 확인하는 함수 : 눌렀으면 true, 아니면 false 반환
	//_getch();		// 눌린 키 값을 반환한다.

	if (_kbhit())
	{
		cout << "키보드가 눌렸습니다." << endl;
		int getkey = _getch();	//아스키코드로 나온다.
		cout << (char)getkey << endl;

		switch (getkey)
		{
		case 'w':
			
			//위
			break;
		case 'a':
			//왼쪽
			break;
		case 's':
			//아래
			break;
		case 'd':
			//오른쪽
			break;
		}
	}

}

void CGameManager::Draw()
{
	// 콘솔에 그리기
	system("cls");

	// 게임판 그리기
	// 상단
	for (int i = 0; i < GAME_WIDTH; i++)
	{
		cout << "*";
	}
	// 인게임
	cout << endl;
	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		
		for (int j = 0; j < GAME_WIDTH; j++)
		{
			if (j == 0 || j == GAME_WIDTH - 1)
			{
			cout << "*";

			}
			else if (i == 6 && j == 10)
			{
				cout << "M";		// 뱀은 위치정보 필요하네? 위치정보 뭘로 만들까?
			}
			else
			{
				cout << " ";
			}
		}

		cout << endl;
	}

	// 하단
	for (int i = 0; i < GAME_WIDTH; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << endl;

	// 뱀 그리기
	
	


	// 과일 그리기
}

void CGameManager::Update()
{
	bool gameover;
	// 뱀 이동하기 호출
	gameover = false;

	// 과일 어떻게 먹었는지 알까(뱀이랑 사과가 행과 열이 같으면 과일을 먹은거다.)

	// 과일 생성
	int fruitX = rand() % 25 + 1;
	int fruitY = rand() % 25;
	int score = 0;
}

void CGameManager::GameRun()
{
	Init();

	// 게임실행
	while (true)
	{
		Draw();
		Input();
		Update();
		cout << "출력" << endl;
		Sleep(300);
	}
}
