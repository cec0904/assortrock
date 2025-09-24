#include "DebugHeader.h"
#include "player.h"

/*
	프로젝트 -> 우클릭 -> 속성 -> C/C++ -> 고급 -> 강제 포함 파일 -> 원하는 파일 항상 #include 할수 있다.

*/

int main()
{
	// 메모리 릭 탐지를 활성화하는 디버그 플래그를 설정합니다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//int* pi = new int;

	Cplayer player;


	return 0;
}