/*
	우리가 일반적으로 사용하는 사칙연산부터 조건연산
	계산, 논리, 대입등을 수행하는 기호를 연산자라고 한다.

	//기본 연산자

	- 산술 연산자 -> +, -, *, /, %
	- 증감 연산자 -> ++, --
	- 비교 연산자 -> ==, !=, >, <, >=, <=
	- 논리 연산자 -> &&, ||, !
	- 비트 연산자 -> &, |, ^, ~, <<, >>
	- 대입 연산자 -> =, +=, -=, *=, /=, %=
	- 포인터 연산자 -> *, &, ->, sizeof
	- 기타 연산자 -> ?:, , , typeid, ., ::, sizeof

	



	// 사용자 정의 연산자

*/

#include <iostream>

enum CoffeeMenu
{
	Americano = 1,	//명시를 안하면 시작은 0부터 시작합니다.
	CafeLatte =2,	//1
	Cappuccino,	//2
	Frappe	//3
};


int main()
{
	CoffeeMenu menu = Americano;
	std::cout << menu << std::endl;





	// 산술 연산자
	// 정수나 실수에 대해서 사칙연산(더하기, 빼기, 곱하기, 나누기, 나머지)를 수행하는 연산자
	// +, -, *, /, %
	// 
	// 
	// 
	// 
	// 나누기는 0 으로 나누면 Error 나온다
	// % 는 정수 연산만 가능하다

	//int a = 5, b = 2; //a 라는 변수명으로 int 자료형을 생성할건데 5로 초기화 하면서 생성 하겠다.
	////b 라는 변수명으로 int 자료형을 생성할건데 2로 초기화 하면서 생성 하겠다.
	//int sum = 0; //더하기 결과값

	//sum = a + b; // a 와 b 를 더한 값을 sum 에 넣어라
	//std::cout << "더하기 : " << sum << std::endl;

	//int diff = 0; // 빼기 결과값
	//diff = a - b;
	//std::cout << "빼기 : " << diff << std::endl;

	//int multi = 0; // 곱하기 결과값
	//multi = a * b;
	//std::cout << "곱하기 : " << multi<< std::endl;

	//int div = 0; // 나누기 결과값
	//div = a / b; // b != 0
	//std::cout << "나누기 : " << div << std::endl;

	//int remain = 0; // 나머지 결과값
	//remain = a % b; // b != 1.2f
	//std::cout << "나머지 : " << remain << std::endl;


	//// 증감 연산자
	//// 변수의 값을 1만큼 증가 또는 감소시키는 연산자
	//// 주의 : 1의 단위는 자료형 마다 다를 수 있다.
	//// 정수 : 1
	//// 포인터 : 64비트 - 8
	//// 전위, 후위가 존재한다

	//int nIncrease = 0;
	//std::cout << "정수 값 : " << nIncrease << std::endl; 
	//std::cout << "++정수 값 : " << ++nIncrease << std::endl; 
	//std::cout << "정수++ 값 : " << nIncrease++ << std::endl; 

	//std::cout << "--정수 값 : " << --nIncrease << std::endl;
	//std::cout << "정수-- 값 : " << nIncrease-- << std::endl; 








	//// 대입 연산자
	//// =
	//// 오른쪽에서 왼쪽으로 값을 넣어준다
	//// ps, rvalue, lvalue


	//// +=, -=, *=
	//int number = 0;
	//// +=
	//number = number + 10; // number 값(0) + 10 을 number 에 대입해준다.
	//number += 10;
	//
	//std::cout << number << std::endl;
	//number -= 10;

	//std::cout << number << std::endl;
	//number *= 2;

	//std::cout << number << std::endl;
	//number /= 2;

	//std::cout << number << std::endl;
	//number %= 2;



	//// 실습
	//// 숫자 실수 2개 입력 받아서
	//// 각각의 사칙연산한 결과 값을 출력해보자, 나머지 제외
	//int A = 0;
	//float B = 0;
	//std::cout << "숫자 A를 입력하세요 : ";
	//std::cin >> A;
	//std::cout << "숫자 B를 입력하세요 : ";
	//std::cin >> B;
	//std::cout << "A + B : " << A + B << std::endl;
	//std::cout << "A - B : " << A - B << std::endl;
	//std::cout << "A * B : " << A * B << std::endl;
	//std::cout << "A / B : " << A / B << std::endl;


	// int 2개 입력받고 두수중 어느 수가 더 큰지 출력해주기

	//int a, b = 0;
	//
	//std::cin >> a >> b;
	//if (a > b)
	//{
	//	std::cout << a << "가" << b << "보다 더 큽니다." << std::endl;
	//}
	//else if (a == b)
	//{
	//	std::cout << a << "와" << b << "가 같습니다." << std::endl;
	//}
	//else
	//{
	//	std::cout << b << "가" << a << "보다 더 큽니다." << std::endl;
	//}

	/////////////////////////////////////////////////
	//switch 문
	//int n = 0;
	//std::cout << "입력 :";
	//std::cin >> n;

	//switch (n)
	//{
	//case1:
	//	std::cout << "case 1 입니다." << std::endl;
	//	break;
	//case2:
	//	std::cout << "case 2 입니다." << std::endl;
	//	break;
	//case3:
	//	std::cout << "case 3 입니다." << std::endl;
	//	break;
	//case4:
	//	std::cout << "case 4 입니다." << std::endl;
	//	break;
	//case5:
	//	std::cout << "case 5 입니다." << std::endl;
	//	break;
	//case6:
	//	std::cout << "case 6 입니다." << std::endl;
	//	break;
	//case7:
	//	std::cout << "case 7 입니다." << std::endl;
	//	break;

	//	// 위에 case 가 아닌 모든 값들이 여기로 들어온다.
	//default:
	//	std::cout << "해당없음
	//		" << std::endl;
	//	break;
	//}


	int a = 0;

	std::cout << "1번 아메리카노" << " " << "2번 카페라떼" << " " << "3번 카푸치노" << " " << "4번 프라페" << std::endl;
	std::cout << "주문 번호를 입력하세요 : ";
	std::cin >> a ;
	switch(a)
	{
	case 1:
		std::cout << "주문하신 아메리카노 나왔습니다." << std::endl;
		break;
	
	case 2:
		std::cout << "주문하신 카페라떼 나왔습니다." << std::endl;
		break;
	
	case 3:
		std::cout << "주문하신 카푸치노 나왔습니다." << std::endl;
		break;
	
	case 4:
		std::cout << "주문하신 프라페 나왔습니다." << std::endl;
		break;
	

	default:
		std::cout << "잘못 된 선택입니다." << std::endl;
		break;
	}









	return 0;
}