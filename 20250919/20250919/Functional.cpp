#include <iostream>
#include <vector>

// 다양한 종류의 함수를 하나의 타입으로 묶어주는 함수 포인터타입
#include <functional>
// std::function<반환타입(매개변수 타입들)> 변수명;


using namespace std;

inline void PrintFun()
{
	cout << "우리는 functional 이용해서 출력할게요!" << endl;
}

float PrintTwoFloat(float _f1, float _f2)
{
	cout << "첫번째 인자 : " << _f1 << " 두번째 인자 : " << _f2 << endl;

	return _f1 + _f2;
}


// 클래스 멤버 함수
class Calculator
{
public:
	void PrintFunc()
	{
		cout << "계산기 그리기" << endl;
	}


	int add(int _n1, int _n2)
	{
		return _n1 + _n2;
	}

	float sub(int _n1, float _n2)
	{
		return _n1 - _n2;
	}

};


int main()
{
	function<void()> pFunc;	// void(*pFunc)();
	pFunc = PrintFun;
	pFunc();

	function<float(float, float)> pPrintTwoFloat;
	pPrintTwoFloat = PrintTwoFloat;
	pPrintTwoFloat(1.2f, 3.4f);

	float sum = pPrintTwoFloat(1.2f, 3.4f);
	cout << sum << endl;

	// 클래스 함수
	Calculator cal;

	// 멤버함수 function
	function<int(int, int)> pAddFunc;
	pAddFunc = bind(&Calculator::add, &cal, placeholders::_1, placeholders::_2);

	/*
		std::placeholders::숫자
		순서대로 작성해야 매개변수 데이터가 넣은 순서대로 출력된다.
		만약 순서가 바뀌면 함수에 들어온 매개변수의 데이터도 순서가 바뀌게 된다.
	*/






	pAddFunc = bind(&Calculator::add, &cal, placeholders::_1, placeholders::_2);
	cout << pAddFunc(20, 30) << endl;

	function<void()> pPrintFunc;
	pPrintFunc = bind(&Calculator::PrintFunc, &cal);
	pPrintFunc();

	function<float(int, float)> pSubFunc;
	pSubFunc = bind(&Calculator::sub, &cal, placeholders::_1, placeholders::_2);
	cout << pSubFunc(5, 3.7) << endl;



	// 배열에도 선언이 가능하다.
	vector<function<float(int, float)>> funcArray;
	funcArray.push_back(pSubFunc);
	funcArray.resize(3);

	
	cout << funcArray[0](5,3.2) << endl;
	
	







	return 0;
}