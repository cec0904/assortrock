#include <iostream>
using namespace std;

struct sCalculateResult
{
	int addResult;
	int subResult;
	int mulResult;
	float divResult;
	int remainResult;

	void printCalculate()
	{
		cout << addResult << endl;
		cout << subResult << endl;
		cout << mulResult << endl;
		cout << divResult << endl;
		cout << remainResult << endl;
	}

	// operator 연산자를 따로 만들면 배열처럼 접근 가능할수도 있다.
	// 직접 만들어야 한다.



};

using CCR = sCalculateResult;


void Calculate(int _n1, int _n2, CCR& result)
{
	result.addResult = _n1 + _n2;
	result.subResult = _n1 - _n2;
	result.mulResult = _n1 * _n2;
	result.divResult = _n1 / _n2;
	result.remainResult = _n1 % _n2;
}

int main()
{
	CCR result; // 객체

	Calculate(3, 4, result);

	result.printCalculate();

	return 0;
}