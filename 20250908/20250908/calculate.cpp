#include <iostream>
using namespace std;


struct calResult // 계산 결과를 저장하는 구조체
{
	int addResult = 0;
	int subResult = 0;
	int mulResult = 0;
	int divResult = 0;
	int remResult = 0;
};

calResult allCalResultFunc(int _num1, int _num2)
{
	calResult sResult;
	// 더하기
	sResult.addResult = _num1 + _num2;

	// 빼기
	sResult.subResult = _num1 - _num2;
	
	// 곱하기
	sResult.mulResult = _num1 * _num2;

	// 나누기
	// 나누는 수가 0이 아닌 경우만
	if (_num2 != 0)
	{
		sResult.divResult = _num1 / _num2;
	}
	else
	{
		sResult.divResult = 0;
	}

	// 나머지
	if (0 == _num2)	//요다 표기법 : =, == 실수를 방지하고자 나온 법칙 중 하나
	{
		sResult.remResult = 0;
	}
	else
	{
		sResult.remResult = _num1 % _num2;
	}

	return sResult;

}



int main()
{
	calResult result = allCalResultFunc(10, 5);
	cout << result.addResult << endl;
	cout << result.subResult << endl;
	cout << result.mulResult << endl;
	cout << result.divResult << endl;
	cout << result.remResult << endl;


}