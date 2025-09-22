/*
	실습
	배열 마지막? 실습
	빙고
	5 X 5 로 빙고 만들기

	빙고 맞춘 갯수 출력
	5빙고면 게임 종료
	- 선택한 숫자는 *로 바꾸기

	ps. 가능하면 내가선택하고 컴퓨터가 하나 선택하고 하는 적AI기능 만들어보기
*/

#include <iostream>

#include <time.h>

#define BINGOSIZE 25

using std::cout;
using std::cin;
using std::endl;

enum eFinishResultType
{
	NONE,	//결과가 안나왔을때 
	PlayerWIn,	//플레이어가 이겼을때 
	AIWin,	// AI가 이겼을때 
	Draw	//무승부
};

//빙고 계산할 변수 선언
int global_nLineCount = 0;	// 몇줄이 완성 되었는가 카운트 한다. 
int global_nAILineCount = 0;


bool ArrayInitialize(int* _array);

//디폴트 인자 
//함수의 매개변수에 기본값을 부여한다. 
// 만약 함수 사용시 매개변수에 데이터를 안넣어 준면 기본값으로 생성 된다. 
// !!조건이 디폴트 인자를 넣으면 그 오른쪽 매개변수들은 전부 디폴트 인자를 넣어줘야 한다. 
void ArraySuffle(int* _array, int SuffleCount = 100);	// 선언후 ctrl + .	정의만들기가 나온다. 
//함수 내용으로 바로 이동하고 싶으면 F12

void GameRun(int _PlayerBingo[], int _AIBingo[]);

void PrintBingoBoard(int _PlayerBingo[], int _AIBingo[]);

//게임 결과 출력해주는 함수 
//반환값은 열거형도 사용할수있다. 
//열거형도 자료형이기 때문이다. 
eFinishResultType FinishCheck();

//입력받기 함수 
// 반환값 : 0이면 종료, -1이면 이상한값 입력 1~25까지는 정상입력 
// //.
int Input();

//입력된 빙고 체크하기 
void BingoNumberCheck(int _array[], int num);

/////AI
int GetAIInputNumber(int* _array);

//체크하기 
//가로세로 
int CheckRowColumn(int _array[]);
//대각선 검사하기 
int CheckCross(int _array[]);


int main()
{
	srand((unsigned int)time(0));

	int nBingo[BINGOSIZE] = {};	//어차피 정수니까 안쓰는 정수를 이용하면 되지 않을까?
	//AI 의 빙고
	int nAIBingo[BINGOSIZE] = {};


	//초기화
	if (ArrayInitialize(nBingo))
	{
		cout << "플레이어 배열이 초기화 완료" << endl;
	}
	if (ArrayInitialize(nAIBingo))
	{
		cout << "AI 배열이 초기화 완료" << endl;
	}

	//셔플 
	ArraySuffle(nBingo, 1000);
	ArraySuffle(nAIBingo);

	///////빙고 게임 시작!!!
	GameRun(nBingo, nAIBingo);//함수 매개변수 목록 보고싶으면 ctrl + shift + space

	return 0;
}

//배열 초기화 함수 
bool ArrayInitialize(int* _array)
{
	//배열 초기화 
	for (int i = 0; i < BINGOSIZE; ++i) //되도록 후위말고 전위로 작성하자 
	{
		// 1 ~ 25 출력할것이다. 
		_array[i] = i + 1;
	}

	return false;
}

// 셔플함수 
void ArraySuffle(int* _array, int SuffleCount)
{
	for (int i = 0; i < SuffleCount; ++i)
	{
		int RandomIndex1 = rand() % BINGOSIZE;
		int RandomIndex2 = rand() % BINGOSIZE;
		int temp = 0;

		//스왑 
		temp = _array[RandomIndex1];
		_array[RandomIndex1] = _array[RandomIndex2];
		_array[RandomIndex2] = temp;
	}
}

//게임 시작 함수 
//매개변수 : 플레이어 빙고 배열, AI 빙고 배열 
void GameRun(int _PlayerBingo[], int _AIBingo[])
{
	while (true)
	{
		system("cls");

		PrintBingoBoard(_PlayerBingo, _AIBingo);


		// 결과 출력 
		cout << "빙고 갯수 : " << global_nLineCount;
		cout << "\t\t\t\t\t빙고 갯수 : " << global_nAILineCount << endl;

		//끝났는지 검사 
		if (FinishCheck() != eFinishResultType::NONE)
		{
			return;
		}

		//입력받기 
		int PlayerInput = Input();
		switch (PlayerInput)
		{
		case 0:
			return;
		case -1:
			continue;
		}

		//플레이어 입력을 빙고판에 그린다. 
		BingoNumberCheck(_PlayerBingo, PlayerInput);
		BingoNumberCheck(_AIBingo, PlayerInput);


		/////////////////////
		//AI 입력 받기 
		int AIInput = GetAIInputNumber(_AIBingo);

		BingoNumberCheck(_PlayerBingo, AIInput);
		BingoNumberCheck(_AIBingo, AIInput);


		global_nLineCount = 0;
		global_nAILineCount = 0;

		//가로세로 
		global_nLineCount = CheckRowColumn(_PlayerBingo);
		global_nAILineCount = CheckRowColumn(_AIBingo);

		//대간선 
		global_nLineCount += CheckCross(_PlayerBingo);
		global_nAILineCount += CheckCross(_AIBingo);
	}
}

void PrintBingoBoard(int _PlayerBingo[], int _AIBingo[])
{
	cout << "================ 플레이어 ========================== 적 =======================" << endl;
	for (int i = 0; i < 5; ++i) // i 는 행
	{
		//플레이어 
		for (int j = 0; j < 5; ++j) // j 는 열 
		{

			if (_PlayerBingo[i * 5 + j] == INT_MAX)
			{
				cout << "*\t";
			}
			else
			{
				cout << _PlayerBingo[i * 5 + j] << "\t";
			}
		}

		///경계선 그려주기 
		cout << "||\t";

		//적 AI 
		for (int j = 0; j < 5; ++j) // j 는 열 
		{

			if (_AIBingo[i * 5 + j] == INT_MAX)
			{
				cout << "*\t";
			}
			else
			{
				cout << _AIBingo[i * 5 + j] << "\t";
			}
		}
		cout << endl;//줄바꿈
	}
}

eFinishResultType FinishCheck()
{
	//5빙고 완성!!!!!
	if (global_nLineCount >= 5 && global_nAILineCount >= 5)
	{
		cout << "무승부입니다. 게임을 종료합니다." << endl;
		system("pause");
		return eFinishResultType::Draw;
	}
	else if (global_nLineCount >= 5)
	{
		//게임 종료 
		cout << "승리하셨습니다!! 게임을 종료합니다." << endl;
		system("pause");
		return eFinishResultType::PlayerWIn;
	}
	//AI 꺼 
	else if (global_nAILineCount >= 5)
	{
		//게임 종료 
		cout << "패배하였습니다ㅜㅜ 게임을 종료합니다." << endl;
		system("pause");
		return AIWin;
	}

	return eFinishResultType::NONE;
}

int Input()
{
	int input = 0;
	cout << "숫자를 입력하세요 (0 입력하면 종료): ";
	cin >> input;

	if (input == 0)
	{
		cout << "게임을 종료합니다." << endl;
		system("pause");
		return 0;
	}
	else if (input <= 0 || input > 25)	// 1보다 작거나 또는 25보다 크면
	{
		cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
		system("pause");
		return -1;
	}

	return input;
}

void BingoNumberCheck(int _array[], int num)
{
	// 선택된 숫자 마킹 해준다. 
	for (int i = 0; i < BINGOSIZE; ++i)
	{
		//들어온 배열 
		if (_array[i] == num)
		{
			_array[i] = INT_MAX;
		}
	}
}

int GetAIInputNumber(int* _array)
{
	//AI 가 뽑을 숫자는 
	int AISelectTotalNum = 0;//AI 가 선택할수 있는 숫자의갯수 

	//AI 숫자 뽑기
	int AISelect[25] = {};	// 중복숫자 없애기용도 

	//중복 없애기 
	for (int i = 0; i < 25; ++i)
	{
		if (_array[i] != INT_MAX)
		{
			AISelect[AISelectTotalNum] = _array[i];
			++AISelectTotalNum;
		}
	}
	//int SelectAIIndex = rand() % 25;	//버그 수정전 
	int SelectAIIndex = rand() % AISelectTotalNum;

	int AIInput = AISelect[SelectAIIndex];

	cout << "AI가 선택한 숫자는? : " << AIInput << endl;
	system("pause");

	return AIInput;
}

//가로세로 체크하기 
int CheckRowColumn(int _array[])
{
	int totalLineCount = 0;
	int StartCheck1 = 0, StartCheck2 = 0; // 한 줄에 별의 갯수를 센다. 

	// 가로 세로 
	for (int i = 0; i < 5; ++i)
	{
		StartCheck1 = 0;
		StartCheck2 = 0;

		for (int j = 0; j < 5; ++j)
		{
			//가로줄 체크해봅시다. 
			if (_array[i * 5 + j] == INT_MAX)
			{
				++StartCheck1;
			}
			//세로줄
			if (_array[i + j * 5] == INT_MAX)
			{
				++StartCheck2;
			}
		}
		if (StartCheck1 == 5)
		{
			++totalLineCount;

		}
		if (StartCheck2 == 5)
		{
			++totalLineCount;
		}
	}

	return totalLineCount;
}

int CheckCross(int _array[])
{
	//오른쪽위 아래쪽아래 대각선 
	int totalLineCount = 0;
	int StartCheck = 0;



	for (int i = 0; i < 25; i += 6)	// i 는 6씩 증가해야한다. 
	{
		if (_array[i] == INT_MAX)
		{
			//대각선이 별이냐? 
			++StartCheck;
		}
	}
	if (StartCheck == 5)
	{
		++totalLineCount;
	}

	//왼쪽위 오른쪽아래 대각선 
	StartCheck = 0;

	//인덱스 4로 시작해서 4씩 증가하고 20까지 검사해야한다. 
	for (int i = 4; i <= 20; i += 4)
	{
		if (_array[i] == INT_MAX)
		{
			//대각선이 별이냐? 
			++StartCheck;
		}

	}
	if (StartCheck == 5)
	{
		++totalLineCount;
	}
	return totalLineCount;
}

