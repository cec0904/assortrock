/*
	가변배열

	stl(standard template library)		MS 전용이 아닌 모두의 것
	
*/

//std::string 은 문자만 받는 가변배열이면
// vector는 모든 자료형에 대응 할 수 있는 가변 배열이다.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct sLocation
{
	int x = 0;
	int y = 0;
	int z = 0;
};

class Animal
{
	string sName;

};



int main()
{
	vector<float> aFloatVector;
	vector<sLocation> aLocVector;
	vector<Animal> aAnimals;
	vector<Animal*> aPAnimals;

	// 문자열을 벡터배열에 받는거다.담는거다.
	vector<string> Jobs = { "전사", "궁수" };
	///////////////////////////////////

	// 원소(데이터) 추가하기
	Jobs.push_back("마법사");
	Jobs.push_back("도적");
	Jobs.push_back("힐러");


	// 데이터 가져오기도 배열이랑 같다.
	Jobs[0];
	cout << Jobs[0] << endl;
	//*(Jobs + 0)		// 배열은 주소 그 자체였지만, vector 는 클래스다.

	//벡터 크기
	Jobs.size();
	Jobs.capacity();

	//첫번째 데이터 가져오기
	cout << Jobs.front() << endl;
	//특정 데이터 가져오기
	cout << Jobs.at(2) << endl;
	//마지막 데이터 가져오기
	cout << Jobs.back() << endl;

	cout << endl << endl;

	// 특정 요소 삭제
//Jobs.begin() 은 0 인덱스이다
//2번째 인덱스 삭제
	Jobs.erase(Jobs.begin() + 1);

	//전부 순회
	for (auto job : Jobs)
	{
		cout << job << endl;
	}

	// 모든 데이터 삭제
	Jobs.clear();

	////////////////////////////////
	// 동적할당으로 int 만들었다.
	vector<int*> numbers;
	numbers.push_back(new int(1));
	numbers.push_back(new int(2));
	numbers.push_back(new int(3));
	numbers.push_back(new int(4));

	for (auto* data : numbers)
	{
		delete data;
	}





	// auto 
	// 자동으로 자료형을 인식해서 변환함
	// 남발하면 코드를 볼 때 뭘로 되는지 알아볼 수 없음
	// 

	/*
		resize -> 배열의 길이를 매개변수만큼 정해둔다.
		reserve -> 배열의 메모리를 예약해둔다.(데이터를 아직 넣지 않았는데 복사하는데 비용이 많이 들어 복사를 최소화하기 위해 미리 잡아두는 것)
	*/

	//vector<string> tests;
	//tests.reserve(10);
	//tests.resize(10);




	return 0;



}