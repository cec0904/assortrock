#include <iostream>
#include <string>
#include "printLib.h"
#include "Singleton.h"
#include "Dog.h"
using namespace std;



//네임스페이스 
namespace 화요일
{
	int g_number;

	void Func()
	{
		std::cout << "너무 즐겁다!!" << std::endl;
	}
}

void Func()
{
	std::cout << "너는 누구니?" << std::endl;
}

enum class week
{
	월요일,
	화요일,
	수요일,
	목요일,
	금요일,
	토요일,
	일요일
};




int main()
{
	화요일::g_number;
	화요일::Func();

	// 한 군데에서 관리하고 싶을 때 하는 것
	// 가리키는 주소는 같다
	Singleton* single1 = Singleton::GetInstance();
	Singleton* single2 = Singleton::GetInstance();
	cout << "single1이 가리키는 주소" << single1 << endl;
	cout << "single2이 가리키는 주소" << single2 << endl;

	cout << endl;
	cout << endl;


	Singleton& single11 = Singleton::GetInstance2();
	Singleton& single22 = Singleton::GetInstance2();
	cout << "single11이 가리키는 주소" << single1 << endl;
	cout << "single22이 가리키는 주소" << single2 << endl;


	single11.LogPrint("첫번째 로그 입니다. ");
	single11.LogPrint("두번째 로그 입니다. ");
	single22.PreLogPrint();

	CDog dog;
	dog.moungmoung();

	single11.PreLogPrint();


	return 0;
}

