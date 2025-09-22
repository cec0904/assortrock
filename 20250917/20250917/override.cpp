/*
	상속
	-> 기존 클래스의 속성과 기능을 새로운 클래스가 물려받는 형태다.
	-> 객채지향 프로그램의 핵심이다.

	*** 키워드 공부
	* 객체지향, 절차지향
	* 객체지향 -> 다형성
	* "가상함수테이블"
	*

	동물 클래스

	동물클래스를 상속받는 강아지
	동물클래스를 상속받는 고양이
	동물클래스를 상속받는 코끼리

	virtual 키워드	-> 함수를 가상함수로 만들어준다.
					-> 가상함수는 부모 클래스에서 함수를 호출해도 자식클래스로 만들어졌으면 자식 클래스에서 정의된 함수를 호출해준다.
					-> virtual 키워드를 이용하면 "가상함수테이블"
					-> 인터페이스를 제공함으로써 어떤 기능을 만들수 있는지 제공해준다.

	override 키워드 -> 자식 클래스의 


	다형성
	-> 동일한 함수(연산자등 포함)를 여러 데이터 타입 또는 객체에 대해 다양한 방식으로 동작한다.
	->
	-> 함수 오버라이딩...
	-> 사용이유 : 유연성, 확장성

	생성자 소멸자 호출순서
	생성자 : 
	소멸자 : 
*/

// 실습 RPG 몬스터 또는 직업 관련으로 해서 본인이 생각하는 상속 클래스 만들어보기 
// 몬스터
// 직업 



#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CAnimal
{
private:

protected:		// 외부에는 노출이 안되는데 자식한테는 물려준다.
	string mName;
public:
	// 부모의 함수를 재정의 하는것을
	// 함수 "오버라이딩" 이라고 한다.
	virtual void Howling()		// virtual 키워드를 이용하면 부모의 함수를 자식에게 허용해준다
		// virtual 키워드를 사용하면
		// 가상함수 테이블이 생김
	{
		cout << "동물의 울음소리" << endl;
	}
	

};

class CDog : public CAnimal		// Dog은 Animal의 자식이다.
{
public:
	void GetName()
	{
		mName = "강아지";
	}
	void Howling()		// 함수 재정의
	{
		CAnimal::Howling();		// 부모의 함수를 호출할 수도 있다. 부모의 네임스페이스 이용
		cout << "멍멍" << endl;
	}


	virtual void Func1()
	{

	}
	virtual void Func2()
	{

	}

};

class CCat : public CAnimal
{
public:
	void Getname()
	{
		mName = "고양이";
	}
	void Howling()
	{
		CAnimal::Howling();
		cout << "애용" << endl;
	}

	

};


class CDuck : public CAnimal
{
public:
	void Getname()
	{
		mName = "오리";
	}
	void Howling()
	{
		CAnimal::Howling();
		cout << "꽥꽥" << endl;
	}
};


// 생성자는 virtual 안붙는다
// 소멸자에는 붙인다.
class CGrandFather
{
public:
	//virtual 
	CGrandFather()
	{
		cout << "할아버지 생성자" << endl;
	}
	virtual ~CGrandFather()
	{
		cout << "할아버지 소멸자" << endl;
	}
};

class CFather : public CGrandFather
{
public:
	CFather()
	{
		cout << "아버지 생성자" << endl;
	}
	virtual ~CFather()
	{

		cout << "아버지 소멸자" << endl;
	}
};

class CSon : public CFather
{
public:
	CSon()
	{
		cout << "아들 생성자" << endl;
	}
	virtual ~CSon()
	{

		cout << "아들 소멸자" << endl;
	}
};


int main()
{
	// 자식클래스는 부모클래스 포인터로 들고 있을 수 있다.

	// 재정의 해도 자식걸로 나온다
	//CAnimal* pDog = new CDog();

	//pDog->Howling();

	//CAnimal* pCat = new CCat();

	//pCat->Howling();
	//

	//vector<CAnimal*> animals;
	//animals.push_back(new CDog());
	//animals.push_back(new CCat());
	//animals.push_back(new CDuck());
	//animals.push_back(new CDog());
	//animals.push_back(new CDuck());

	//for (auto animal : animals)
	//{
	//	animal->Howling();
	//}


	CSon* pSon = new CSon();
	
	cout << endl;

	delete pSon;

	
	return 0;

}