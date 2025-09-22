#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<vector<int>> Board(10, vector<int>(15, 0));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			
			if (i == 0 || i == 9)
			{
				Board[i][j] = 0;
			}
			else
			{
				Board[i][j] = 1;
			}
			if (j == 0 || j == 14)
			{
				Board[i][j] = 0;
			}
			
			cout << Board[i][j] << " ";
		}
		cout << endl;

	}





}