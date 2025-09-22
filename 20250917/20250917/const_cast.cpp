#include <iostream>
using namespace std;


// 값을 참조해서 가져올 수 있는데 내부데이터를 수정은 못함
void PrintFunc(const int* ptr)
{
	//*ptr = 11;
	// lvalue 가 const 가 붙어서 수정이 안됨(lvalue, rvalue)

	// 원래라면 const 포인터는 접근해서 수정이 안되지만
	// 이걸 상수값인데 강제로 바꾸고 싶다면
	int* Not_ConstNumber = const_cast<int*>(ptr);
	*Not_ConstNumber = 11;
	// 웬만해선 쓰지 않는다.
}


int main()
{
	int number = 0;
	cout << "이전 : " << number << endl;
	PrintFunc(&number);
	cout << "이후 : " << number << endl;




	return 0;

}