#include <iostream>
using namespace std;

/*
	typedef 키워드
	자료형에 또다른 별명 별칭을 지어준다.
*/



typedef struct sLocation
{
	int x;
	int y;
	int z;
}LOCATION, *PLOCATION;

/*
	using
	typedef 비슷한 기능을 사용한다.
	하지만 더 많은 기능이 있다.

	typedef 와의 차이점
	-> 템플릿에는 using 사용가능, typedef는 사용 불가능
*/

using namespace std;
using UINT = unsigned int;

using MYLOCATIONNAME = sLocation;
using PMYLOCATIONNAME = sLocation*;


//////////////////////////////////////
/*
	enum			// 상수에 이름을 지어주는거다.
*/

enum test
{
	t1,
	t2,
	t3
};
enum temp
{
	t1,
	t2,
	t3
};

int main()
{
	sLocation myLoc;
	sLocation* pMyLoc;

	LOCATION myMomLoc;
	PLOCATION pMomLoc = &myMomLoc;

	MYLOCATIONNAME myLoccc;
	PMYLOCATIONNAME pMyLoccc = &myLoccc;


	LOCATION myFatherLoc;
	PLOCATION pFatherLoc = &myFatherLoc;


}