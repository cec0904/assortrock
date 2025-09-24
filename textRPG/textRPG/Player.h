#pragma once
#include "Object.h"

class CPlayer : public CObject
{
private:
	ePlayerState mState;

	ePlayerCombatMod mCombatMod;

	eJobClass mJob;

public:
	CPlayer();
	virtual ~CPlayer() override;
	
// 나누는 이유는 개인적으로 보기 좋아서.
public:
	virtual bool Init() override;
	virtual void Draw() override;
	virtual void Update() override;
	void SaveLoadSelect();
	string JobToString(eJobClass _job);

private:
	void PlayerInfoDraw();
	void PlayerSearchDraw();
	void PlayerCombatDraw();

	void BasicStateUpdate(int _message);
	void CombatStateUpdate(int _message);
	void SearchUpdate(int _message);
	void CombatWinUpdate(int _message);
	void CombatLoseUpdate(int _message);

	void Attack();
};

