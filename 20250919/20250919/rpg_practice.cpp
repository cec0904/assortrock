#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CObject
{
protected:
	string wName;
	string aName;
	int wHP = 200;
	int aHP = 100;

public:
	CObject(const string& name) 
		:wName(name),
		aName(name),
		wHP(200),
		aHP(100)
	{

	}
	virtual void ~CObject() = default;


};

typedef void(CObject::* pEventFunc)(int);

class CWarrior : public CObject
{

};