#include <iostream>
using namespace std;

// 디버깅
// 중단점 찍기
// 
// 



///////////////
// for 문 하면 별찍기다.
/*
	1. 별 5*5

	2. 5에서 줄어들기

	3. 1에서 늘어나기



*/


int main()
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << "*****" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	






	for (int j = 0; j < 5; j++)
	{

		for (int j = 5 - j; j > 0; --j)
		{
			cout << "*";
		}
		cout << endl;

	}


	std::cout << std::endl;
	std::cout << std::endl;




	for (int i = 0; i < 5; i++)
	{
		for (int j = 4-i; j > 0; j--)
		{
			cout << " ";
			
		}

		
		for (int k = 0; k <= i; k++)
		{
			cout << "*";
		}
		cout << endl;
	}

	
		for (int i = 0; i < 5; i++)
		{

			for (int j = 4-i; j > 0; j--)
			{
				cout << "o";
			}
			for (int k = 0; k <= 2*i-1; k++ )
			{
				cout << "*";
			}
			for (int j = 4-i; j > 0; j--)
			{
				cout << "o";
			}

			cout << '\n';
		}

}