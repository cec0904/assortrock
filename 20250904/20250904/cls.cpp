#include <iostream>

using namespace std;

int main()
{
	int count = 0;
	while (true)
	{
		if (count % 5 == 0)
		{
			system("cls");		// 콘솔을 모두 지운다. 콘솔 그려져 있는 것을 모두 없앤다
			system("pause");	// 콘솔을 다음 입력전까지 멈추는 명령어
		}

		cout << "출력중 입니다 !!" << endl;

	}
}