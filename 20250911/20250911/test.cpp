#include <iostream>
using namespace std;


/*
	call by value
	call by address
	call by reference

	참조도 포인터랑 비용차이가 없다
*/


void Func(int _n/*call by value*/, int* _pn/*call by address*/, int& _rn/*call by reference*/)
{
	_rn = 900;
}

int main()
{
	int number = 100;
	Func(number, &number, number);

	return 0;
}