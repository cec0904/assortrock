#include <iostream>
#include <time.h>
using namespace std;







int main()
{
	srand((unsigned int)time(0));

	int nBoard[50] = {};

	for (int i = 0; i < 50; i++)
	{
		nBoard[i] = i + 1;
	}

	for (int i = 0; i < 100; i++)
	{
		int randomIndex1 = rand() % 50;
		int randomIndex2 = rand() % 50;
		int temp = 0;

		temp = nBoard[randomIndex1];
		nBoard[randomIndex1] = nBoard[randomIndex2];
		nBoard[randomIndex2] = temp;
	}

	bool gameEnd = false;

	while (!gameEnd)
	{

	}


}