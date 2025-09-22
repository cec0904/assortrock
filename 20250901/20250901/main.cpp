//전처리기
#include <iostream>

// c++ 11 에서 전용 int
#include <cstdint>

#include <stdint.h>

// cout 에서 double 값을 보기 위한 헤더
#include <iomanip>




using namespace std;

//주석
//주석: 코드에서 예외됩니다.
//한 줄 주석: //로 시작
//여러 줄 주석: /*로 시작, */로 끝남
/*
	주석1
	주석2
	주석3
*/




//출력
// printf()
// std::cout;


/*
	출력문
	#include <iostream>

	출력문
	printf();
	std::cout;


	# 이스케이프 시퀀스
	- 특정 문자를 조합하여 줄을 바꾸거나 특별한 문자를 출력할 때 사용하는 조합문자
	https://learn.microsoft.com/ko-kr/cpp/c-language/escape-sequences?view=msvc-170

	\n : 줄바꿈
	\t : 탭 만큼 공백
	123123123 \t 123123123
	\" : 쌍따옴표 출력
	\\ : 역슬래시 출력


	# 서식지정자 (자료형을 출력하기 위해)

*/


/*
	자료형 : 데이터의 종류와 크기 표현을 나타낸다 정의한다

	-변수 : 프로그램에서 데이터를 저장하고 조작할 수 있도록 이름을 붙인 메모리 공간
	-자료형 : 데이터의 종류와 크기, 표현을 나타낸다, 정의한다
	- 변수명은 중복되면 안된다
	- 숫자로 시작하면 안된다
	- 공백 없어야 한다. _(언더바) 사용 가능
	- 특수문자 사용 불가
	- MAX, NULL : 표준 프로그래밍 언어에서 미리 정의된 단어는 예약어인 단어들은 변수명으로 사용할 수 없다.
	- 예약어 : if, for, while, int, float, double, char, return 등등
	- 대소문자 구분 됩니다
	- 카멜 규칙 그 외에도 여러가지 있지만 회사 또는 팀, 개인 성향에 따라 규칙이 정해진다.
	- 다른사람이 이 변수가 무엇을 의미하는지 알 수 있게 짓는게 좋다.

	종류
	기본 자료형, 포인터 타입 자료형, 레퍼런스 타입 자료형, 사용자정의 자료형

	우리는 먼저 기본 자료형을 배울 것이다.

	#데이터 크기
	1bit : 0 과 1을 나타내는 기본 단위
	8bit : 1byte
	1024byte : 1KB
	1024KB : 1MB
	1024MB : 1GB
	1024GB : 1TB



	#기본 자료형
	문자형
	형식(자료형)				데이터 크기(byte)
	char				1 byte
	wchar_t				2 byte

	
	정수형
	short				2 byte
	int					4 byte
	long				4 byte	()
	long long			8 byte
	bool				1 byte (true, false)


	unsigned char		1 byte
	unsigned short		2 byte
	unsigned int		4 byte
	unsigned long		4 byte
	unsigned long long	8 byte


	실수형
	float				4 byte
	double				8 byte
	long double			8 byte (거의 사용 안함)
	



*/



int main()
{

	printf("Hello, World!\n");

	//강아지 그리기
	printf("    /\\_\n");
	printf("   (   @\\__\n");
	printf("   /         o\n");
	printf("  /   (_____/\n");
	printf(" /_____/   U\n");

	std::cout << "Hello, World!" << std::endl;

	//escape sequence
	printf("\n 줄바꿈 \n"); // 줄바꾸기
	printf("Hello\tWorld\n"); // 탭만큼 공백
	printf(" \\ 슬래쉬 \n"); // 역슬래쉬 출력
	printf(" \"쌍따옴표\" \n"); // 쌍따옴표 출력
	printf(" 백스페이스 ABC\bD\n"); // 백스페이스
	printf("\n\n");

	int n = 10;
	printf("int %d", n);

	// 서식지정자
	// 정의 -> printf, scanf 함수 등에서 사용되어 변수나 데이터의 형태를 지정한다.
	// 키워드 %
	/*
		%d : 정수
		%f : 실수
		%c : 문자 한개
		%s : 문자열
		%x : 16진수
	*/

	cout << endl;
	cout << endl;

	int number = 12345678;
	printf("휴대폰 번호 : %d %d", 10, number);

	cout << endl;
	cout << endl;


	float pi = 3.14f;
	double dpi = 3.141592;


	printf("원주율 : %f", pi);
	cout << endl;


	printf("double 원주율 : %lf", dpi);
	cout << endl;

	char c = 'A';
	printf("문자 : %c", c);
	printf("문자열 : %s\n", "Hello, World!");

	//16진수
	/*
		
	1 2 3 4 5 6 7 8 9 A B C D E F

	2진수		10진수		16진수
	0000		0			0
	0001		1			1
	0010		2			2
	0011		3			3
	0100		4			4
	0101		5			5
	0110		6			6
	0111		7			7
	1000		8			8
	1001		9			9
	1010		10			A
	1011		11			B
	1100		12			C
	1101		13			D
	1110		14			E
	1111		15			F
	*/


	//cout
	//std::cout -> 출력의 시작
	//std::endl -> 해당 출력 줄이 끝났다. 줄바꿈
	std::cout << "나의 전화번호는" << number << std::endl;

	////////////////////////////////////////////////////
	//입력
	// 원하는 값을 입력 받기 위해서 사용하는 것 입니다.

	//cin 
	//나이
	//int age = 0;
	//char name[255] = "";

	//std::cout << "나이를 입력하세요 : ";
	//std::cin >> age;
	//std::cout << " 내 나이는 " << age << "살 입니다." << std::endl;

	//std::cout << "이름을 입력하세요 : ";
	//std::cin >> name;
	//std::cout << "내 이름은 " << name << " 입니다." << std::endl;

	////scanf
	//printf("입력하세요 : ");
	//scanf_s("%d", &age);

	////문자열 같은거 사용할 때 문법이 달라졌다.
	////(서식지정자 포맷, 주소, 주소공간 크기)
	//printf("이름을 입력하세요 : ");
	//scanf_s("%s", name, sizeof(name));
	//printf("내 이름은 %s 입니다.\n", name);
	//
	////다중 선언 가능
	//long long long1, long2, long3;
	//scanf_s("%lld %lld %lld", &long1, &long2, &long3);
	//std::cout << "출력 " << long1 << " , " << long2 << " , " << long3 << std::endl;


	//cout << endl;
	//cout << endl;


	////////////////////////////////////////////////////
	//
	//이름 : 
	//나이 : 
	//성별 : 
	//char 이용해서 이름 알파벳 이니셜 받기
	////////////////////////////////////////////////////
	//구현

	char name[255] = "";
	int age = 0;
	char sex = ' ';
	char initial = ' ';

	printf("이름을 입력하세요 : ");
	scanf_s("%s", name, sizeof(name));
	

	printf("나이를 입력하세요 : ");
	scanf_s("%d", &age);
	

	printf("성별을 입력하세요 (M, F) : ");
	scanf_s(" %c", &sex, 1); 
	

	printf("이니셜을 입력하세요 : ");
	scanf_s(" %c", &initial, 1);



	printf("내 이름은 %s 입니다.\n", name);
	printf("내 나이는 %d살 입니다.\n", age);
	printf("내 성별은 %c 입니다.\n", sex);
	printf("내 이니셜은 %c 입니다. \n", initial);












	// 문자형
	/*	타입					주용도									크기			값의 범위(바이트)
		char				문자 데이터를 저장할 때 사용				1			-128 ~ +127
		unsigned char		부호가 양수 바이너리 파일 처리할 때		1			0 ~ 255
	*/
	
	// bool
// 1바이트
// 참 또는 거짓을 나타낸다
// true -> 0을 제외한 모든 수
// flase -> 0 인 경우
// bool 값은	
//
	bool b1 = true;
	b1 = 25;
	bool b2 = false;
	std::cout << "b1 : " << b1 << std::endl;
	std::cout << "b2 : " << b2 << std::endl;

	bool* pb1 = &b1;
	std::cout << pb1 << std::endl;


	char c1 = 'A';
	std::cout << "c1 : " << c1 << std::endl;
	std::cout << "char size : " << sizeof(char) << std::endl;
	std::cout << "c1 size : " << sizeof(c1) << std::endl;


	// 정수형
	// 용도는 -> 정수값을 저장한다.
	/*
		타입					크기			값의 범위(바이트)
		short				2			-32,768 ~ +32,767
		unsigned short		2			0 ~ 65,535
	*/
	// short
	short s1 = 101;
	unsigned s2 = 102;

	std::cout << "short size : " << sizeof(short) << std::endl;
	std::cout << "s1 : " << s1 << std::endl;
	std::cout << "s2 : " << s2 << std::endl;
	
	// short 자료형의 최대 값을 받아올 수 있는 것
	s2 = std::numeric_limits<unsigned short>::max();
	std::cout << "s2 : " << s2 << std::endl;


	// 업데이트 내용 확인
	s2 += 9999;
	std::cout << "s2 + 1 : " << s2 << std::endl;



	// int
	// 4byte
	// 가장 보편적으로 많이 사용되는 자료형
	// 값 범위 : -2,147,483,648 ~ +2,147,483,647
	// unsigned int : 0 ~ 4,294,967,295
	//
	int i1 = 100000000000;
	unsigned int i2 = 2;

	std::cout << "int size : " << sizeof(int) << std::endl;
	std::cout << "unsigned int size : " << sizeof(unsigned int) << std::endl;
	std::cout << "i1 size : " << sizeof(i1) << std::endl;
	std::cout << "i2 size : " << sizeof(i2) << std::endl;
	
	// MS 전용 확장자 자료형이 있다. 표준 C++ 아니다.
	__int16 i16 = 16;
	__int32 i32 = 32;
	__int64 i64 = 64;

	std::cout << "__int16 size : " << sizeof(__int16) << std::endl;
	std::cout << "__int32 size : " << sizeof(__int32) << std::endl;
	std::cout << "__int64 size : " << sizeof(__int64) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	// c++ 11
	int16_t i16t = 2;
	int32_t i32t = 4;
	int64_t i64t = 8;

	std::cout << "int16_t size : " << sizeof(int16_t) << std::endl;
	std::cout << "int32_t size : " << sizeof(int32_t) << std::endl;
	std::cout << "int64_t size : " << sizeof(int64_t) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	// long
	// 4byte (윈도우)

	long l1 = 101L;
	unsigned long l2 = 102UL;

	std::cout << "sizeof long : " << sizeof(long) << std::endl;
	std::cout << "sizeof unsigned long : " << sizeof(unsigned long) << std::endl;
	std::cout << "sizeof l1 : " << sizeof(l1) << std::endl;
	std::cout << "sizeof l2 : " << sizeof(l2) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	// long long
	// 8byte 64bit
	long long ll1 = 1000000000000LL;
	unsigned long long ll2 = 1000000000000ULL;

	std::cout << "sizeof long long : " << sizeof(long long) << std::endl;
	std::cout << "sizeof unsigned long long : " << sizeof(unsigned long long) << std::endl;
	std::cout << "sizeof ll1 : " << sizeof(l1) << std::endl;
	std::cout << "sizeof ll2 : " << sizeof(l2) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	// 실수형
	// 정밀도 => 부동 소수점 오차 => 
	// 소수부분은 약 7자리의 정밀도를 가진다 
	// 
	// float : 7자리
	// 정밀도 :
	// 소수부분이 약 15 ~ 16자리의 정밀도를 가진다
	// 
	
	float f1 = 3.14159265358979323846f;
	float f2 = 1.2345678901234567890f;
	std::cout << "float f1 : " << f1 << std::endl;
	std::cout << "float f2 : " << f2 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;


	//double
	//8byte
	//정밀도 : 소수부분이 약 15 ~ 16자리의 정밀도를 가진다

	double d1 = 0.1234567890123456789;
	std::cout <<  std::setprecision(20) << "double d1 : " << d1 << std::endl;
	//0.12345678901234567737
	
	double d2 = 9876543210987654321.123456789;
	std::cout << std::setprecision(20) << "double d2 : " << d2 << std::endl;
	//9876543210987655168

	double d3 = 654321.123456789123456789;
	std::cout << std::setprecision(20) << "double d3 : " << d3 << std::endl;
	//654321.12345678918064

	std::cout << "double sizeof : " << sizeof(double) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	//float a = 0.1f;
	//float b = 0.1f;
	//bool result = (a == b);
	////a 와 b 가 같은 값일까 ?
	//cout << "a == b ? " << result << endl;

	//float c = 0.3;
	//float d = 0.1 + 0.2;
	//result = (c == d);
	//// c랑 d가 같은 값일까 ?
	//cout << "c == d ? " << result << endl;


	return 0;
}

