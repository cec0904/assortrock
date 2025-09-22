#include <iostream>
#include "Player.h"
#include "BingoManager.h"


using namespace std;

CBingoManager bingoManager;



void Player::PlayerInput()
{
	
	int input = 0;
	cout << "숫자를 입력하세요 (0 입력하면 종료): ";
	cin >> input;

	if (input == 0)
	{
		cout << "게임을 종료합니다." << endl;
		system("pause");
		return;
	}
	else if (input <= 0 || input > 25)	// 1보다 작거나 또는 25보다 크면
	{
		cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
		system("pause");
		// 다시 입력칸으로 가기
	}

	for (int i = 0; i < 25; ++i)
	{
		//플레이어 
		if (bingoManager.nPBoard[i] == input)
		{
			bingoManager.nPBoard[i] = INT_MAX;
		}
		// AI 
		if (bingoManager.nAiBoard[i] == input)
		{
			bingoManager.nAiBoard[i] = INT_MAX;
		}
	}

	

}






