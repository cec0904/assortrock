/*
	//멤버변수 private
	이름
	나이
	학번
	국 영 수
	평균 합계

	//한번에 입력받고
	//각자 입력받기

	// 출력 해보기
*/
#include <iostream>
#include <string>

class CStudent
{
private:
	//이름
	std::string mName;
	//나이
	int mAge;
	//학번
	int mID;
	//국 
	int mKor;
	//영 
	int mEng;
	// 수
	int mMath;
	//평균 
	float mAvg;
	//합계
	int mTotal;

public:
	CStudent() = delete;
	//한번에 받기는 생성할때만 가능하게 하고싶다. 이걸 필수로 하고싶다. 
	CStudent(std::string _name, int _age, int _id, int _kor, int _eng, int _math)
	{
		mName = _name;
		mAge = _age;
		mID = _id;
		mKor = _kor;
		mEng = _eng;
		mMath = _math;
		mTotal = mKor + mEng + mMath;
		mAvg = (float)mTotal / 3;
	}
	~CStudent() = default;

public:
	//Getter 함수 내부 멤버 변수를 가져오는 함수를 만들 것이다. 
	// 직접 데이터 접근 못하게 하고 싶어서 
	std::string GetName()
	{
		return mName;
	}
	int GetAge() { return mAge; }
	int GetID() { return mID; }
	int GetKorScore() { return mKor; }
	int GetEngScore() { return mEng; }
	int GetMathScore() { return mMath; }
	int GetTotal() { return mTotal; }
	int GetAvg() { return mAvg; }

	void SetKorScore(int _kor)
	{
		mKor = _kor;
		reCalculate();
	}
	void SetEngScore(int _eng)
	{
		mEng = _eng;
		reCalculate();
	}
	void SetMathScore(int _math)
	{
		mMath = _math;
		reCalculate();
	}

	void PrintStudentInfo()
	{
		std::cout << "학생이름\t:\t" << mName << std::endl;
		std::cout << "나이\t\t:\t" << mAge << std::endl;
		std::cout << "학번\t\t:\t" << mID << std::endl;
		std::cout << "국어 점수\t:\t" << mKor << std::endl;
		std::cout << "영어 점수\t:\t" << mEng << std::endl;
		std::cout << "수학 점수\t:\t" << mMath << std::endl;
		std::cout << "점수 총합\t:\t" << mTotal << std::endl;
		std::cout << "점수 평균\t:\t" << mAvg << std::endl;
	}


private:
	void reCalculate()
	{
		mTotal = mKor + mEng + mMath;
		mAvg = (float)mTotal / 3;
	}
};


int main()
{
	CStudent student1("윤영호", 30, 11223344, 50, 60, 70);

	student1.PrintStudentInfo();

	student1.SetKorScore(80);
	student1.SetEngScore(90);
	student1.SetMathScore(70);

	student1.PrintStudentInfo();

	return 0;
}
