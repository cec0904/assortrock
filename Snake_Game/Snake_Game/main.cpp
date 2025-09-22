#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>

using namespace std;

void HideCursor()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Input()
{
	if (_kbhit())
	{
		cout << "키보드가 눌렸습니다." << endl;
		int getkey = _getch();	//아스키코드로 나온다.
		cout << (char)getkey << endl;

		switch (getkey)
		{
		case 'w':

			//위
			break;
		case 'a':
			//왼쪽
			break;
		case 's':
			//아래
			break;
		case 'd':
			//오른쪽
			break;
		}
	}
}

void Draw()		// 보드판 그리기
{
	system("cls");

	


	for (int i = 0; i < 30; i++)
	{
		cout << "#" ;
	}

	cout << endl;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			if (j == 29)
			{
				cout << "#" << endl;
				break;
			}
			cout << " ";
			
		}
	}

	for (int i = 0; i < 30; i++)
	{
		cout << "#";
	}

	cout << endl;

}

void Snake(int x, int y)
{
	
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);


}

void Fruit(int fruitX, int fruitY)
{
	fruitX = rand()%28 + 1;
	fruitY = rand()%18 + 1;
	cout << "@";
}

int main()
{
	while (true)
	{
		HideCursor();
		Draw();
		Input();
		Fruit(10, 10);
		cout << "출력" << endl;
		Sleep(300);
	}
}