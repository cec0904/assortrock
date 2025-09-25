#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// 포인터 주소값 갖고 있는 자료형
// 레퍼런스는 하나의 별칭
// 원본은 똑같다 이름이 다를뿐

/*
	vector

	템플릿으로 나만의 가변배열 만들어보기
	pushback
	size
	resize
	reserve
	clear
	front
	back

	// 접근 연산자 까지 한번 만들어보자
	int& operator[](int index)
	{
		return mPArray[index];
	}


*/

template<typename T>
class CMyArray
{
private:
	T* pint;
	int count;
	int maxcount;


public:
	void PushBack(const T& Data);
	void Resize(int ResizeCount);
	void Sort();
	
	T& operator[] (int index);

public:
	CMyArray();
	~CMyArray();


};


template<typename T>
CMyArray<T>::CMyArray()
	:pint(nullptr),
	count(0),
	maxcount(2)
{
	pint = new T[2];
}
template<typename T>
CMyArray<T>::~CMyArray()
{
	for (int i = 0; i < count; i++)
	{
		cout << pint[i] << endl;
	}
	delete[] pint;
	count = 0;
	maxcount = 0;
}
template<typename T>
// PushBack 에서 MyArray.h 에 정의만들기
void CMyArray<T>::PushBack(const T& Data)
{
	if (this->maxcount <= this->count)
	{
		Resize(maxcount * 2);
	}

	pint[this->count++] = Data;
}
// Resize 에서 MyArray.h 에 정의만들기
template<typename T>
void CMyArray<T>::Resize(int ResizeCount)
{
	// 현재 최대 수용량 보다 더 적은 수치로 확장하려는 경우
	if (maxcount >= ResizeCount)
	{
		assert(nullptr);
	}
	// 1. 리사이즈 시킬 개수만큼 동적할당 한다.
	T* pnew = new T[ResizeCount];

	// 2 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < this->count; i++)
	{
		pnew[i] = this->pint[i];
	}
	// 3. 기존 공간은 메모리 해제
	delete[] pint;
	// 4. 배열이 새로 할당된 공간을 가리키게 한다.
	this->pint = pnew;
	//5 . maxcoyunt 변경점 적용
	this->maxcount = ResizeCount;
}
// Sort 에서 MyArray.h 에 정의만들기
template<typename T>
inline void CMyArray<T>::Sort()
{
	while (1)
	{
		if (count < 1)
		{
			break;
		}
		bool finish = true;
		for (int i = 0; i < count - 1; i++)
		{
			if (pint[i] > pint[i + 1])
			{
				int re = pint[i];
				pint[i] = pint[i + 1];
				pint[i + 1] = re;
				finish = false;
			}
		}
		if (finish == true)
		{
			break;
		}
	}
}

template<typename T>
inline T& CMyArray<T>::operator[](int index)
{
	// TODO: 여기에 return 문을 삽입합니다.
	return pint[index];
}

