// 숫자 입력받고 숫자 맞추기 큰지 작은지 알려주는 게임

#include <iostream>
#include <Windows.h>
using namespace std;



// 선택한 숫자
int playerSelectNumber = 0;
// 랜덤 숫자
int RandomNumber = 0;
int trycount = 0;

void Random()
{
	srand((unsigned int)time(0));

	// 랜덤숫자받기
	RandomNumber = rand() % 100 + 1; // 1 ~ 100 사이의 숫자를 생성


}

void checkNumber()
{
	// 입력받기
	cout << "1 부터 100까지의 숫자를 맞춰보세요 : ";
	cin >> playerSelectNumber;


	if (playerSelectNumber > RandomNumber)
	{
		cout << "DOWN 입니다." << endl;
		trycount++;

	}
	else if (RandomNumber > playerSelectNumber)
	{
		cout << "UP 입니다." << endl;
		trycount++;

	}
	else
	{
		cout << "정답입니다. 게임종료" << endl << "시도횟수 : " << trycount + 1 << endl;
		return;
	}
}

void endNumber()
{

	// 숫자체크
	while (true)
	{
		checkNumber();
		if (playerSelectNumber == RandomNumber)
		{
			break;
		}
	}
	return;

}




int main()
{
	Random();
	endNumber();
}