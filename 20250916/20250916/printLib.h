#pragma once
#include <iostream>
#include <string>

using namespace std;
class CprintLib
{
private:
	string mName;

	static int Number;

public:
	void PrintFunc()
	{
		this->mName = "아무개";
		cout << "나는 객채의 PrintFunc" << endl;
	}

	/*
		static 멤버 함수
		=>클래스 객체에 종속되지 않고 호출할수 있는 함수다.
	*/

	//객체에 귀속되지 않는다. 
	static void myPrintStaticFunc();

};

