#include <iostream>
#include <vector>

using namespace std;
/*
	템플릿 template
	하나의 자료형에 국한하지 않고 일반화하여 만들어주는 기능



*/


int add(int _n1, int _n2)
{
	return _n1 + _n2;
}



// 자료형 하나 받는 방법
template<typename T>
T add(T _n1, T _n2)
{
	return _n1 + _n2;
}

template<typename T>
T sub(T _n1, T _n2)
{
	return _n1 - _n2;
}

// 자료형 두개 받는 방법
template<typename T1, typename T2>
T1 AddFunc(T1 _n1, T2 _n2)
{
	T1 result;
	result = _n1 + _n2;
	return result;
}

// 클래스도 템플릿으로 만들 수 있다.
template<typename T>
class numbers
{
public:
	vector<T> arr;
	T mData;

	void reFunc(T _in)
	{
		cout << _in << endl;
	}
};

// 곱하기
template<typename T>
T mul(T _n1, T _n2)
{
	T result;
	result = _n1 * _n2;
	return result;
}
// 나누기
template<typename T>
T div(T _n1, T _n2)
{
	T result;
	result = _n1 / _n2;
	return result;
}



int main()
{
	//vector<int> arr;
	// int형으로 만들어준다.

	add<int>(10, 20);
	add<float>(10.f, 20.f);
	add(30, 60);

	add<double>(40.0, 20.0);
	sub(30, 20);	// 안써도 되긴함

	
	
	cout << mul<int>(10, 20) << endl;
	cout << div<int>(30, 20) << endl;

	AddFunc(10, 20.f);
	cout << AddFunc<float, char>(3.4, 'c') << endl;

	numbers<double> myNumbersClass;
	myNumbersClass.arr;
	myNumbersClass.mData;



	return 0;
}
