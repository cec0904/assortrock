#pragma once
#include <utility>		// 이동 생성자 사용용도 std::move
using namespace std;

template<typename T>
class CMyVector
{
private:
	T* arr = nullptr;
	int mCapacity = 2;
	int mSize = 0;

public:
	// 기본생성자
	CMyVector()
	{
		mCapacity = 2;
		arr = new T[mCapacity];
		mSize = 0;
	}

	// 복사생성자
	CMyVector(const CMyVector& other)
	{
		// 얕은복사, 깊은복사 차이 다시한번 복습
		//arr = other arr;
		arr = new T[other.mCapacity];
		mCapacity = other.mCapacity;
		mSize = other.mSize;
		
		for (int i = 0; i < mSize; i++)
		{
			arr[i] = other.arr[i];
		}
	}

	// 이동생성자
	CMyVector(CMyVector&& other)
	{
		arr = move(other.arr);
		mCapacity = move(other.mCapacity);
		mSize = move(other.mSize);

		// 이동 완료 후 기존의 데이터를 초기화 해줘야한다.
		other.arr = nullptr;
		other.mCapacity = 0;
		other.mSize = 0;
	}

	// 소멸자
	~CMyVector()
	{
		if (arr != nullptr)
		{
			delete[]arr;
		}
	}

	//함수
	//반환 함수명(매개변수)
	//	{

	//}

	// 연산자
	//대입연산자
	CMyVector& operator = (const CMyVector& other)
	{
		// 기존의 데이터는 초기화 해준다.
		delete[] arr;
		mCapacity = 0;
		mSize = 0;

		// 대입 해줄건데
		arr = new T[other.mCapacity];
		mCapacity = other.mCapacity;
		mSize = other.mSize;

		for (int i = 0; i < mSize; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	// 대입연산자 이동
	CMyVector& operator = (CMyVector&& other)
	{
		// 기존에 데이터는 초기화 해준다.
		delete[] arr;
		mCapacity = 0;
		mSize = 0;

		// 대입 해줄건데
		arr = move(other.arr);
		mCapacity = move(other.mCapacity);
		mSize = move(other.mSize);

		// 기존 vector 는 초기화 해준다.
		other.arr = nullptr;
		other.mCapacity = 0;
		other.mSize = 0;
	}

	// 데이터 접근 가능 연산자 만들어 둔거다.
	T& operator[](int index)
	{
		return arr[index];
	}

public:
	void push_back(const T& value)
	{
		//mSize > mCapacity 보다 크면 재할당을 해줘야한다.
		if (mSize >= mCapacity)
		{
			mCapacity *= 2;
			T* newArr = new T[mCapacity];
			// 새로 공간을 만든 것이다.

			for (int i = 0; i < mSize; i++)
			{
				newArr[i] = arr[i];
			}
			delete[] arr;	// 기존 공간 해제하고
			arr = newArr;	// 새로 만든 공간의 주소를 넣어준다.
		}

		arr[mSize++] = value;
	}

	unsigned int size()
	{
		return mSize;
	}
	unsigned int capacity()
	{
		return mCapacity;
	}
	void resize(const int& size)
	{
		// 사이즈가 늘어나면 공간도 늘려줘야한다.
		if (size > mCapacity)
		{
			//재할당
			mCapacity = size;
			T* newArr = new T[mCapacity];
			for (int i = 0; i < size; i++)
			{
				newArr[i] = NULL;
			}

			for (int i = 0; i < mSize; i++)
			{
				newArr[i] = arr[i];
			}
			delete arr;
			arr = newArr;
		}
		else if (size < mSize)
		{
			for (int i = size; i < mSize; i++)
			{
				arr[i].~T();
				// 뒤의 객체의 소멸자를 호출해준다.
			}
			mSize = size;
		}
		mSize = size;
	}
	void reserve(const int& capacity)
	{
		if (capacity > mCapacity)
		{
			T* newArr = new T[capacity];
			for (int i = 0; i < mSize; i++)
			{
				newArr[i] = arr[i];
			}
			delete[] arr;
			arr = newArr;
			mCapacity = capacity;

		}
	}
	void clear()
	{
		for (int i = 0; i < mSize; i++)
		{
			arr[i].~T();
		}
		mSize = 0;
	}
	T front()
	{
		return arr[0];
	}
	T back()
	{
		return arr[mSize - 1];
	}

};