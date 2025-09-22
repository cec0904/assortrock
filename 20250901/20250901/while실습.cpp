///////////
// 실습
// while 문 이용해서
// 100까지의 홀수 출력
// 5의 배수는 출력 안하기

#include <iostream>

#define MAX_LOOP 100

int main()
{
	int a = 0;
	while (a <= MAX_LOOP) //while문 써보기
	{
	
		if (a % 2 != 0 && a%5!=0)
		{
			/*if (a % 5 == 0)
			{
			std::cout << " 5의 배수 : " << a << std::endl;
			++a;
				continue;
			}*/

			std::cout << " 실습문제 진행중!! count : " << a << std::endl;
		}

		
		++a;

	}

	return 0;
}