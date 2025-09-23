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

private:
	void PlayerInfoDraw();
	void PlayerSearchDraw();
	void PlayerCombatDraw();
	string JobToString(eJobClass _job);

	void BasicStateUpdate(int _message);
	void CombatStateUpdate(int _message);
	void SearchUpdate(int _message);
	void WinUpdate(int _message);
	void LoseUpdate(int _message);

};

