/*
	가변 배열
	런타임(프로그램 실행) 중에 할당된 배열로 메모리 크기가 런타임 도중에 변환될 수 있다.
	
	예시 : std::string
			-> 문자열이 길어져도 계속해서 문자열 공간이 커진다.

	원리
	기존에 메모리 공간이 가득 차면 새로운 메모리를 할당 하고 기존에 메모리의 데이터를 복사한 후에 기존에 메모리는 해제한다.

	기능은
	init -> 배열 초기화
	pushBack() -> 데이터 순차적으로 넣기
	sort -> 정렬


	size() -> 현재 배열의 크기
	capacity -> 현재 메모리의 크기

	Reallocate -> 재할당

*/

/*
	구조체 or class
	한번 어떻게 만들지 해보자	
*/

#include <iostream>
#include <cassert>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <crtdbg.h>
#include "myArray.h"

using namespace std;


int main()
{
	//_CrtSetBreakAlloc(151);
	{
		// 조사식에서 "arr, mPArray, 숫자" 하면 해당 포인터에 연속된 데이터를 가져올 수 있다.
		myArray arr;

		arr.PushBack(200);
		arr.PushBack(100);
		//std::cout << arr.GetCapacity() << std::endl;
		arr.PushBack(500);
		arr.PushBack(450);
		//std::cout << arr.GetCapacity() << std::endl;
		arr.PushBack(60);
		//std::cout << arr.GetCapacity() << std::endl;

		for (int i = 0; i < arr.GetSize(); ++i)
		{
			std::cout << arr[i] << std::endl;
		}
		cout << endl << endl;
		arr.sort();
		for (int i = 0; i < arr.GetSize(); ++i)
		{
			std::cout << arr[i] << std::endl;
		}

		arr[1]++;

		arr + arr;



	}
	_CrtDumpMemoryLeaks();

	return 0;
}

