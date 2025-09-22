#include <iostream>
using namespace std;

//////////////////////////////////////
/*
	enum			// 상수에 이름을 지어주는거다.


	enum class 는 enum 과 다르게 사용할 때 사용
	:: 스코프 해상도 연산자

	enum class 는 형변환 시 강제, 명시적 캐스팅을 해야한다.

	열거형도 using, typedef 사용 가능
*/

enum class test
{
	TEST_T1,
	TEST_T2,
	TEST_T3
};
enum temp
{
	t1,
	t2,
	t3
};



int main()
{
	test::TEST_T1;
	temp::t2;


	int state = t1;
	state = (int)test::TEST_T2;
}