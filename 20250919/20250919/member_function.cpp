#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CObject
{
protected:
	string mName;
	int mHP = 100;

public:
	CObject(const string& name) :mName(name), mHP(100){ }
	virtual ~CObject() = default;
		
	virtual void OnReceiveEvent(int _value)
	{
		// 이거 상속받으면 함수 포인터 호출
	}
	virtual void DamageMessage(int damage)
	{
	}
	virtual void HalfHP(int _exp)
	{
	}
	virtual void Die(int _exp)
	{
	}
};


typedef void(CObject::* pEventFunc)(int);

struct sEvent
{
	CObject* callObj;
	pEventFunc func;
};

class CPlayer : public CObject
{
private:
	int mExp;

public:
	CPlayer(string _name)
		: CObject(_name), 
		mExp(0)
	{

	}
	~CPlayer() = default;

	// override 키워드 이용해서 가상함수 문제 없는지 확인
	virtual void OnReceiveEvent(int exp) override
	{
		mExp += exp;
		cout << "플레이어 " << mName << " 은 " << exp << "경험치를 획득했습니다." << endl;
		cout << "전체 경험치는 " << mExp << "입니다." << endl;
	}

	
	
};

class CMonster : public CObject
{

private:
	
	int mExp = 30;

	// 피격을 맞았을 때 호출해 줄 함수포인토 모음
	// 생각해볼것
	// 일반 함수는 호출할 함수 주소만 있으면 됐는데
	// 멤버함수는 누가 이 함수를 호출할 지 필요하다.
	// 그럼 객체도 같이 넣어줘야 한다.

	vector<sEvent> mEvents; // 객체와 함수 포인터를 들고있는 구조체를 하나 만들어서 들고있는다.

public:
	CMonster(string _name)
		: CObject(_name),
		mExp(30)
	{

	}
	~CMonster() = default;

	void AddEvent(CObject* _obj, pEventFunc _func)
	{
		// 어떤 객체의 함수를 넣어줄지 구조체로 넣어준다.
		mEvents.push_back({ _obj, _func });
	}


	// 데미지 입었을 때 호출
	void takeDamage(int _damage)
	{

		mHP -= _damage;

		for (auto event : mEvents)
		{
			// 넣어둔 객체의 함수로 호출 해준다.
			(event.callObj->*event.func)(mExp);
		}
	}

	virtual void DamageMessage(int damage) override
	{
		std::cout << "공격을 받았습니다." << std::endl;
	}
	virtual void HalfHP(int _exp) override
	{
		if (mHP <= 50)
		{
			std::cout << mName << "의 체력이 50%이하 입니다." << std::endl;
		}
	}
	virtual void Die(int _exp) override
	{
		if (mHP <= 0)
		{
			std::cout << mName << "이 죽었습니다." << std::endl;
		}
	}
};


class CQuestSystem : public CObject
{
private:
	int curExp = 0;
	int MaxExp = 100;
	bool mIsQuestDone = false;

public:
	CQuestSystem(string name)
		:CObject(name)
	{

	}

	virtual void OnReceiveEvent(int exp)
	{
		cout << endl;
		if (curExp >= MaxExp)
		{
			cout << mName << " 완료!!!" << endl;
			return;
		}

		cout << mName << " 퀘스트 진행중!" << endl;
		curExp += exp;

		if (curExp > MaxExp)
		{
			curExp = MaxExp;
		}
		cout << "목표 " << curExp << " / " << MaxExp << endl << endl;
	}
};


int main()
{
	CPlayer Player("전사");
	CMonster Slime("슬라임");
	CQuestSystem expQuest("경험치 모으기");
	
	Slime.AddEvent(&Player, &CObject::OnReceiveEvent);
	Slime.AddEvent(&Slime, &CObject::DamageMessage);
	Slime.AddEvent(&Slime, &CObject::HalfHP);
	Slime.AddEvent(&Slime, &CObject::Die);
	Slime.AddEvent(&expQuest, &CObject::OnReceiveEvent);


	Slime.takeDamage(10);
	Slime.takeDamage(10);
	Slime.takeDamage(10);
	Slime.takeDamage(10);
	Slime.takeDamage(30);
	Slime.takeDamage(30);

	return 0;
}