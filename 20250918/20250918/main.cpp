/*
	reinterpret_cast
	용도
	-> 포인터를 다른 타입의 포인터로 강제로 변환시킬 때 사용한다.
	-> void* 로 변환시킬 때 많이 사용했다.


*/







#include <iostream>
#include <vector>



using namespace std;

int main()
{
	int number = 100;
	int* pNumber = &number;

	// 이런식으로 포인터를 다른 타입으로 강제로 변환시킬 때 사용한다.
	void* pVoid = reinterpret_cast<void*>(pNumber);

	cout << number << endl;
	cout << &number << endl;
	cout << pNumber << endl;
	cout << pVoid << endl;
	

	cout << endl;

	vector<void*> addressArr;
	addressArr.push_back(pNumber);

	float* pPi = new float(3.14);
	addressArr.push_back(reinterpret_cast<void*>(pPi));

	void* pPast = (void*)pPi;


	return 0;
}