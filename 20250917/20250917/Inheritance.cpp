#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CAnimal
{
public:
	CAnimal()
	{
		cout << "동물 생성자 입니다." << endl;
	}
	virtual ~CAnimal()
	{

	}

private:

protected:	
	string mName;
public:

	virtual void Howling()	
	{
		cout << "동물의 울음소리" << endl;
	}

	// 이동
	/*
		순수 가상함수
		필수로 이 함수를 구현해야한다.
	*/
	virtual void Move() = 0;


};

class CQWalkingAnimals : public CAnimal
{
public:

};

class CDog : public CAnimal
{
public:
	CDog()
	{

	}
	~CDog()
	{

	}
public:
	void GetName()
	{
		mName = "강아지";
	}
	void Howling()	
	{
		CAnimal::Howling();
		cout << "멍멍" << endl;
	}

	void Move() override
	{
		cout << "4발로 걷습니다." << endl;
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
	void Move() override
	{
		cout << "4발로 걷습니다." << endl;
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


int main()
{

	CAnimal* pDog = new CDog();
	pDog->Move();
	delete pDog;

	CCat* pCat = new CCat();
	pCat->Move();
	delete pCat;

	return 0;

}