#include <iostream>
using namespace std;

class CParent
{
public:
	CParent()
	{
		cout << "Parent 생성자" << endl;
		
	}
	virtual ~CParent()
	{
		cout << "Parent 소멸자" << endl;
	}

	virtual void PrintFunc()
	{
		cout << "Parent의 PrintFunction" << endl;
	}

	void testFunc()
	{
		cout << "Parent의 testFunc" << endl;
	}

	int PrintNumber(int _number)
	{
		cout << "Parent의 PrintNumber : "<< _number << endl;
		
		return _number * 100 ;
	}


};

class CChild : public CParent
{
public:
	CChild()
	{
		cout << "상속받은 Parent 생성자" << endl;
	}
	virtual ~CChild()
	{
		cout << "상속받은 Parent 생성자" << endl;
	}

	virtual void PrintFunc() override
	{
		cout << "Child의 PrintFunction" << endl;
	}


};

// 반환값 void
// 함수명 Func1
// 매개변수 없음
void Func1()
{
	cout << Func1 << endl;
	cout << "Func1" << endl;
	return;
}

void Func2(int _n)
{
	cout << _n << endl;
	return;
}

int Func3(int _n, float _f, char _c)
{
	cout << "Func3 n : " << _n << endl;
	cout << "Func3 f : " << _f << endl;
	cout << "Func3 c : " << _c << endl;
	return _n * _f * _c;
}


int main()
{
	CParent* pChild = new CChild();
	pChild->PrintFunc();
	delete pChild;

	// 함수도 주소값으로 들고있을 수 있다.
	// 가상함수는 void 포인터를 들고있다.

	// 함수 포인터
	// 문법 -> 반환타입(*변수이름)(매개변수 자료형 타입 목록)


	// Func1을 들고있는 함수 포인터 변수를 만들 것이다.

	void(*pFunc1)() = Func1;
	Func1();
	// 00007FF6BEBF152D 주소값 출력
	// Func1 출력
	
	


	// Func2를 들고있는 함수 포인터를 변수로 만들 것이다.
	void(*pFunc2)(int) = Func2;
	pFunc2(100);
	// 100 출력

	// Func3를 들고있는 함수포인터
	int(*pFunc3)(int, float, char) = Func3;
	cout << Func3(3, 3.14, 'Z');

	// 출력값
	// Func3 n : 1
	// Func3 f : 3.14
	// Func3 c : Z
	// 282



    // 클래스 멤버 함수 포인터 호출 시 객체 인스턴스 필요
    CParent pParent;

	// 클래스의 멤버함수 들고있기
	// void testFunc();
	// testFunc 는 const 안붙어서 주소바뀌어도 상관없음
	void (CParent:: * ptestFunc)();
	ptestFunc = &CParent::testFunc;

	int(CParent:: * pPrintNumber)(int);
	pPrintNumber = &CParent::PrintNumber;
	// pPrintNumber(999);	에러
	cout << (pParent.*pPrintNumber)(999) << endl;



	return 0;
}