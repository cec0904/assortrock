#include <iostream>
using namespace std;

/*
	포인터에 const 를 사용할 때 위치에 따라 의미가 달라진다.

	const 포인터자료형 변수명 -> 가리키는 대상의 데이터를 상수화 한다.

*/

// 예시
void add(const int* num, const int* num2, int* result1, int* result2)
{
	*result1 = *num + *num2;
	*result2 = *num + *num2 + 100;
}

/*
	레퍼런스
	기본의 변수에 또다른 이름을 만들어 주는 문법이다. 메모리 공간을 공유한다.



*/







// const를 매개변수에 사용하면 읽기 전용으로 만들 수 있다.
void printPointData(const int* number)
{
	cout << number << endl;
}



int main()
{
	int number = 10;
	int number2 = 11;

	// const가 앞에 붙었을 때
	const int* cpNumber = &number;		// const int 냐 int const 냐

	cpNumber = &number;


	//자료형 앞에 붙으면 주소 안의 데이터를 변경할 수 없다.
	//*pNumber = 10;		//error

	// const가 뒤에 붙었을 때
	// 포인터 자체 주소값을 변경할 수 없다.
	// 주의조건 : 선언과 동시에 초기화 해줘야한다.
	int* const pcNumber = &number;

	//*pcNumber = &number2;
	
	*pcNumber = 100;


	//cpc : 무조건 number를 관찰만 할거다
	const int* const cpcNumber = &number;

	int result1 = 0;
	int result2 = 0;

	add(&number, &number2, &result1, &result2);

	cout << result1 << endl;
	cout << result2 << endl;

	return 0;
}