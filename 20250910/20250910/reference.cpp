#include <iostream>

using namespace std;


/*
	레퍼런스
	기본의 변수에 또다른 이름을 만들어 주는 문법이다. 메모리 공간을 공유한다.
	자료형& 별칭 = 변수명;

	선언 동시에 초기화를 해줘야한다.
	재할당이 불가능하다.

*/
/*
	그럼 왜 레퍼런스 안쓰고 포인터 쓰냐 ?
	-> 보내주는 데이터량이 적으면 레퍼런스로 사용하면 편하고 좋다
	하지만 데이터량이 커지면 포인터가 적게 사용하기 때문에 포인터가 더 좋다.
*/
void change100(int& n, int* pn, const int& crp)
{
	// 포인터였으면
	*pn = 100;

	// 레퍼런스라면
	n = 100;

	//const 붙이면 변경 불가
	//crp = 100;
}


void add(int& a, int& b);




int main()
{
	//int number = 0;


	//// 기본적인 사용방법

	//int& rNumber = number;	// number 또다른 이름인 rNumber 가 생긴거다
	//
	//cout << "number의 주소 : " << &number << endl;
	//cout << "rnumber의 주소 : " << &rNumber << endl;

	//int& ncrp = number;
	//
	//cout << "number ::" << number << endl;
	//change100(number, &number, ncrp);
	//cout << "number ::" << number << endl;
	////////////////////////////////////////////////////////
	//// 재할당이 안된다.
	//int a = 10;
	//int b = 30;

	//int& ra = a;
	//ra = b; // 이 친구는 ra는 b의 메모리를 공유하는게 아니라, a에 b의 데이터를 넣어준 것이다.


	////////////////////////////////
	//a = NULL;
	//int* pa = nullptr;	// 아무것도 없는것이다.


	////int rb = nullptr;	//레퍼런스는 널이 없다. 무조건 초기화 할 때 할당 해줘야한다.






	// 레퍼런스
	// 사칙연산
	// 매개변수로 레퍼런스 받고, 첫 번째 레퍼런스에 담아서 내보내기
	// 그리고 바로 출력해주기

	int n = 0;
	int m = 0;

	int& rn = n;
	int& rm = m;

	add(rn, rm);

	cout << add << endl;

}

void add(int& a, int& b)
{
	a = 5;
	b = 3;
	
	cout << a + b;
}