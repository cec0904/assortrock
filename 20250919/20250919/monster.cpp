#include <iostream>
#include <vector>

using namespace std;

// typedef 를 이용해서 자료형을 만들어 준 것이다.
typedef void(*pEventFunc)(int);



class CMonster
{
private:
	int HP = 100;
	//배열로 함수포인터를 담을 그릇 만들거다.
	//void(*pEventFunc)(int) 해당 형식의 함수포인터를 담아두겠다.
	vector<pEventFunc> BindFuncs;

public:
	CMonster() = default;
	~CMonster() = default;

	void AddEvent(pEventFunc Func)
	{
		BindFuncs.push_back(Func);
	}



	void takeDamage(int _damage)
	{
		HP -= _damage;

		for (auto Func : BindFuncs)
		{
			Func(HP);
		}
	}


};



void onDamageMessage(int _damage)
{
	cout << "데미지를 받았습니다." << endl;
}

void onMonsterHalfHP(int _hp)
{
	if (_hp <= 50)
	{
		cout << "몬스터에 체력이 50% 이하입니다." << endl;
	}
}

void onMonsterDie(int _hp)
{
	if (_hp <=0)
	{
		cout << "몬스터가 죽었습니다." << endl;
	}
}



int main()
{
	CMonster Orc;

	// 함수등록
	Orc.AddEvent(onDamageMessage);
	Orc.AddEvent(onMonsterHalfHP);
	Orc.AddEvent(onMonsterDie);

	//데미지 주기
	Orc.takeDamage(10);
	Orc.takeDamage(20);
	Orc.takeDamage(30);
	Orc.takeDamage(50);

	return 0;

}