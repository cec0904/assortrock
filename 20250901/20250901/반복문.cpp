#include <iostream>

/*
	반복문 Loop
	특정 조건이 true(참) 인 동안 코드 블록을 반복 실행하는 제어 구조다.

	종류
	- while 문
	- do-while 문
	- for 문


	- 범위 기반 for 문


	반복문에서도
	break -> 그 반복문을 종료한다.
	continue -> 건너띄기 -> 
*/

int main()
{
	////
	while (true)
	{
		std::cout << "while문 진행중!!";
	}

	int n = 0;
	while (n < 10) // 조건이 안 맞으면 진입이 안된다.
	{
		++n;
		//조건이 맞으면 반복
		if (n % 2 == 0)
		{
			continue; // 반복문 건너띄기
		}




		std::cout << "while문 진행중!! count :" << n << std::endl;
		if (n == 5)
			break;
	}

	// do-while
	// 1번은 무조건 실행한다.
	// while 문 끝에 ; 을 붙여줘야 한다.
	do
	{
		std::cout << "do-while문 진행중!! count :" << n << std::endl;
		++n;
	} while (n < 10);


	///////////
	 //실습
	 //while 문 이용해서
	 //100까지의 홀수 출력
	 //5의 배수는 출력 안하기
	int a = 0;
	while (a < 100)
	{
		if (a == 100)
			int i = 10;

		a++;
		if (a % 2 == 0 || a % 5 == 0)
		{
			continue;
		}
		std::cout << " 실습문제 진행중!! count : " << a << std::endl;
		

	}



	///////////////////////////////
	 for 반복문
	 for(선언; 조건; 증감식){//코드 블록//}
	 조건이 맞으면 실행하고 증감식을 실행한다.

	for (int i = 0; i < 10; i++)	// for(for문에서 사용할 변수 선언 및 초기화; i가 10보다 작은경우 실행; i를 1씩 증가)
	{
		std::cout << i << std::endl;
	}

	int x = 0;
	for (; x < 10;)
	{
		std::cout << "for i : " << x << std::endl;
	}
	 범위기반 for문은 나중에 배울것이다.
	 자료구조가 선행되어야 하기 때문이다.
	 최소한 배열은 했어야 가능하기 때문에








	return 0;
}