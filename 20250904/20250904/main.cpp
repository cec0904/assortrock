/*
	// 실습
	// 로또 프로그램 만들어보자

	// 로또번호 1 ~ 45 사이에 번호를 출력해보자
	// 로또 1등 번호 6개 출력하고, 보너스 번호 1개 출력해보자
	// 결과는 랜덤한 중복 없는 숫자
	// 결과
	// 1등 당첨 번호 : 1 2 3 4 5 6
	// 보너스 번호 7


*/

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;


// int r = rand() % 10;

int main()
{
	srand((unsigned int)time(0));

	int lotto[7] = {};


	for (int i = 0; i < 7; i++)
	{
		lotto[i] = rand() % 45 + 1;
		for (int j = 0; j < i; j++)
		{
			if (lotto[i] == lotto[j])
			{
				i--;
				break;
			}
		}
	}

	cout << "로또 번호는 : ";
	cout << lotto[0] << " " << lotto[1] << " " << lotto[2] << " " << lotto[3] << " " << lotto[4] << " " << lotto[5] << endl;
	
	cout << "보너스 번호는 : ";
	cout << lotto[6];

	cout << '\n';
	cout << '\n';





}