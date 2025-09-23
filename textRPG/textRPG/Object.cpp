#include "Object.h"

void CObject::TakeDamage(int _damage)
{
	mHP -= _damage;
}

void CObject::TakeDefense(int _defense)
{

	mHP -= _defense;
}

void CObject::TakeSpeedDown(int _speeddown)
{
	mSPD -= _speeddown;
}

