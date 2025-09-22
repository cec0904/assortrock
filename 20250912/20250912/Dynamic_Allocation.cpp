/*
	동적할당
	
	-> 런타임(프로그램 실행) 중 필요한 크기만큼 메모리를 힙 메모리 데이터영역에 메모리를 할당하고 해제한다.

	c 타입

	동적 할당 받는 함수
	malloc()	//초기화 x
	calloc()	//초기화 o

	동적 할당 해제 함수
	free()

	c++ 타입
	new
	delete


*/

//https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/find-memory-leaks-using-the-crt-library?view=msvc-170
#define _CRTDBG_MAP_CLLOC

#include <iostream>
#include <cassert>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main()
{
	//_CrtCheckMemory(_CRTDBG_LEAK_CHECK_DF);

	// 지역변수들은 컴파일 단계에서 메모리 크기가 정해진다.
	int number = 0;
	int bingo[10];
	// 프로그램 실행 도중에 새롭게 할당하고 싶으면 동적할당을 사용하면 된다.

	//////////////////////////////////////////////////////////

	// malloc
	// int 3개짜리 공간을 동적할당 하고싶다.
	//void* mArr = malloc(sizeof(int) * 3);
	int* mArr = (int*)malloc(sizeof(int) * 3);
	// 동적할당이 실패하면 null 이 나온다.
	if (mArr == nullptr)	// 사람 실수가 되었든 컴퓨터 하드 스펙 이슈가 되었든 null 이 나올수도 있다.
	{

		/*
			assert : 문제가 있을 경우 개발자가 직접 에러를 띄워서 확인한다.
		*/

		assert(0);	// 문제가 생겼을 시 강제적으로 에러를 띄운다.
	}
	cout << "malloc 결과값" << endl;
	
	mArr[0] = 10;
	mArr[1] = 20;
	mArr[2] = 30;


	for (int i = 0; i < 3; i++)
	{
		cout << mArr[i] << endl;
	}

	// 동적할당은 다 사용하면 꼭 해제해줘야 한다.
	free(mArr);		// 메모리 해제

	

	////////////////////////////////////////////////////
	// calloc -> 생성될 때 0으로 초기화 된다.
	//sizeof(int) 크기에 25번 0으로 초기화
	int* Bingo = (int*)calloc(25, sizeof(int));

	for (int i = 0; i < 25; i++)
	{
		cout << Bingo[i] << endl;
	}

	free(Bingo);



	// 해주면 메모리 누수가 생겼을 때 알려준다.
	_CrtDumpMemoryLeaks();		// 리턴 끝나기 전에 해주는게 좋다

	return 0;
}