#include "BingoManager.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Ai.h"
#include "Player.h"

using namespace std;
using std::cout;
using std::cin;
using std::endl;

CBingoManager::CBingoManager()
{
	
}

CBingoManager::~CBingoManager()
{
	
}



void CBingoManager::BingoLineCount()
{
	

	if (*nPLineCount >= 5 && *nAiLineCount >= 5)
	{
		cout << "무승부입니다. 게임을 종료합니다." << endl;
		mIsGameOver = true;
	}
	else if (*nPLineCount >= 5)
	{
		//게임 종료 
		cout << "승리하셨습니다!! 게임을 종료합니다." << endl;
		mIsGameOver = true;
	}
	//AI 꺼 
	else if (*nAiLineCount >= 5)
	{
		//게임 종료 
		cout << "패배하였습니다ㅜㅜ 게임을 종료합니다." << endl;
		mIsGameOver = true;
	}

	
	

}

void CBingoManager::StarCheck()
{
	int StarCheck1 = 0, StarCheck2 = 0; // 한 줄에 별의 갯수를 센다. 
	int AiStarCheck1 = 0, AiStarCheck2 = 0; // 한 줄에 별의 갯수를 센다. 

	// 가로 세로 
	for (int i = 0; i < 5; ++i)
	{
		StarCheck1 = 0;
		StarCheck2 = 0;
		AiStarCheck1 = 0;
		AiStarCheck2 = 0;

		for (int j = 0; j < 5; ++j)
		{
			//가로줄 체크해봅시다. 
			if (nPBoard[i * 5 + j] == INT_MAX)
			{
				++StarCheck1;
			}
			//세로줄
			if (nPBoard[i + j * 5] == INT_MAX)
			{
				++StarCheck2;
			}

			//AI 꺼 
			if (nAiBoard[i * 5 + j] == INT_MAX)
			{
				++AiStarCheck1;
			}
			//세로줄
			if (nAiBoard[i + j * 5] == INT_MAX)
			{
				++AiStarCheck2;
			}

		}
		if (StarCheck1 == 5)
		{
			++nPLineCount;

		}
		if (StarCheck2 == 5)
		{
			++nPLineCount;
		}
		if (AiStarCheck1 == 5)
		{
			++nAiLineCount;

		}
		if (AiStarCheck2 == 5)
		{
			++nAiLineCount;
		}

	}

	//대간선 

	//오른쪽위 아래쪽아래 대각선 
	StarCheck1 = 0;
	AiStarCheck1 = 0;

	for (int i = 0; i < 25; i += 6)	// i 는 6씩 증가해야한다. 
	{
		if (nPBoard[i] == INT_MAX)
		{
			//대각선이 별이냐? 
			++StarCheck1;
		}
		//ai 꺼 
		if (nAiBoard[i] == INT_MAX)
		{
			//대각선이 별이냐? 
			++AiStarCheck1;
		}

	}
	if (StarCheck1 == 5)
	{
		++nPLineCount;
	}
	if (AiStarCheck1 == 5)
	{
		++nAiLineCount;
	}


	//왼쪽위 오른쪽아래 대각선 
	StarCheck1 = 0;
	AiStarCheck1 = 0;

	//인덱스 4로 시작해서 4씩 증가하고 20까지 검사해야한다. 
	for (int i = 4; i <= 20; i += 4)
	{
		if (nPBoard[i] == INT_MAX)
		{
			//대각선이 별이냐? 
			++StarCheck1;
		}

		if (nAiBoard[i] == INT_MAX)
		{
			//대각선이 별이냐? 
			++AiStarCheck1;
		}
	}

	if (StarCheck1 == 5)
	{
		++nPLineCount;
	}
	if (AiStarCheck1 == 5)
	{
		++nAiLineCount;
	}

}





void CBingoManager::GameRun()
{
	Init();
	Draw();

	Player p;
	Ai ai;

	// 게임실행
	while (!mIsGameOver)
	{
		                
		p.PlayerInput();

		BingoLineCount();

		if (mIsGameOver)
		{
			break;
		}
		
		
       ai.AiSelectTotalNumber();
        
		BingoLineCount();
        Draw();
		
	}

	cout << "게임이 종료되었습니다." << endl;
	system("pause");
}


void CBingoManager::Init()
{

	nPLineCount = 0;
	nAiLineCount = 0;
	mIsGameOver = false;


	srand((unsigned int)time(0));

	for (int i = 0; i < 25; i++)
	{
		nPBoard[i] = i + 1;
		nAiBoard[i] = i + 1;
	}

	for (int i = 0; i < 100; ++i)
	{
		int RandomIndex1 = rand() % 25;
		int RandomIndex2 = rand() % 25;
		int temp = 0;

		//스왑 
		temp = nPBoard[RandomIndex1];
		nPBoard[RandomIndex1] = nPBoard[RandomIndex2];
		nPBoard[RandomIndex2] = temp;

		//AI 꺼 
		RandomIndex1 = rand() % 25;
		RandomIndex2 = rand() % 25;
		temp = 0;

		//스왑 
		temp = nAiBoard[RandomIndex1];
		nAiBoard[RandomIndex1] = nAiBoard[RandomIndex2];
		nAiBoard[RandomIndex2] = temp;
	}
}

void CBingoManager::Draw()
{
	system("cls");

	
	
	cout << "================ 플레이어 ========================== 적 =======================" << endl;

	for (int i = 0; i < 5; ++i) // i 는 행
	{
		//플레이어 
		for (int j = 0; j < 5; ++j) // j 는 열 
		{

			if (nPBoard[i * 5 + j] == INT_MAX)
			{
				cout << "*\t";
			}
			else
			{
				cout << nPBoard[i * 5 + j] << "\t";
			}
		}

		///경계선 그려주기 
		cout << "||\t";

		//적 AI 
		for (int j = 0; j < 5; ++j) // j 는 열 
		{

			if (nAiBoard[i * 5 + j] == INT_MAX)
			{
				cout << "*\t";
			}
			else
			{
				cout << nAiBoard[i * 5 + j] << "\t";
			}
		}


		cout << endl;//줄바꿈
	}

	// 결과 출력 
	cout << "빙고 갯수 : " << nPLineCount;
	cout << "\t\t\t\t\t빙고 갯수 : " << nAiLineCount << endl;
}


