#include "Singleton.h"

//정적 멤버 변수 선언시 소스파일에서 초기화를 해줘야 한다. 
Singleton* Singleton::instance = nullptr;