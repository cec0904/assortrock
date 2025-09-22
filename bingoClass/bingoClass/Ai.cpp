#include <iostream>
#include "Ai.h"
#include "BingoManager.h"

using namespace std;




void Ai::AiSelectTotalNumber(int* nPBoard, int* nAiBoard, int* nPLineCount, int* nAiLineCount)
{

	int AiSelectTotalNumber = 0;

	
	

	for (int i = 0; i < 25; ++i)
	{
		if (nAiBoard[i] != INT_MAX)
		{
			AiSelect[AiSelectTotalNumber] = nAiBoard[i];
			++AiSelectTotalNumber;
		}
	}

	int AiSelectIndex = rand() % 25;
	int AiInput = AiSelect[AiSelectIndex];

	cout << "AI가 선택한 숫자는? : " << AiInput << endl;
	system("pause");

	for (int i = 0; i < 25; ++i)
	{
		//플레이어 
		if (nPBoard[i] == AiInput)
		{
			nPBoard[i] = INT_MAX;
		}
		// AI 
		if (nAiBoard[i] == AiInput)
		{
			nAiBoard[i] = INT_MAX;
		}
	}

	nPLineCount = 0;
	nAiLineCount = 0;
}


