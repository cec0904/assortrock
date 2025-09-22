#include "printLib.h"
using namespace std;
//정적 멤버 변수는 소스파일에 한번 선언 및 초기화를 해줘야한다. 
int CprintLib::Number = 0;

void CprintLib::myPrintStaticFunc()
{

	//this가 없는 상태 
	// -> 고유의 멤버 변수에 접근을 못한다. 
	//this->mName;
	//this->PrintFunc();	//호출이 안된다. 
	++Number;
	cout << "나는 printLib클래스의 PrintFunc 입니다. " << Number << endl;;

}
