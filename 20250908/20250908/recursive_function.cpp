#include <iostream>
#include <Windows.h>


using namespace std;


//int printText(int n)	//무한히 재귀한다. 하면 안된다.
//{
//	//재귀함수를 사용할 때는 정확한 반환 조건을 작성해 줘야 한다.
//	//무한히 반복하면 "호출스택"은 유한하기 때문에 프로그램이 터진다.
//	if (n <= 0)	
//	{
//		return 1;
//	}
//
//	cout << "printText" << endl;
//
//	printText(n - 1);
//}
//
//	// 게임 쿨타임 같은 것도 재귀로 만들 수 있다.
//int cooltimeCount(int time)
//{
//	if (time <= 0)
//	{
//		cout << "쿨타임이 끝났습니다.";
//		return 1;
//	}
//	else
//	{
//		cout << "쿨타임이" << time << "초 남았습니다." << endl;
//	}
//	Sleep(1000);
//	cooltimeCount(time - 1);
//}

int factorial(int n)
{
	if (n <= 0)
	{
		return 1;
	}
	else
	{
		return n *factorial(n - 1);
	}


}


int main()
{

	int n = 5;
	////printText(n);

	//if (cooltimeCount(n))
	//{
	//	cout << "파이어볼" << endl;
	//}



	cout << factorial(n) << endl;

	return 0;
}




//팩토리얼 만들어보자
//5! == 1 * 2 * 3 * 4 * 5