/*

	배열 Array
	-> 같은 자료형으로 선언된 연속된 메모리 공간을 가지는 변수(자료구조)





*/









#include <iostream>

using namespace std;

int main()
{
	////하나의 데이터 공간만 생긴다.
	//// 변수 초기화
	//int number = 1;		//선언과 동시에 초기화
	//int number2;
	//number = 2;		//최초 값을 넣어주면 초기화

	////배열로 선언하면
	//int numbers[5];		// numbers 라는 변수명으로 int 자료형 데이터, "연속된 메모리"를 5개 생성하겠다.

	////배열 초기화 방법

	////선언과 동시에 초기화 방법
	//int numbers1[5] = {0, 0, 0, 0, 0}; // 데이터 모두를 0으로 초기화한다.
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << i << "번 인덱스 데이터" << numbers1[i] << '\n';
	//}
	//cout << endl;
	//cout << endl;

	//int numbers2[5] = { 1, 2, 3 };
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << i << "번 인덱스" << numbers2[i] << '\n';
	//}

	//cout << endl;
	//cout << endl;


	////접근 방식
	////변수명[인덱스] 인덱스는 접근 위치 순서
	//numbers[1]; // index == 2;

	//// 접근 예시
	//numbers[0] = 1;
	//numbers[1] = 2;
	//numbers[2] = 3;
	//numbers[3] = 123;
	//numbers[4] = 99;

	//cout << "0번 인덱스" << numbers[0] << '\n';
	//cout << "1번 인덱스" << numbers[1] << '\n';
	//cout << "2번 인덱스" << numbers[2] << '\n';
	//cout << "3번 인덱스" << numbers[3] << '\n';
	//cout << "4번 인덱스" << numbers[4] << '\n';

	//// 반복문을 통해서 접근 가능하다
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << i << "번 인덱스" << numbers[i] << '\n';
	//}
	//cout << endl;
	//cout << endl;


	/////////////////////////////////////////////////////////////////
	////hello world!
	////문자열 끝에는 무조건 \0이 있어야 한다.
	////\0 은 문자열의 끝을 의미한다.
	//char name[15] = { 'h','e','l','l','o','w','o','r', 'l','d','!','\0' };
	//char name2[11] = { 'h','e','l','l','o','w','o','r', 'l','d','!'};

	//char hello[] = "Hello World!";

	//cout << "이름 : " << name << endl;
	//cout << "이름 : " << name2 << endl;
	//cout << hello << endl;


	// 간단하게
	// 이름 입력 받아서
	// 배열 통해서 영어이름 저장하기
	// 지금은 영어이름
	// 
	// input 문자열에 이름 입력받고
	// 입력받은 문자열을 name 문자열에 for문 통해서 하나씩 복사

	char input[125] ="";
	char myname[125] = "";


	cout << "What's your name? : ";
	cin.getline(input, 125, '\n');
	cout << "My name is " << input << endl;

	for (int i = 0; i < 125; i++)		//for(int i = 0 ; input[i] != '\0 ; i++)
										//초기화를 해라 그래야 마감문자 따로 안 넣어도 된다
	{
		myname[i] = input[i];
		cout << myname[i] << endl;
		if (myname[i] == '\0')
			break;
	}

	



	return 0;
}