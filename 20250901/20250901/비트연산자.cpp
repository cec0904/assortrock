/*
	기본 연산자 중 하나이다.
	비트 연산자
	-> 비트 조종 하는 연산자 이다.


					명칭								간략한 설명
	- a & b			AND								두 비트를 비교 했을 때 모두 1인 경우만 1
	- a | b			OR								두 비트를 비교 했을 때 둘 중 하나라도 1인 경우만 1
	- a ^ b			XOR								두 비트를 비교 했을 때 다를 경우만 1
	- a ~ b			NOT								비트를 반전시킨다. 0이면 1, 1이면 0으로 변환시킨다.
	- a << n		왼쪽 시프트						비트를 왼쪽으로 n 칸씩 이동시킨다. 한칸이동 곱하기 2
	- a >> n		오른쪽 시프트						비트를 오른쪽으로 n 칸씩 이동시킨다. 한칸이동 나누기 2
	
	n은 정수



*/


#include <iostream>

//비트를 보여주는 기능을 가지고 있는 클래스의 헤더이다.
#include <bitset>

int main()
{

	char a = 5;
	char b = 128;
	//char 1바이트 -> 8비트

	std::bitset<8> bits_a(a);
	std::cout << bits_a << std::endl;


	std::bitset<8> bits_b(b);
	std::cout << bits_b << std::endl;

	//AND 비트연산
	char andResult = a & b;
	std::bitset<8> bits_andResult(andResult);
	std::cout << bits_andResult << std::endl;

	//OR 비트연산
	char orResult = a | b;
	std::bitset<8> bits_orResult(orResult);
	std::cout << bits_orResult << std::endl;

	//XOR 비트연산
	char xorResult = a | b;
	std::bitset<8> bits_xorResult(xorResult);
	std::cout << bits_xorResult << std::endl;



	//not 비트 연산
	// a = 5
	// ~a -> ~5 가 되는 거 아니야 ?


	//NOT 비트연산
	char notResult = a | b;
	std::bitset<8> bits_notResult(notResult);
	std::cout << bits_notResult << std::endl;



	a = 7;//0111
	b = 3;//0011
	int c = -3;
	std::bitset<8> bits_c(c);
	std::cout << bits_c << std::endl;
	//result = a - b; // 7-3
	//result = a + (-b);// 7 + (-3)
	//CPU 가 덧셈계산이 빠르기 때문에
	//빼기를 할 때 덧셈연산으로 변환시켜서


}