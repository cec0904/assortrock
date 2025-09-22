#include <iostream>
#include <Windows.h> // 윈도우 관련 함수를 사용 할 수 있게 해주는 헤더
#include <time.h> // 시간 관련 함수를 사용할 수 있게 해주는 헤더

using namespace std;

// 랜덤한 정수 가져와 보기
// iostream 요즘에는 헤더에 기능이 들어가있다.
// 
// 
// srand() -> 패턴 Seed 설정한다. // 마크 랜덤맵 생성 seed 와 같이 패턴 생성 할 때 사용된다.
// 컴퓨터의 랜덤은 무작위가 아닌 seed를 통해서 패턴을 반환해주는 것이다.
// 
// 랜덤의 범위 지정은 나머지 연산으로 할 수 있다. 
// rand() % 원하는 범위
// 0이상 최대값 미만
// 
// rand() -> 랜덤한 정수를 가져온다.








int main()
{

	//현재 시간으로 시드값을 정해준다.
	srand((unsigned int)time(0));


	//while (true)
	//{
	//	cout << rand() << endl;

	//	Sleep(1000); // ms 밀리세컨드
	//}
	//

	// 랜덤한 값을 원하는 범위 만큼만 가져오는 방법은 ?
	// 나머지 연산을 이용하면 값의 범위를 지정할 수 있다.


	while (true)
	{
		cout << rand() % 10 << endl;		// 10 이하의 수가 나옴

		Sleep(1000); // ms 밀리세컨드
	}





	return 0;
}