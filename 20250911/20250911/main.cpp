#include <iostream>
#include <cstring>		// C 파생 문자열 함수들을 사용할 수 있게 해준다.

#define _CRT_SECURE_NO_WORNING
using namespace std;

/*
	리터럴 문자열
	-> 코드 내에서 직접 표현되는 문자열 상수이다.
	보통 " " 큰 따옴표로 작성된다.

	메모리 구조 중 데이터 영역 그 중에서도 읽기 전용 메모리 영역에 주소가 할당된다.

	같은 문자열이면 하나의 주소를 가지고 가져다 사용한다.

	맨 뒤에 자동으로 \0 널 문자가 들어온다.
*/

/*
	문자열을 조작할 수 있는 여러 함수들을 사용 할 것이다.

	문자열의
	- 길이
	- 복사
	- 문자열 이어붙이기
	- 비교
	- 문자열 나누기
*/



int main()
{
	
#pragma region 리터럴문자
	//char c = 'a';						//문자
	//char string[20] = "hello!!!";		//문자열
	//char string2[20] = "hello!!!";
	//char string3[20] = "hello world!!!";

	//string = "bye";
#pragma endregion

	int array[] = { 1,2,3,4 };	
	char str[] = "Hello, World";	// 문자열 선언 및 초기화 방법1
	char str2[20] = "";				// 문자열 선언 및 초기화 방법2

	cout << endl << endl;

#pragma region 길이
	// 길이
	/*
		strlen() -> 문자열의 길이를 알려주는 함수다.
		// 마감 문자,  널문자를 제외한 길이를 보내준다.
	*/

	size_t length = strlen(str);		//size_t 자료형 알아보기
	int length1 = (int)strlen(str);
	cout << "문자열 길이 : " << length1 << endl;		// 널문자 포함x
	cout << "문자열 크기 : " << sizeof(str) << endl;	// 널문자 포함o

#pragma endregion
	cout << endl << endl;
#pragma region 복사
	///*
	//	strcpy_s(복사되는 곳, 복사되는곳 크기, 복사할 곳)
	//	strcpy 

	//	주의사항
	//	1. 복사할 곳이 충분히 크지 않으면, 메모리 침범이 일어날 수 있다.
	//	2. 복사할 곳이 \0(널 문자)로 끝나지 않으면 이상한 결과가 나올 수도있다.

	//*/
	//// _s 를 꼭 붙여줄 것

	//cout << "str : \t" << str << endl;
	//cout << "str2 : \t" << str2 << endl;


	//strcpy_s(str2, sizeof(str2), str);		// str의 문자열을 str2로 복사했다.


	//cout << "str : \t" << str << endl;
	//cout << "str2 : \t" << str2 << endl;

	////주의사항1 메모리 침범
	//// 추가팁 : 오류가 나왔을 대는 중단이 아닌 다시하기로 어디서 문제가 일어났는지 확인하자
	//strcpy_s(str2, "AAAA BBBB CCCC DDDD EEEE");
	//cout << "str2 : \t" << str2 << endl;

	//// 주의사항2 널문자 마감 안했을 때
	//strcpy_s(str2, sizeof(str2), "AAAAABBBBBCCCCCDDDDD");	//
#pragma endregion
	cout << endl << endl;


#pragma region 이어붙이기
	/*
		연결 문자열 이어 붙이기
		strcat_s(연결할 곳, 연결할 곳의 크기, 연결할 것)

		주의사항
		복사랑 같다.
		1. 연결할 곳이 충분히 크지 않으면, 메모리 침범이 일어날 수 있다.
		2. 널문자로 끝나야 한다!
	
	*/
	// str2 초기화
	// 배열주소를 바꿀 수 없다 한번 선언 된 주소는 바꿀 수 없다
	// str2 = " ";
	strcpy_s(str2, "!!");		// 이렇게 초기화, 문자열 비우는 방법 중 하나, 아무것도 없는것을 복붙
	cout << "str2 : \t" << str2 << endl;

	// str hello world
	// str2 ""
	// str2 + str;
	strcat_s(str2, sizeof(str2), str);
	cout << "str2 : \t" << str2 << endl;

	// str2 + "!!!";
	strcat_s(str2, sizeof(str2), "~~짠");
	cout << "str2 : \t" << str2 << endl;

#pragma endregion

	cout << endl << endl;
#pragma region 비교

	/*
		strcmp(비교할것1, 비교할것2);
		결과값이 세가지로 나옴
		문자열이 두개 같으면 -> 0	같다
		비교할것1 < 비교할것2 -> -1
		비교할것1 > 비교할것2 ->  1

		사전 순서가 빠른게 더 높다고 생각하면 된다.
		
	
	*/

	strcpy_s(str, "apple");
	strcpy_s(str2, "banana");

	int result = strcmp(str, str2);
	cout << result << endl;


	"helloworld" == "Helloworld";		//a
	//리터럴 문자열끼리 이렇게 단순 비교하면 내용물을 비교하는게 아니고 리터럴문자의 주소를 비교하는 것이다.
	// 리터럴 문자열은 결국 주소값이기 때문이다.


#pragma endregion

	cout << endl << endl;


#pragma region 나누기
	// 검색 문자열이 문자가 있는지 검색
	/*
		문자열에 해당 문자가 있는지 검사
		strchr(검색할 곳, 검색할 문자)
		반환값이 문자가 있는 곳에 문자열 주소를 준다.
		문자가 없으면 nullptr 를 반환한다.
	
	*/
	cout << "strchr 사용중" << endl;
	strcpy_s(str, "ABCDEFGH");
	
	char* pPosition = strchr(str, 'E'); // 반환값 : str + 4 주소값을 반환해준다.
	
	/*int arr[5];
	arr[1];
	*(arr + 0);
	arr + 0;*/

	cout << &str << endl;				//str의 주소값 출력
	cout << pPosition << endl;			
	cout << (void*)pPosition << endl;	//pPosition 의 주소값 출력
	cout << *pPosition << endl;



	cout << endl; 


	/*
		문자열을 넣어서 검색하는 함수
		strstr(검색할 곳, 검색할 것)
		찾으면 해당 위치 주소값, 없으면 nullptr
	
		중복된 문자열이 있으면 앞에 주소를 가져온다
	*/
	cout << "strstr 사용중" << endl;
	strcpy_s(str, "ABCDEFABC");


	pPosition = strstr(str, "DEF");

	cout << pPosition << endl;


#pragma endregion


	cout << endl << endl;

	// 나누기(토큰
	/*
		strtok_s(문자열, 구분자, 컨텍스트)
		문자열에서 구분자 기준으로 나누고 남은 문자열이다.

		문자열에 nullptr 이면 컨텍스트에 있는 내용물로 문자열을 나누기를 계속 진행한다.

		구분자는 여러개가 될 수 있다.
	*/

	cout << endl << endl;


	char str3[] = "A,B,C,D,E,F,G";
	char* context = nullptr;

	char* token = strtok_s(str3, ",", &context);
	cout << "토큰값 : " << token << endl;






	cout << endl << endl;

	while (token != nullptr)
	{
		cout << token << endl;
		cout << context << endl;
		token = strtok_s(nullptr, ",", &context);
	}


	strcpy_s(str3, "A,B;C:D F");
	context = nullptr;

	token = strtok_s(str3, ",;: ", &context);

	while (token != nullptr)
	{
		cout << token << endl;
		cout << context << endl;
		token = strtok_s(nullptr, ",;: ", &context);
	}

	return 0;
}