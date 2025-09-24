#include <iostream>
#include <string>
#include <direct.h>	//경로에 폴더를 만들기 위해서 사용한다. 

using namespace std;

//플레이어 정보
struct PlayerInfo
{
	string name;
	string job;
	int money;
};

int main()
{
	PlayerInfo player1 = { "전의찬", "궁수", 2000 };
	//PlayerInfo player1 = {};

	//저장하기 
	//지금은 상대 경로롤 만들것이다. 
	FILE* pFile = nullptr;
	int err = fopen_s(&pFile, "PlayerDataＢ.txt", "wb"); //w가 아닌 바이너리를 쓰는거기때문에 wb를 적어준다. 
	if (err == 0)
	{
		int nameLength = player1.name.length();
		//바이너리는 fwrite 함수를 사용한다. 
		//앞에서부터 얼마나 읽을것인지 저장해준것이다. 
		fwrite(&nameLength, sizeof(int), 1, pFile);	//어떤 데이터를 넣을건지, 데이터의 자료형, 데이터의 갯수, 저장할 파일
		fwrite(player1.name.c_str(), sizeof(char), nameLength, pFile);	// 플레이어의 이름 저장, 문자형, 이름길이만큼 저장, pFile 에다가

		//직업저장
		int jobLength = player1.job.length();
		fwrite(&jobLength, sizeof(int), 1, pFile);
		fwrite(player1.job.c_str(), sizeof(char), jobLength, pFile);

		//돈 저장 
		fwrite(&player1.money, sizeof(int), 1, pFile);

		fclose(pFile);
		pFile = nullptr;
	}

	//불러오기 
	err = fopen_s(&pFile, "PlayerDataB.txt", "rb");

	// 이름길이.이름.직업길이.직업.돈
	if (err == 0)
	{
		//fread 
		//이름
		int nameLength = 0;
		fread(&nameLength, sizeof(int), 1, pFile);

		char nameBuffer[255];
		fread(nameBuffer, sizeof(char), nameLength, pFile);
		nameBuffer[nameLength] = '\0';
		player1.name = nameBuffer;

		//직업 
		int jobLength = 0;
		fread(&jobLength, sizeof(int), 1, pFile);

		char jobBuffer[255];
		fread(jobBuffer, sizeof(char), jobLength, pFile);
		jobBuffer[jobLength] = '\0';
		player1.job = jobBuffer;

		//돈
		fread(&player1.money, sizeof(int), 1, pFile);

		fclose(pFile);
	}



}