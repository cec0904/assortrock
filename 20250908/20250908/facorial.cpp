#include <iostream>

using namespace std;

int FactorialFunc(int _n)
{
	
	if (_n == 1)
	{
		return 1;
	}
	
	int fresult = _n * FactorialFunc(_n - 1);
	
	return fresult;
}

int main()
{
	int number = 0;
	cin >> number;


	cout << FactorialFunc(number);

	return 0;
}