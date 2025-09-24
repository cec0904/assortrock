/*
	파일 입출력

	적어준 순서대로 읽어온다.

	// 암기
	절대 경로 -> E:\SVN\cec0904\20250924\20250924 경로를 루트에서 부터 다 적어주는거

	상대 경로 -> 특정 폴더부터 시작하는 경로
*/

#include <iostream>
#include <vector>
#include <string>
#include <direct.h>		// 폴더 관련된 함수를 사용할 수 있다.
						// _mkdir -> window 전용이다.
						// mkdir 도 가능이다.

using namespace std;

// 플레이어 정보
struct PlayerInfo
{
	string name;
	string job;
	int money;
};



//이것은 c 스타일이다.
int main()
{
	PlayerInfo player1 = { "전의찬", "전사", 1000 };

	// FILE
	FILE* pFile = nullptr;
	/*
		3번째 매개변수로 읽기쓰기 모드가 있는데
		어떤 모드인지에 따라서 덮어씌울건지 아님 변경내용만 저장할 건지 선택할 수 있다.
		읽기 일때도 마찬가지다.
		w : 쓰기 -> 매번 새로 작성
		r : 읽기
		wb : 바이너리 파일로 만들것이다.
		rb : 바이너리 파일을 읽을것이다.
	*/
	// error_t
	// 절대 경로로 만들어 줄 수 있다
	string path = "C:\\Users\\assortrock\\Downloads";
	_mkdir(path.c_str());
	path += "\\PlayerData.txt";


	int err = fopen_s(&pFile, path.c_str(), "w");	// 파일은 열기
	//int err = fopen_s(&pFile, "PlayerData.txt", "w");	//작업중인 프로젝트 폴더에 파일이 생성된다.
	if (err == 0)	// error -> 0 이면 error 가 없는거다
		// 만약에 0말고 다른 값이 나오면 검색화면에 왜 오류가 나오는지 나온다.
	{
		// 내용을 작성해보자
		// printf(); -> 
		// 문자열 함수를 사용할 때 std::string 아닌 char*
		fprintf(pFile, "%s\n", player1.name.c_str());
		fprintf(pFile, "%s\n", player1.job.c_str());
		fprintf(pFile, "%d\n", player1.money);
		fprintf(pFile, "우리는 파일 입출력을 하고있습니다.");
		// FILE 이 친구도 꼭 다 사용하고나서 종료해줘야 한다.
		fclose(pFile);		//동적할당이랑 같다고 생각하면 된다.
		pFile = nullptr;
	}

		// 불러오기
	player1 = {};
		err = fopen_s(&pFile, path.c_str(), "r"); // 파일 열기
		if (err == 0)
		{
			// 데이터 받아 올 공간이 필요하다.
			char nameBuffer[255];
			char jobBuffer[255];


			fscanf_s(pFile, "%s", nameBuffer, sizeof(nameBuffer));
			player1.name = nameBuffer;
			fscanf_s(pFile, "%s", jobBuffer, sizeof(jobBuffer));
			player1.job = jobBuffer;


			/*fscanf_s(pFile, "%s", nameBuffer, player1.name, player1.name.length());
			fscanf_s(pFile, "%s", jobBuffer, player1.job, player1.job.length());*/
			

			/*fscanf_s(pFile, "%s", player1.name, player1.name.length());
			fscanf_s(pFile, "%s", player1.job, player1.job.length());*/


			fscanf_s(pFile, "%d", &player1.money);
			fclose(pFile);
		}



		return 0;

}

