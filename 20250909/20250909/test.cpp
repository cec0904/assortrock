// 전역변수와 함수 이용해서 계산결과 각각 가져오기 
// calcultate 함수 : 전역변수로 사칙연산 결과받기 
// resultPrint 함수 : 사칙연산 결과 출력하기


#include <iostream>

using namespace std;


int addResult = 0;
int subResult = 0;
int mulResult = 0;
int divResult = 0;
int remResult = 0;

// 반환값이 필요없다
// 전역변수를 쓰면 반환값이 필요없다
void calculateFunc(int a = 0, int b = 0)
{
	addResult = a + b;
	subResult = a - b;
	mulResult = a * b;

	if (b == 0)
	{
		divResult = 0;
	}
	else
	{
		divResult = a / b;
	}


	if (b == 0)
	{
		remResult = 0;
	}
	else
	{
		remResult = a % b;
	}
}

void resultPrintFunc()
{
	cout << "덧셈 결과: " << addResult << endl;
	cout << "뺄셈 결과: " << subResult << endl;
	cout << "곱셈 결과: " << mulResult << endl;
	cout << "나눗셈 결과: " << divResult << endl;
	cout << "나머지 결과: " << remResult << endl;
}

int main()
{
	int a = 0, b = 0;
	cout << "두 수를 입력하세요 : ";
	cin >> a >> b;

	calculateFunc(a, b);
	resultPrintFunc();

	return 0;

}