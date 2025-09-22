#include <iostream>
using namespace std;

struct game
{
	int pBingo[25] = { };
	int LineCount = 0;
	int input = 0;		// 플레이어 숫자뽑기


	int aiBingo[25] = { };
	int aiLineCount = 0;		// 빙고 완성 카운트
	int aiSelect[25] = {};		// 중복숫자 없애기 용도 
	int aiSelectTotalNum = 0;	// ai 가 선택할 수 있는 숫자개수
};



// 숫자 랜덤 생성
game createNumber()
{
	game sNumber;

	srand((unsigned int)time(0));

	for (int i = 0; i < 25; i++)
	{
		sNumber.pBingo[i] = i + 1;
		sNumber.aiBingo[i] = i + 1;
	}

	for (int i = 0; i < 100; ++i)
	{
		int RandomIndex1 = rand() % 25;
		int RandomIndex2 = rand() % 25;
		int temp = 0;

		//스왑 
		temp = sNumber.pBingo[RandomIndex1];
		sNumber.pBingo[RandomIndex1] = sNumber.pBingo[RandomIndex2];
		sNumber.pBingo[RandomIndex2] = temp;

		//AI 꺼 
		RandomIndex1 = rand() % 25;
		RandomIndex2 = rand() % 25;
		temp = 0;

		//스왑 
		temp = sNumber.aiBingo[RandomIndex1];
		sNumber.aiBingo[RandomIndex1] = sNumber.aiBingo[RandomIndex2];
		sNumber.aiBingo[RandomIndex2] = temp;
	}

	return sNumber;		// 왜 sNumber 를 리턴할까

}




// 숫자 보드판 위에 띄우기
game createBoard()
{

}



// 플레이어 숫자 선택



// ai 숫자 선택

// 빙고가 맞는지 줄에 별 개수 세기


// 빙고 됐을 때 빙고 줄 개수 세기


// 대각선 빙고 개수 세기


// 게임 종료 조건 만들기








int main()
{
	game game = createNumber();

	for (int i = 0; i < 25; i++)
	{
		cout << game.aiBingo[i] << endl;

	}
}