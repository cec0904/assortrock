#pragma once
class myArray
{
private:
	// 멤버 변수 선언
	// 배열을 들고 있을 주소
	int* mPArray = nullptr;
	// 배열에서 사용하고 있는 배열의 길이
	int mSize = 0;
	// 배열이 할당된 메모리의 크기
	int mCapacity = 0;

	// 클래스 내부에서만 사용할거니까 private로 외부에서 사용 못하게 한다.
	bool initArr();
	void Reallocate();

public:
	myArray();		// 객체가 생성될 때 호출된다.
	~myArray();		// 객체가 소멸될 때 호출된다.

	// 데이터 넣는 함수
	void PushBack(const int& data);

	int GetSize() { return mSize; }
	int GetCapacity() { return mCapacity; }
	// 배열에 직접 접근하는 위험한 함수이므로 주석처리
	// int* GetArray() { return mPArray; }

	void sort();

	//
public:
	// 연산자도 사용자 정의가 가능하다.
	// 키워드는 operator 라는 키워드를 이용할 수 있다.
	int& operator[](int index)
	{
		return mPArray[index];
	}

	myArray& operator+(const myArray& _ref)
	{

	}

	int& operator++(int)
	{

	}

};