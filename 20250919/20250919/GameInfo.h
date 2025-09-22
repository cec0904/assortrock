#pragma once

// 모두 컴파일 된 헤더
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

using namespace std;



 //싱글톤 매크로
#define DECLARE_SINGLETON(classname) private:\
classname();\
~classname();\
public:\
static classname* GetInst()\
{\
	static classname* GetInst()\
	return &Inst;\
}


