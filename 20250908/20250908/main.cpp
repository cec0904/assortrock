/*
	구조체
	-> 여러 종류의 데이터를 하나의 데이터로 묶어서 사용할 수 있는 자료형이다.

	예를 들어서 민증
	이름
	번호
	주소
	를 각각 선언하는게 아니고 하나의 묶음으로 선언 할 수 있다.

	struct

	사용자 정의 자료형

*/

struct PID
{
	char name[20];		//1바이트
	int ID;				//4바이트
	char address[128];	//1바이트
};

struct SID
{
	char name[20];
	int ID;
	int LS;
	int ES;
	int MS;
	int SUM;
};



#include <iostream>

using namespace std;

int main()
{

	//PID id;
	//cout << "이름을 입력하세요 : ";
	//cin >> id.name;
	//cin.ignore(1000, '\n');

	//cout << "주민번호를 입력하세요 : ";
	//cin >> id.ID;
	//cout << "주소를 입력하세요 : ";
	//cin >> id.address;

	//cout << endl << endl;

	//cout << "이름 : " << id.name << endl;
	//cout << "주민번호 : " << id.ID << endl;
	//cout << "주소 : " << id.address << endl;

	//cout << endl << endl;

	//PID ids[3];

	//for (int i = 0; i < 3; i++)
	//{
	//	cout << "이름을 입력하세요 : ";
	//	cin >> ids[i].name;
	//	cin.ignore(1000, '\n');

	//	cout << "주민번호를 입력하세요 : ";
	//	cin >> ids[i].ID;
	//	cout << "주소를 입력하세요 : ";
	//	cin >> ids[i].address;

	//	cout << endl << endl;

	//	cout << "이름 : " << ids[i].name << endl;
	//	cout << "주민번호 : " << ids[i].ID << endl;
	//	cout << "주소 : " << ids[i].address << endl;
	//}

	///////
	// 학생정보 만들어보기
	// 이름
	// 학번
	// 국어
	// 영어
	// 수학
	// 점수합계
	// 입력 받아서 출력하기
	// 배열로 3명정도

	SID idd[3];
	for (int i = 0; i < 3; i++)
	{



		cout << "이름을 입력하세요 : ";
		cin >> idd[i].name;

		cout << "학번을 입력하세요 : ";
		cin >> idd[i].ID;

		cout << "국어점수를 입력하세요 : ";
		cin >> idd[i].LS;

		cout << "영어점수를 입력하세요 : ";
		cin >> idd[i].ES;

		cout << "수학점수를 입력하세요 : ";
		cin >> idd[i].MS;

		cout << endl << endl;
		
		idd[i].SUM = idd[i].LS + idd[i].ES + idd[i].MS;

		cout << "이름 : " << idd[i].name << endl;
		cout << "학번 : " << idd[i].ID << endl;
		cout << "국어점수 : " << idd[i].LS << endl;
		cout << "영어점수 : " << idd[i].ES << endl;
		cout << "수학점수 : " << idd[i].MS << endl;
		cout << "점수합계 : " << idd[i].SUM << endl;

		cout << endl << endl;
		
	}
	



}