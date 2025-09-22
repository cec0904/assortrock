#include <iostream>
using namespace std;

enum printType
{
	NAME,
	ID,
	KOR,
	ENG,
	MATH,
};

struct StudentInfo
{
	//이름
	char name[20] = "";
	//학번
	int ID = 0;
	//국어
	int kor = 0;
	//영어
	int eng = 0;
	//수학
	int math = 0;
	//총합
	int total = 0;
	//평균
	float avg = 0.f;
};

// 함수 프로토타입 선언
// 컴파일러에게 이런 함수가 있어 라고 알려줌

void printInput(printType _type);
void PrintStudentInfo(StudentInfo _info);

StudentInfo InputStudentInfo(/*매개변수 꼭 넣을 필요 없음*/)
{
	StudentInfo info;
	
	//이름
	printInput(printType::NAME);
	cin >> info.name;
	//학번
	printInput(printType::ID);
	cin >> info.ID;
	//국어
	printInput(printType::KOR);
	cin >> info.kor;
	//영어
	printInput(printType::ENG);
	cin >> info.eng;
	//수학
	printInput(printType::MATH);
	cin >> info.math;
	//총점
	info.total = info.kor + info.eng + info.math;
	//평균
	info.avg = (float)info.total / 3; //정수 / 정수 나누기를 한다음 float으로 바꾸면서

	return info;
};

void printInput(printType _type)
{
	switch (_type)
	{
	case NAME:
		cout << "이름을 입력해주세요 : ";
			break;
	case ID:
		cout << "학번을 입력해주세요 : ";
			break;
	case KOR:
		cout << "국어점수를 입력해주세요 : ";
			break;
	case ENG:
		cout << "영어점수를 입력해주세요 : ";
			break;
	case MATH:
		cout << "수학점수를 입력해주세요 : ";
			break;

	}
}





int main()
{
	StudentInfo jec = InputStudentInfo();
	PrintStudentInfo(jec);
}


void PrintStudentInfo(StudentInfo _info)
{
	system("cls");
	cout << "===========입력된 정보===========" << endl;
	cout << "이름 : " << _info.name << endl;
	cout << "학번 : " << _info.ID << endl;
	cout << "국어 : " << _info.kor << endl;
	cout << "영어 : " << _info.eng << endl;
	cout << "수학 : " << _info.math << endl;
	cout << "총점 : " << _info.total << endl;
	cout << "평균 : ";cout.precision(2); cout << _info.avg << endl;
}