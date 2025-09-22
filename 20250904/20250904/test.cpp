/*
	실습 짝수 맞추기
	문제설명
	1~10 까지 숫자가 2개씩 존재한다.
	숫자를 골고루 섞어준다.
	*을 10 x 2로 출력한다.
	사용자는 2개의 인덱스를 입력해서
	2개의 인덱스 값이 같은경우 해당 부분은 숫자로 출력한다
	10개의 페어를 맞추면 게임이 종료된다.

*/

/*
	0	1	2	3	4	5	6	7	8	9
	*	3	3	*	*	*	*	*	*	*

	10	11	12	13	14	15	16	17	18	19
	*	*	*	*	*	*	*	*	*	*
*/

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;
int main() 
{
	srand((unsigned int)time(0));

	int nNumber[20]{};
	int nNumbers[20]{};

	for (int i = 0; i < 10; i++)
	{
		nNumbers[i] = i + 1;
		nNumbers[i + 10] = i + 1;
	}


	int a = 0, b = 0, temp = 0;
	for (int i = 0; i < 100; i++)
	{
		a = rand() % 10+1;
		b = rand() % 10+1;

		temp = nNumbers[a];
		nNumbers[a] = nNumbers[b];
		nNumbers[b] = temp;
	}

	for (int i = 0; i < 20; i++)
	{
		nNumber[i] = nNumbers[i];
	}

	


	for (int i = 0; i < 10; i++)
	{
		cout << nNumber[i] << " ";
	}
	cout << endl;
	for (int i = 10; i < 20; i++)
	{
		cout << nNumber[i] << " ";
	}

	cout << endl;
	cout << endl;

	int p = 0, q = 0;


	cout << "인덱스를 입력하세요 : ";
	cin >> p >> q;
	cout << endl;
	int count = 0;
	if (nNumber[p] == nNumber[q])
	{
		count++;
	}








	//char Card[] = {'1','2','3','4','5','6','7','8','9','10','1','2','3','4','5','6','7','8','9','10'};
	//char nCard[20]{};
	//int a = 0, b = 0;
	//char mix[20]{};

	//for (int i = 0; i < 100; i++)
	//{
	//	mix = nCard[a];
	//	nCard[a] = nCard[b];
	//	nCard[b] = mix;
	//}

	//for (int i = 0; i < 20; i++)
	//{
	//	Card[i] = nCard[i];
	//	cout << Card[i];
	//}













}