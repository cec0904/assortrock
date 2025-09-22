#include <iostream>
using namespace std;

struct info
{
	char name[20];
	int id = 0;
	int sum = 0;
	int avg = 0;
};

info Score(int Score1, int Score2, int Score3)
{
	info sScore;


	cout << "국어, 영어, 수학 점수를 순서대로 입력해주세요 : ";
	cin >> Score1 >> Score2 >> Score3;

	sScore.sum = Score1 + Score2 + Score3;

	sScore.avg = (Score1 + Score2 + Score3) / 3;

	return sScore;
}






int main()
{
	info input;




	cout << "이름을 입력해주세요 : ";
	cin >> input.name;
	cout << endl;

	cout << "학번을 입력해주세요 : ";
	cin >> input.id;
	cout << endl;
	/*
	cout << "국어, 영어, 수학 점수를 순서대로 입력해주세요 : ";
	cin >> info.score1 >> info.score2 >> info.score3;
	cout << endl;


	cout << info.name << " 학생의 학번은 " << info.id << " 이고 점수 총점은 " << info.sumFunc(info.score1, info.score2, info.score3) << "점 이고 점수 평균은 " << info.avgFunc(info.score1, info.score2, info.score3) << "점 입니다." << endl;*/

	cout << input.name << " 학생의 점수 총합은 " << input.sum << "점 이고 평균은 " << input.avg <<" 점 입니다."






}