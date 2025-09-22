#include <iostream>

/*
	// 학점 출력하기
	// while 문으로 원할 때 까지 반복하기


	// 점수를 입력하면 학점을 출력해 주는 프로그램을 만들고 싶다.
	// 조건
	// 90점 이상 A
	// 80점 이상 B
	// 70점 이상 C
	// 60점 이상 D
	// 0점 이상 F
	// -99 프로그램 종료
	// 0~100 이상 점수가 아니면 -> 잘못된 입력입니다. 출력
	//

*/
using namespace std;


int main()
{
	int score = 0;
	int n = 0;
	int sum = 0;
	int avg = 0;

	while (score != -99)
	{
		cout << "점수를 입력해주세요 : ";
		cin >> score;

		cout << '\n';
		

		n++;

		






		if (score >= 90 && score <= 100)
		{
			cout << "학점은 A 입니다." << '\n';
			cout << '\n';
			cout << '\n';
		}
		else if (score < 90 && score >= 80)
		{
			cout << "학점은 B 입니다." << '\n';
			cout << '\n';
			cout << '\n';
		}
		else if (score < 80 && score >= 70)
		{
			cout << "학점은 C 입니다." << '\n';
			cout << '\n';
			cout << '\n';
		}
		else if (score < 70 && score >= 60)
		{
			cout << "학점은 D 입니다." << '\n';
			cout << '\n';
			cout << '\n';
		}
		else if (score < 60 && score >= 0)
		{
			cout << "학점은 F 입니다." << '\n';
			cout << '\n';
			cout << '\n';
		}
		else if (score > 100 || score < 0)
		{
			cout << "잘못된 입력입니다." << '\n';
			cout << '\n';
			cout << '\n';
			continue;
		}
		else if (score == -99)
		{
			cout << "종료합니다.";
			break;
		}


		sum += score;
		avg = sum / n;

		cout << n << "명의 점수는 " << sum << "점 입니다." << endl;
		cout << '\n';

		cout << "가장 마지막으로 입력된 점수는 " << score << "점 입니다." << endl;
		cout << '\n';

		cout << n << "명의 평균은 " << avg << "점 입니다." << endl;
		cout << '\n';
		cout << '\n';




	}



	//int score = 0;
	//

	//cout << "성적을 입력해 주세요 : ";
	//cin >> score;
	//int a = score / 10;


	//switch (a) 
	//{
	//case 10 :
	//	cout << "학점은 A 입니다.";
	//	break;
	//case 9 :
	//	cout << "학점은 A 입니다.";
	//	break;
	//case 8:
	//	cout << "학점은 B 입니다.";
	//	break;
	//case 7:
	//	cout << "학점은 C 입니다.";
	//	break;
	//case 6:
	//	cout << "학점은 D 입니다.";
	//	break;
	//case 5:
	//case 4:
	//case 3:
	//case 2:
	//case 1:
	//case 0:
	//	cout << "학점은 F 입니다.";
	//	break;

	//default:
	//	cout << "잘못된 입력입니다.";
	//	break;

	//
	//}







}









