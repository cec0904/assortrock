#include <iostream>
#include <string>
#include <direct.h>

//c++ 파일 입출력 만들고싶다
#include <fstream>
using namespace std;

struct PlayerInfo
{
	string name;
	string job;
	int money;
};



int main()
{

	// 자료형 File 변수명(경로)
	ofstream oFile("PlayerDataCPP.txt");
	PlayerInfo player1{"의찬", "성기사", 1000};

	if (oFile.is_open())	// 파일오픈을 성공하면 true, 실패하면 false
	{
		// 형식이 cout
		oFile << player1.name << endl;	// 한 데이터를 지금은 줄바꿈으로 하는 것이다.
		oFile << player1.job << endl;
		oFile << player1.money << endl;

		oFile.close();
	}

	player1 = {};
	ifstream iFile{ "PlayerDataCPP.txt" };

	if (iFile.is_open())
	{
		// 줄바꿈으로 구분되었으니
		// 한줄씩 다 가져와서 데이터를 가져온다.
		// 문자열 가져오는 방식
		getline(iFile, player1.name);
		getline(iFile, player1.job);

		iFile >> player1.money;

		iFile.close();
	}





	return 0;
}