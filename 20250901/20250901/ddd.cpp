#include <iostream>

using namespace std;

int main()
{

	for (int i = 1; i < 5; i++)
	{

		for (int j = 4 - i; j > 0; j--)
		{
			cout << " ";
		}
		for (int k = 0; k < 2 * i - 1; k++)
		{
			cout << "*";
		}
		for (int j = 4 - i; j > 0; j--)
		{
			cout << " ";
		}

		cout << '\n';
	}
}