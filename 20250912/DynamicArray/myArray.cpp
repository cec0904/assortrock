#include "myArray.h"
#include <cstdlib>
#include <cassert>
#include <iostream>

myArray::myArray()
{
	// 생성자
	initArr();
}

myArray::~myArray()
{
	// 소멸자
	if (mPArray)
	{
		free(mPArray);
		mCapacity = 0;
		mSize = 0;
	}
}

void myArray::PushBack(const int& data)
{
	// capacity 보다 size 가 같거나 크면 메모리재할당을 해준다.
	if (mCapacity <= mSize)
	{
		Reallocate();
	}

	// 데이터를 넣고 mSize의 크기를 늘려준다.
	mPArray[mSize++] = data;
}

void myArray::sort()
{
	for (int i = 0; i < mSize - 1; i++)
	{
		for (int j = 0; j < mSize - i -1; j++)
		{
			if (mPArray[j] > mPArray[j + 1])
			{
				int temp = mPArray[j];
				mPArray[j] = mPArray[j + 1];
				mPArray[j + 1] = temp;
			}
		}
	}

}


bool myArray::initArr()
{
	// 여기에 구현하면 된다.


	mSize = 0;
	mCapacity = 2;
	mPArray = (int*)malloc(mCapacity * sizeof(int));	// 총 8바이트

	if (mPArray == nullptr)
	{
		return false;
	}

	return false;
}

void myArray::Reallocate()
{
	// 새로운 메모리 할당 받고 잠시 그 주소를 pTemp에 넣어준다.
	int* pTemp = (int*)malloc(mCapacity * 2 * sizeof(int));

	if (pTemp == nullptr)		// nullptr 나올 수 있기 때문에 밑에서 두배 해준다.
	{
		assert(0);		// 문제 있으니 경고 띄운다.
	}

	// 새로운 공간에 기존의 데이터를 복사해준다.
	for (int i = 0; i < mSize; i++)
	{
		pTemp[i] = mPArray[i];
	}

	// 기존 메모리는 해제한다.
	free(mPArray);
			
	// 새로 할당 된 공간을 가리키게 한다.
	mPArray = pTemp;

	mCapacity *= 2;		// nullptr 나올 수 있기 때문에, 동적할당이 실패할 수 있기 때문에 밑에서 두배 해준다. capacity의 카운트를 2배 늘려준다
}
