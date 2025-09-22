#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CMyPlayerJob
{
private:
	
protected:
	string MyPlayerJobName;

public:

	virtual void Warrior_Skill()
	{
		cout << "전사 공격 시전" << endl;
	}

};

class CWarrior : public CMyPlayerJob
{
public:
	void GetName()
	{
		MyPlayerJobName = "전사";
	}

	void Warrior_Skill()
	{
		CMyPlayerJob::Warrior_Skill();
		cout << "검 찌르기" << endl;

	}
	void Warrior_Skill1()
	{
		CMyPlayerJob::Warrior_Skill();
		cout << "검 휘두르기" << endl;

	}

};

int main()
{
	CMyPlayerJob* mpjWarrior = new CWarrior();

	mpjWarrior->Warrior_Skill();
	
}