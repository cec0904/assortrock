#pragma once


// 1. static 정적 멤버 변수를 이용해서 만드는 방법
// 2. static 정적 지역 변수를 이용해서 만드는 방법
// 2 번이 더 최근방법이다.

#include <iostream>
#include <string>

using namespace std;

class Singleton
{
private:
	static Singleton* instance;

	string mPreLog;

private:
	Singleton() = default;
	Singleton(const Singleton& _other) = delete;
	Singleton(Singleton&& _other) = delete;
	// ~Singleton() = default;
	Singleton& operator = (const Singleton&) = delete;
	~Singleton()
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}

public:
	static Singleton* GetInstance()	// 방법 1
	{
		if (instance == nullptr)
		{
			instance = new Singleton();
		}
		return instance;
	}

	static Singleton& GetInstance2()	// 마이어스 싱글톤(meyer's singleton)
	{
		static Singleton Instance;

		return Instance;
	}

	void LogPrint(string _log)
	{
		mPreLog = _log;
		cout << mPreLog << endl;
	}

	void PreLogPrint()
	{
		cout << mPreLog << endl;
	}

};