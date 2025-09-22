 //바이트패딩
 //구조체의 크기는 우리가 생각하는 것과 다를 수도 있다.
 //컴파일러가 효율적으로 메모리를 불러오기 위해 바이트 패딩을 한다.

 //선언 시 크기가 큰 자료형부터 작은 자료형 순서대로 선언하면 좋다.

 //외우자 ! 선언 시 자료형 크기가 큰 순서대로 판단


#include <iostream>
using namespace std;

struct a
{
	char cdata1;	//1바이트
	char cdata2;	//1바이트
	char cdata3;	//1바이트
	char cdata4;	//1바이트
	int idata1;		//4바이트
};

struct b
{
	char cdata1;	//1바이트
	char cdata2;	//1바이트
	int idata1;		//4바이트
	char cdata3;	//1바이트
	char cdata4;	//1바이트

};



int main()
{
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
}