#pragma once
#include "Object.h"

class CMonster : public CObject
{
protected:
	eMonsterType mMonsterType;
	//몬스터를 그려주는 함수를 만들 것이다.
	void(*mDrawMonsterImage)();

protected:
	void MonsterInfoDraw();

	static string MonsterTypeToString(eMonsterType _monstertype);

public:
	CMonster();
	~CMonster();

	virtual bool Init() override;
	virtual void Draw()override;
	virtual void Update()override;

	eMonsterType GetMonsterType() { return mMonsterType; }
	void SetMonsterType(eMonsterType _type) { mMonsterType = _type; }

	void MonsterSetting(string _name, int _level, int _exp, int _money, int _hp, int _atk, int _def);
	
};

