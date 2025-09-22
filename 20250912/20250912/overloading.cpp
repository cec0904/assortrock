/*
	함수 오버로딩 overloading
	-> 같은 이름의 함수를 "매개변수에따라" 구분하는 것이다.

	같은 이름으로 함수를 만드는 조건

	1. 매개변수의 타입이 다르면 된다.
	2. 매개변수의 갯수가 다르면 된다.

	3. 매개변수의 순서가 다르면 된다.

*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#pragma region 덧셈
int AddFunc(int a, int b)
{
	cout << "나는 int 매개변수가 2개야" << endl;
	return a + b;
}

//float AddFunc(int a, int b)		// 반환값은 상관 없다. 무조건 매개변수에 따라 달라진다.
//{
//
//}

int AddFunc(int a, int b, int c)
{
	cout << "나는 int 매개변수가 3개야" << endl;
	return a + b + c;
}

float AddFunc(float a, float b, float c)
{
	cout << "나는 float 매개변수가 3개야" << endl;
	return a + b + c;
}
#pragma endregion

#pragma region 뺄셈
int sub(int a, int b)
{
	return a - b;
}

int sub(float a, float b)
{
	return a - b;
}

int sub(double a, double b)
{
	return a - b;
}
#pragma endregion

#pragma region 곱셈

int MulFunc(int a, int b)
{
	int result = a * b;
	cout << result << endl;
	return 0;
}
int MulFunc(float a, float b)
{
	float result = a * b;
	cout << result << endl;
	return 0;
}
int MulFunc(double a, double b)
{
	double result = a * b;
	cout << result << endl;
	return 0;
}
int MulFunc(char a, char b)
{
	char result = a * b;
	cout << result << endl;
	return 0;
}



#pragma endregion

#pragma region 나눗셈

int DivFunc(int a, int b)
{
	int result = a / b;
	cout << result << endl;
	return 0;
}
int DivFunc(float a, float b)
{
	float result = a / b;
	cout << result << endl;
	return 0;
}
int DivFunc(double a, double b)
{
	double result = a / b;
	cout << result << endl;
	return 0;
}
int DivFunc(char a, char b)
{
	char result = a / b;
	cout << result << endl;
	return 0;
}
#pragma endregion

int main()
{
	AddFunc(1, 2);
	AddFunc(3, 4, 5);
	AddFunc(1.f, 2.f, 3.f);

	
	//strcpy_s()


	// 곱셈 나눗셈 함수 오버로딩 int float double char 종류별로


	MulFunc(3, 5);
	MulFunc(3.2, 5.3);
	MulFunc(3, 5);
	MulFunc(3, 5);

	return 0;
}
