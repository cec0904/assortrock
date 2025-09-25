#include <iostream>
class cAc
{
public:
	cAc()
	{
		std::cout << "생성자입니다." << std::endl;
	}

	cAc(cAc& other)
	{
		std::cout << "복사 생성자입니다." << std::endl;
	}

	cAc(const cAc& other)
	{
		std::cout << "복사 생성자입니다." << std::endl;
	}

	cAc(cAc&& other) noexcept
	{
		std::cout << "이동 생성자입니다." << std::endl;
	}
	~cAc()
	{
		std::cout << "소멸자 입니다." << std::endl;
	}


};

cAc Func(cAc other)
{
	return other;
}

int main()
{
	cAc t;

	Func(t);
}