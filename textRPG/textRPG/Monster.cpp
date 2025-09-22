#include "Monster.h"



CMonster::CMonster()
{

	// 동적으로 생성되고 나서 초기화를 해준다.
	Init();
}

CMonster::~CMonster()
{
}

bool CMonster::Init()
{
	// 몬스터 종료 받고 랜덤하게 스탯을 부여한다.
	mMonsterType = (eMonsterType)(rand() % (int)eMonsterType::End);

	mMonsterType = eMonsterType::Slime;
	switch (mMonsterType)
	{
	case eMonsterType::Slime:
		// 이름 능력치 등등 넣는 함수 필요
		MonsterSetting("슬라임", 1, 10, 100, 50, 3, 0);
		mDrawMonsterImage = GlobalFunc::PrintSlimeImage;
		break;
	case eMonsterType::Goblin:
		break;
	case eMonsterType::Orc:
		break;
	}

	return true;
}

void CMonster::Draw()
{
	MonsterInfoDraw();
	
}
void CMonster::MonsterInfoDraw()
{
	COUTN("-------------- 몬스터 정보 --------------");
	//이름
	COUT("이름\t: " << mName << "\t|\t");
	//직업
	COUTN("종족\t: " << MonsterTypeToString(mMonsterType));
	//체력 
	COUT("체력\t: " << mHP << " / " << mMaxHP << "\t|\t");
	//레벨
	COUTN("레벨\t: " << mLevel);
	//ATK
	COUT("공격력\t: " << mATK << "\t\t|\t");
	//DEF
	COUTN("방어력\t: " << mDEF);
	COUTN("-------------------------------------");
	mDrawMonsterImage();
	COUTN("-------------------------------------");
}

string CMonster::MonsterTypeToString(eMonsterType _monstertype)
{
	switch (_monstertype)
	{
	case eMonsterType::Slime:
		return "액체형";
	case eMonsterType::Goblin:
		return "소형";
	case eMonsterType::Orc:
		return "대형";
	}
	return string();
}

void CMonster::Update()
{
	
}

void CMonster::MonsterSetting(string _name, int _level, int _exp, int _money, int _hp, int _atk, int _def)
{
	mName = _name;
	mLevel = _level;
	mEXP = _exp;
	mMoney = _money;
	mMaxHP = _hp;
	mHP = mMaxHP;
	mATK = _atk;
	mDEF = _def;
}

