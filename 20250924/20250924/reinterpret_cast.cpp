#include <iostream>
#include <vector>
#include <string>
#include <direct.h>
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
	PlayerInfo player1;

	ofstream oFile("PlayerDataCppBinary.txt");
	if (oFile.is_open())
	{
		// 이름 저장
		size_t nameLength = player1.name.length();
		oFile.write(reinterpret_cast<char*>(&nameLength), sizeof(size_t));
		oFile.write(player1.name.c_str(), nameLength);

		// 직업 저장
		size_t jobLength = player1.job.length();
		oFile.write(reinterpret_cast<char*>(&jobLength), sizeof(size_t));
		oFile.write(player1.job.c_str(), jobLength);

		// 돈 저장
		oFile.write(reinterpret_cast<char*>(&player1.money), sizeof(int));
		oFile.close();
	}


	// 불러오기
	player1 = {" "," ", 0};
	ifstream iFile("PlayerDataCppBinary.txt");

	if (iFile.is_open())
	{

		// 이름
		size_t nameLength = 0;
		iFile.read(reinterpret_cast<char*>(&nameLength), sizeof(size_t));
		vector<char> nameBuffer(nameLength);
		iFile.read(nameBuffer.data(), nameLength);
		player1.name.assign(nameBuffer.begin(), nameBuffer.end());

		// 직업
		size_t jobLength = 0;
		iFile.read(reinterpret_cast<char*>(&jobLength), sizeof(size_t));
		vector<char> jobBuffer(jobLength);
		player1.job.assign(jobBuffer.begin(), jobBuffer.end());

		iF

	}








	return 0;
}