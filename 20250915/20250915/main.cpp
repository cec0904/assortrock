#include <iostream>
#include <string>
#include <utility>	// 이동생성자 만들 때 필요하다 std::move
using namespace std;

/*
	c 타입 malloc calloc

	c++ 생성 할당
	malloc calloc 이랑 가장 큰 차이점은
	1가지 -> new 랑 delete는 생성자, 소멸자를 호출해준다
*/


class CAnimal
{
public:
	string mName;
	int* m특성;

public:
	// 매개변수가 없으면
	// 기본 생성자
	CAnimal()
	{
		cout << "동물의 생성자 !!" << endl;
		mName = "동물";
		m특성 = new int(100);
	}

	

	// 매개 변수 생성자
	// const 해서 변하지 않는 값 할 때 & 레퍼런스
	
	CAnimal(const string& _name)
	{
		//_name = "실수로 이름바꿈";
		// const 이용해서 값이 바뀌는 것을 방지한다.
		cout << "동물의 매개변수 생성자 !!" << endl;
		mName = _name;
	}

	~CAnimal()
	{
		cout << "동물의 소멸자 !!" << endl;
		mName = "뼈";
		delete m특성;
	}



	// 복사 생성자
	CAnimal(const CAnimal& other)
	{
		this->mName = other.mName;
		m특성 = new int(*other.m특성);
		
		// 포인터를 서로 공유하면
	}

	/*
		복사도 종류가 다양하다
		얕은 복사 -> 주소를 공유한다. -> 같은곳을 가리키게 된다.
		깊은 복사 -> 실제 값만 복사하고, 완전히 독립된 객체로 복사한다


	*/
	
	// 이동생성자
	// noexcept : 예외처리를 안하겠다고 컴파일러에게 알려준다
	// 소유권을 넘긴다.
	//
	CAnimal(CAnimal&& other) noexcept
	{
		mName = move(other.mName);
		m특성 = move(other.m특성);
	}






};


int main()
{

	// new를 이용해서 int 타입을 동적할당 했다.
	//int* pNumber = new int;		// 데이터 초기화 x
	int* pNumber = new int(1);	// int 를 1로 초기화 했다.
	cout << *pNumber << endl;
	*pNumber = 100;
	cout << *pNumber << endl;
	delete pNumber;

	// 배열 동적으로 할당받기
	char* pcArr = new char[100];
	delete[] pcArr;


	//CAnimal* pAnimal = (CAnimal*)malloc(sizeof(CAnimal));
	// 생성자 호출이 없다.


	CAnimal* pAnimal = new CAnimal;
	delete pAnimal;

	// 클래스라고 다른게 없다
	CAnimal* pAnimalArr = new CAnimal[10];
	delete[] pAnimalArr;


	////////////////////////////////////////
	CAnimal* pDog = new CAnimal("Dog");
	CAnimal* pDog2 = new CAnimal(*pDog);
	delete pDog;

	cout << *pDog2->m특성 << endl;

	// 이동 생성자
	CAnimal pDog3 = move(*pDog2);
	cout << pDog2->mName << endl;
	cout << *pDog2->m특성 << endl;
	delete pDog2;
	pDog2 = nullptr;



	return 0;
}



