/*
	기본자료형
	포인터 자료형
	레퍼런스 자료형

	사용자 정의 자료형
	구조체	struct
	열거체	enum	enum class
	클래스 class

	----------
	클래스도 결국 사용자가 만드는 자료형이다.

	구성
	클래스 내부에 선언되는 변수나 함수앞에 멤버라고 붙인다.
	변수 -> 멤버 변수 (데이터)
	함수 -> 멤버 함수 (기능)

	!!! "객체지향 프로그래밍"의 기본 단위가 된다.
	캡슐화
	
	상속
	다형성
	추상화

	///////////////////////////////
	접근지정자
	public:			외부에 모두가 사용 가능하다.
	protected:		상속된 클래스 내부에서만 사용 가능하다.
	private:		클래스 내부에서만 사용 가능하다.

	클래스는 기본 접근 지정자가 private 이다.
	구조체는 기본 접근 지정자가 public 이다.
	
*/

#include <iostream>
#include <string>
using namespace std;

struct sPerson
{
	//
public:		//구조체는 이게 생략되어 있다.
	string name;
	int age;

};





class Person
{
private:		//클래스는 private가 기본적으로 사용돼서 생략되어있다.

public:


	// 이름
	string nName;
	// 나이
	int nAge;

public:
	// Get Set 함수를 만들어서 인터페이스를 제공해준다.
	string GetName()
	{
		return nName;
	}

	void SetAge(int _age)
	{
		nAge = _age;
	}

	int GetAge()
	{
		return nAge;
	}

	/*
		생성자
		// 이 자료형으로 객체가 생성되었을때
		// 자동으로 호출되는 함수다.
	
	*/
	// 생성자
	Person() :
		nName("전의찬"),			// 초기화 방법
		nAge(26)
	{
		cout << "생성자" << endl;
	}

	/*
		//소멸자
		이 클래스의 객체가 소멸될때, 사라질때
		자동으로 호출되는 함수다.

	*/

	~Person()		// 소멸자
	{
		cout << "소멸자" << endl;
	}

public:
	// 멤버 함수에서 멤버 변수 접근 할 때는 그냥 사용 가능하다
	// 점 붙일 필요 없다.
	void PrintMyInfo()
	{
		cout << nName << endl;
		cout << nAge << endl;
	}

	// 클래스 내부에서 사용될 때는
	// 사실 this 라는 키워드가 숨겨져 있다.
	void SetMyInfoOthers(string nName, int nAge)
	{
		this -> nName = nName;
		this -> nAge = nAge;

		cout << this -> nName << endl;
		cout << this->nAge << endl;
	}
};



int main()
{
	{
		Person person1;
		Person person2;
		Person person3;


		person1.PrintMyInfo();
		person2.SetMyInfoOthers("엄준호",80);

		person2.PrintMyInfo();



		// 함수를 통해서
		person3.SetAge(20);

		person3.GetName();
		person3.GetAge();
	}
	
	/*
	* //멤버변수 private
		이름
		나이
		학번
		국 영 수
		평균 합계


		// 한번에 입력받고
		// 각자 입력받기

		// 출력 해보기


	*/





	return 0;
}