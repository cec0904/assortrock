/*
	함수
	기능을
	함수는 구현되어 있는 기능을 동작시키고 결과를 얻는다.

	예를 들어서 자판기라고 생각하면 좋다.

	동전을 넣고(데이터를 넣고)
	원하는 음료수를 선택(원하는 기능을 실행하고)
	음료수를 받는다(반환 받는다)

	///////////////////////////////

	반환형 함수명(받고싶은 데이터(매개변수) 들을 받을 수 있다.)
	(
		// 원하는 기능을 만들 수 있다.
		return;
	)

	// 함수명도 규칙이 있다.
	- 숫자로 시작할 수 없다.
	- 공백이나 특수문자 사용할 수 없다.
	- 예약어 사용 할 수 없다.
	- 대소문자 구별한다.

	반환값에는 모든 자료형 사용 가능하고
	void -> 반환값이 없음


*/
#include <iostream>
using namespace std;



//void printHelloWorld()
//{
//	cout << "Hello World ! " << endl;
//}
//
//int giveMeOne()
//{
//	return 1;	//return 은 함수를 끝내는 키워드다.
//}
//int giveMeTwo()
//{
//	return 2;	//return 은 함수를 끝내는 키워드다.
//}
//
//float giveMePI()
//{
//	return 3.14;
//	float PI;
//	PI = 3.14;
//}
//
//
//
//// 매개변수는
//// 함수에 데이터를 전달하고 싶을 때 사용된다.
//// 형식은 소괄호 안에 받고싶은 데이터 타입으로 변수를 선언한다.
//
//// 하나의 숫자를 받아서 출력하는 기능을 만들고 싶다.
//void printNumber(int number)
//{
//	cout << "숫자를 출력합니다 : " << number;
//
//	return;
//}
//
//
//int main()
//{
//
//
//	printHelloWorld();
//
//	cout << "helloFunc end" << endl;
//
//	cout << giveMeOne() << endl;
//
//
//	int number = 0;
//
//	number = giveMeOne();
//	cout << "첫 번째 number" << number << endl;
//	number = giveMeTwo();
//	cout << "두 번째 number" << number << endl;
//
//	float PI;
//	PI = giveMePI();
//	cout << "PI : " << PI << endl;
//
//	//// 매개변수 사용
//	number = 100;
//	printNumber(100);
//	return 0;
//}

//int AddFunc(int a, int b)
//{
//	return a + b;
//}
//int SubFunc(int a, int b)
//{
//	return a - b;
//}
//int MulFunc(int a, int b)
//{
//	return a * b;
//}
//int DivFunc(int a, int b)
//{
//	return a / b;
//}
//
//
//
//int main()
//{
//	int a = 0, b = 0;
//	cout << "숫자를 입력하세요 : ";
//	cin >> a >> b;
//
//	cout << "두 수의 덧셈은 : " << AddFunc(a, b) << endl;
//	cout << "두 수의 뺄셈은 : " << SubFunc(a, b) << endl;
//	cout << "두 수의 곱셈은 : " << MulFunc(a, b) << endl;
//	cout << "두 수의 나눗셈은 : " << DivFunc(a, b) << endl;
//}


// 실습 : 함수 하나를 이용해서
// 구조체로 사칙연산 결과물을 한번에 반환받아보고
// 구조체 하나 만들어서
// 함수의 반환값으로 이용해보자
// 출력해보자

struct Num
{
	int AddFunc(int a, int b)
	{
		return a + b;
	}
	int SubFunc(int a, int b)
	{
		return a - b;
	}
	int MulFunc(int a, int b)
	{
		return a * b;
	}
	int DivFunc(int a, int b)
	{
		return a / b;
	}
	int RemFunc(int a, int b)
	{
		return a % b;
	}
};

struct Info
{
	char name[20];
	int id;
	int score1, score2, score3;
	int sumFunc(int a, int b, int c)
	{
		return a + b + c;
	}
	int avgFunc(int a, int b, int c)
	{
		return (a + b + c)/3;
	}
}; 




int main()
{
	//Num num;

	//int a = 0, b = 0;
	//cout << "숫자를 입력하세요 : ";
	//cin >> a >> b;

	//cout << "두 수의 덧셈은 : " << num.AddFunc(a, b) << endl;
	//cout << "두 수의 뺄셈은 : " << num.SubFunc(a, b) << endl;
	//cout << "두 수의 곱셈은 : " << num.MulFunc(a, b) << endl;
	//cout << "두 수의 나눗셈은 : " << num.DivFunc(a, b) << endl;
	//cout << "두 수의 나머지는 : " << num.RemFunc(a, b) << endl;

	Info info;

	cout << "이름을 입력해주세요 : ";
	cin >> info.name;
	cout << endl;

	cout << "학번을 입력해주세요 : ";
	cin >> info.id;
	cout << endl;

	cout << "국어, 영어, 수학 점수를 순서대로 입력해주세요 : ";
	cin >> info.score1 >> info.score2 >> info.score3;
	cout << endl;

	
	cout << info.name << " 학생의 학번은 " << info.id << " 이고 점수 총점은 " << info.sumFunc(info.score1, info.score2, info.score3)<< "점 이고 점수 평균은 " 		<< info.avgFunc(info.score1, info.score2, info.score3) << "점 입니다." << endl;
	

	



}