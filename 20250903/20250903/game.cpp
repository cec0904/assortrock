/*
	베이스볼 게임
	규칙
	랜덤한 숫자 3개를 만듭니다.
	각각의 숫자는 1 ~ 9 사이의 숫자고, 중복이 없습니다.(같은 수는 없음) 1 2 3 / 5 6 7

	숫자를 맞추는 게임
	숫자를 맞추면 ball
	숫자의 위치도 맞추면 strike
	숫자가 하나도 안맞으면 out

	숫자 위치 모두 맞추면 3 strike -> 게임 종료

*/


#include <iostream>
#include <Windows.h>
#include <time.h>


using namespace std;


//int main()
//{
//
//	srand((unsigned int)time(0));
//
//	//int nRandomnumbers[3] = { 0, 3 };	//맞춰야 할 숫자 모음
//	//int nPlayernumbers[3] = { 0, 3 };	//플레이어가 맞춰야 할 숫자 모음
//
//	//// 맞출 때 까지 반복
//
//	//cout << "숫자 3개를 입력하세요(1~9, 중복없음) : ";
//	//cin >> nPlayernumbers[0] >> nPlayernumbers[1] >> nPlayernumbers[2];
//	//cout << "입력된 숫자는 : " << "nPlayernumbers[0], " << "nPlayernumbers[1], " << "nPlayernumbers[2]" << endl;
//
//	// 조건문으로 게임 규칙 만들어보기
//
//
//
//	int nR[3] = { 0,3 };
//	int nP[3] = { 0,3 };
//
//	int na[3] = { 0,3 };
//
//	int r = rand() % 10;
//
//	for (int i = 0; i < 3; i++)
//	{
//		
//		for (int j = 0; j < i; j++)
//		{
//			nR[i] = r;
//			if()
//		}
//
//		cout << nR[i];
//	}
//	
//
//
//
//
//
//
//	
//
//	cout << "숫자 3개를 입력하세요(1~9, 중복없음) : ";
//	cin >> nP[0] >> nP[1] >> nP[2];
//	cout << "입력된 숫자는 : " << nP[0] << ", " << nP[1] << ", " << nP[2] << endl;
//
//
//
//
//
//}




// 정답코드

int main() 
{
	int nR[3] = { 0 ,3 };
	int nP[3] = { 0 ,3 };


	srand((unsigned int)time(0));




	// 랜덤한 숫자 3개 만들어보기
	for (int i = 0; i < 3; i++)
	{
		nR[i] = rand() % 9 + 1;
		// 중복 검사
		for (int j = 0; j < i; j++) //배열의 앞부분 데이터만 검사한다.
		{
			if (nR[i] == nR[j])
			{
				--i;
				break;
			}
		}
	}
	Sleep(1000);
	cout << nR[0] << nR[1] << nR[2] << endl;



	// 맞을 때 까지 반복
	// strike 가 3개 일 때
	int strike = 0, ball = 0, out = 0;
	// 총 시도 횟수
	int total = 0;



	while (true)
	{
		//플레이어 숫자 3개를 입력받는다.
		cout << "숫자 3개를 입력하세요(1~9, 중복없음) : ";
		cin >> nP[0] >> nP[1] >> nP[2];
		cout << "입력된 숫자는 : " << nP[0] << ", " << nP[1] << ", " << nP[2] << endl << endl;

		// 스트라이크랑 볼 변수는 반복 돌 때마다 초기화 해줘야된다.
		strike = 0;
		ball = 0;
		

		// 스트라이크랑 볼 개수를 카운팅한다.




		// i 로는 nP 접근
		// j 로는 nR 접근
		for (int i = 0; i < 3; i++)
		{
			
			for (int j = 0; j < 3; j++)
			{
				if (nP[i] == nR[j]) // 볼 검사
				{
					// 위치가 같으면 스트라이크
					// i == j 면 같은 인덱스 번호, 같은 위치에 존재하는 같은 숫자
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball++;
					}
				}

				
				
			}

		}

		// 아웃 갯수 = 최대 아웃 갯수 - (strike + ball)
		out = 3 - (strike + ball);

		cout << out << "아웃, ";
		// 스트라이크랑 볼 갯수 출력해주기
		cout << strike << "스트라이크, " << ball << "볼" << endl;






		// 출력 해보기
		// out
		//if (strike == 0 && ball == 0)
		//{
		//	out++;

		//}

		total++;

		//3스트라이크면 게임 종료
		if (strike == 3)
		{
			//cout <<"아웃 총 횟수 : " << out << endl;
			cout << "3 스트라이크 ! 게임 종료 !!!" << endl;
			cout << "총 시도 횟수 : " << total << endl;
			return 0;
		}

	}
	
	return 0;

}