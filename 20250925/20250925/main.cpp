/*
	vector

	템플릿으로 나만의 가변배열 만들어보기
	pushback	0
	size		0
	resize		0
	reserve		0
	clear		0

	front
	back

	//접근 연산자 까지 한번 만들어봅시다.
	int& operator[](int index)
	{
		return mPArray[index];
	}

*/
class number
{
private:
	int* num;

public:
	number& operator=(const number& other)
	{
		num = new int;
		*num = *other.num;
	}

};
#include <iostream>
#include "MyVector.h"

int main()
{
	CMyVector<float> myArr;
	myArr.reserve(10);
	myArr.push_back(10.f);
	myArr.push_back(90.f);
	myArr.push_back(30.f);


	std::cout << myArr.front() << std::endl;
	std::cout << myArr.back() << std::endl;


	for (int i = 0; i < myArr.size(); ++i)
	{
		std::cout << myArr[i] << std::endl;
	}

	myArr.clear();

	for (int i = 0; i < myArr.size(); ++i)
	{
		std::cout << myArr[i] << std::endl;
	}

	CMyVector<long long> longVector;
	longVector.push_back(10L);


	return 0;
}