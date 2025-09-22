#include <iostream>

using namespace std;


class Parent
{
public:
	Parent() = default;
	virtual ~Parent() = default;
};

class Child : public Parent
{
	Child() = default;
	virtual ~Child() = default;
};

class Child2 : public Parent
{
	Child2() = default;
	virtual ~Child2() = default;
};


int main()
{
	// static cast
	float Pi = 3.14;
	int number = static_cast<int>(Pi);
	cout << "number : " << number << endl;



	Child* pChild = new Child();
	Parent* pParent = pChild;
	Parent* pParent = static_cast<Parent*>(pChild);		// 안전한 업캐스팅이다. 권고함

	// 런타임 전에 됨
	// 실시간으로 검사를 안함
	Child* pTemp = static_cast<Child*>(pParent);		// static cast 로 다운캐스팅 할거면 개발자가 변환이 유효한지 보장해야한다.
	delete pChild;

	//////////////////
	//dynamic_cast
	pParent = nullptr;
	pChild = nullptr;

	pParent = new Child();		// 생성하는데 부모 클래스 포인터 타입으로 담아준다.

	//pChild = pParent; -> 담고싶을 때

	//pChild = (Child*)pParent;		-> 이렇게 하지 말고

	pChild = dynamic_cast<Child*>(pParent);		// 이렇게 안전하게

	if (pChild == nullptr)
	{
		cout << "형변환 실패" << endl;
	}
	else
	{
		cout << "형변환 성공" << endl;
	}


	// 잘못된 클래스로 형변환 했을 때
	// 잘못했다. 제대로 된 주소값 안 알려준다. nullptr 이다. 맞는 캐스트타입 찾아와라. 실패한다.
	Child2* pChild2 = dynamic_cast<Child2*>(pParent);
	if (pChild2 == nullptr)
	{
		cout << "형변환 실패" << endl;
	}
	else
	{
		cout << "형변환 성공" << endl;
	}




	return 0;
}