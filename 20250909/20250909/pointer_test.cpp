#include <iostream>
using namespace std;


void SetArray(int* arr, int arrsize)
{
	for (int i = 0; i < arrsize; i++)
	{
		*(arr + i) = i;
	}
}

//void arrPrint(int* arr, int arrsize)
//{
//	for (int i = 0; i < arrsize; i++)
//	{
//		cout << *(arr + i) << endl;
//	}
//}


void arrPrint(int arr[], int arrsize)	// 명시적으로 배열 받는다고 표현할 수도 있다.
{
	for (int i = 0; i < arrsize; i++)
	{
		cout << *(arr + i) << endl;
	}
}



int main()
{
	//int numbers[10]{};

	//// 배열 데이터 접근할 때 사용하는 연산자는 []
	//numbers[0];

	//// *(numbers + 0); == numbers[0] 이 둘은 같은 의미이다. 그래서 배열시작은 0부터 시작하는 것이다.

	//numbers[1] == *(numbers + 1);




	int numbers[5] = { 1,2,3,4,5 };
	int* pArray = numbers;

	cout << "numbers의 주소 : \t" << &numbers << endl;
	cout << "pArray 주소 : \t\t" << pArray << endl;
	cout << "numbers[0]의 주소 : \t" << &numbers[0] << endl;
	cout << "numbers[0]의 주소 : \t" << numbers + 1 << endl;
	cout << "numbers[0]의 주소 : \t" << &numbers[2] << endl;
	cout << "numbers[0]의 주소 : \t" << &numbers[3] << endl;
	cout << "numbers[0]의 주소 : \t" << &numbers[4] << endl;


	// const 상수화 시킨다.
	// 상수는 변하지 않는거

	const int ArraySize = 5;
	int count = 9;
	int numArray[ArraySize] = {};	// 상수를 넣어야 한다


	arrPrint(numArray, ArraySize);


	SetArray(numArray, ArraySize);		// 배열은 포인터이기 때문에 값을 넣어줄 때 &을 안붙여줘도 된다.


	arrPrint(numArray, ArraySize);


	return 0;
}