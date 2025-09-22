/*
	포인터
	메모리를 지정하는 변수다.

	다른 변수나 객체의 주소를 들고있는 변수이다.
*/

/*
	자료형* -> 해당 자료형 타입에 포인터 자료형
		int* -> int 포인터
		char* -> char 포인터
		float* -> float 포인터
		구조체* -> 구조체 포인터

	연산자
	& : 주소를 알려주는 연산자
		&변수명 -> 해당 변수의 주소를 알려준다.
	
	*포인터 변수 -> 포인터가 가리키는 주소의 값을 가리킨다.


*/



#include <iostream>

using namespace std;




//void change(int number)
//{
//	number += 100;
//}
//
//void changeforPtr(int* number)
//{
//	*number += 100;
//}
//
//void add(int* n)
//{
//	*n += 100;
//}
//void sub(int* n)
//{
//	// n 주소를 pointer int포인터 자료형 변수에 담았고
//	int* pointer = n;
//	// 그 주소에 있는 데이터를 pointerForData int 변수에 값을 복사하고
//	int pointerForData = *pointer;
//	// 복사한 값을 연산하고
//	pointerForData -= 100;
//	// 결과값을 다시 해당 주소 데이터에 덮어씌운다.
//	*pointer = pointerForData;
//
//
//	*n -= 100;
//}
//void mul(int* n)
//{
//	*n *= 100;
//}
//void div(int* n)
//{
//	*n /= 100;
//}
//void rem(int* n)
//{
//	*n %= 100;
//}
//
//
//
//int main()
//{
//	int number = 100; // 넘버라는 공간을 할당 받는다.
//	cout << "number : " << number << endl;
//
//	int* ptr_number = &number; // ptr_number 는 number 의 주소를 가리킨다.
//	cout << "ptr_number : " << ptr_number << endl;
//
//
//	cout << "number : " << number << endl;
//	changeforPtr(&number);
//	cout << "number : " << number << endl;
//
//	//
//	int n = 0;
//
//	// 사칙연산별로
//	// 100 += -= /= *= %=
//	// 함수 만들어보기
//	add(&n);
//	cout << "n : " << n << endl;
//
//	sub(&n);
//	cout << "n : " << n << endl;
//
//	mul(&n);
//	cout << "n : " << n << endl;
//
//	div(&n);
//	cout << "n : " << n << endl;
//
//	rem(&n);
//	cout << "n : " << n << endl;
//
//
//
//	return 0;
//
//}




// 포인터 자료형의 크기
/*
	x64 64비트일 때는 메모리 크기는 8바이트이다.
	x86 32비트일 때는 메모리 크기가 4바이트이다.
*/

/*
	"데이터 버스" 키워드로 조사해보자
*/

// 복사비용 아끼려고
// 주석값만 이동
// 메모리를 더 많이 쓸 수 있다

// 테스트용 구조체
struct BigDataStruct
{
	double d1;
	double d2;
	double d3;
	double d4;
	double d5;
	double d6;
	// 48
};

void sizecheck(BigDataStruct data)
{
	data;
}



int main()
{
	char c1 = 'a';
	char* pc1 = &c1;
	cout << "포인터의 크기 : " << sizeof(pc1) << endl;	//x64 -> 8
														//x86 -> 4


	BigDataStruct data1{};
	cout << "구조체의 크기 : " << sizeof(BigDataStruct) << endl;
	sizecheck(data1);


	return 0;
}