/*
	정적 변수
	static 키워드를 붙이면 정적변수로 만들 수 있다.
	정적 변수도 메모리 데이터 영역에 공간이 만들어 진다.
	함수가 호출될 때 처음 할당 받고, 프로그램이 종료될 때까지 메모리를 할당받고 있다.

	초기화 시 딱 한번만 초기화하고, 값을 지정하지 않으면 0으로 초기화한다.
*/
#include <iostream>

using namespace std;


void a()
{
	static int trycount = 0;	// 프로그램이 끝날 때까지 살아있다
								// 초기화 되지 않는다
	trycount++;
}



int main()
{

}