#include "GameManager.h"
#include "Player.h"
#include "Monster.h"

CGameManager::CGameManager()
{
	mPlayer = nullptr;
}

CGameManager::~CGameManager()
{

}


void CGameManager::GameRun()
{
	//게임 시작을 알리고싶다.
	//게임 초기화 Init
	if (!Init())
	{
		assert(0);
	}

	//게임 종료전까지 반복 while
	while (true)
	{
		//게임 그려주기	Draw
		Draw();
		//입력을 마지막에 해준다. 
		Input();
		//게임 로직 업데이트 update
		Update();
	}
	//게임 끝 해제해주기 Release
	Release();

}

void CGameManager::SaveLoadScreen()
{
	

	struct PlayerInfo
	{
		CGameManager* GameMgr = CGameManager::GetInst();
		CPlayer* pPlayer = GameMgr->GetPlayer();

		string pName = pPlayer->GetName();
		string pJob = pPlayer->JobToString(pPlayer->GetJobClass());
		int pExp = pPlayer->GetExp();
		int pLev = pPlayer->GetLevel();
		int pHP = pPlayer->GetHP();
		int pMoney = pPlayer->GetMoney();
		int pATK = pPlayer->GetATK();
		int pDEF = pPlayer->GetDEF();
	};
	

	//// 이름 직업 경험치 레벨 체력 돈 공 방
	//vector<string> pName{ pPlayer->GetName()};
	//vector<int> pState{ pPlayer->GetExp(),pPlayer->GetLevel(), pPlayer->GetHP(), pPlayer->GetMoney(), pPlayer->GetATK(), pPlayer->GetDEF() };

	vector<PlayerInfo> player;
	player.push_back(PlayerInfo{});

	ofstream oFile("PlayerData.txt");
	if (oFile.is_open())
	{


		for (auto& p : player)
		{
			oFile << stoi(p.pName) << ", " << stoi(p.pJob) << ", " << p.pExp << ", " << p.pLev << ", " << p.pHP << ", " << p.pMoney << ", " << p.pATK << ", " << p.pDEF << endl;
		}

		player.clear();
	}
	
	string path = "E:\SVN\cec0904\\textRPG\Save";




}

void CGameManager::SaveGame()
{

	
}

void CGameManager::LoadGame()
{


}

void CGameManager::NextStage()
{
	mStageLevel += 1;

	GlobalFunc::PrintUpFloor();
}

bool CGameManager::CreateMonster()
{
	// 몬스터 랜덤 생성 함수
	mMonster = new CMonster;
	if (mMonster == nullptr)
	{
		assert(0);
		return false;
	}


	return false;
}

bool CGameManager::IsValidMonster()
{
	if (mMonster)
	{
		return true;
	}
	return false;
}

void CGameManager::DeleteMonster()
{
	if (mMonster)
	{
		delete mMonster;
	}
	mMonster = nullptr;
}



bool CGameManager::Init()
{
	srand(time(0));
	//게임초기화 시작 
	//플레이어 생성 
	mPlayer = new CPlayer;
	if (mPlayer == nullptr)
	{
		assert(0);
		return false;
	}
	//플레이어초기화 
	mPlayer->Init();

	return true;
}

void CGameManager::GameProgressDraw()
{
	COUTN("-------------- 멸망의 탑 --------------");
	COUTN("|                                     |");
	COUTN("|           " << mStageLevel << "층 진행중                |");
	COUTN("|                                     |");
	COUTN("---------------------------------------");
}




void CGameManager::Update()
{

	if (mPlayer)
	{
		mPlayer->Update();
	}

	if (mMonster)
	{
		mMonster->Update();
	}
}






void CGameManager::Draw()
{
	// 화면 초기화
	SYSCLS;


	//지금 게임이 몇층에서 진행되고 있는지 출력
	GameProgressDraw();

	if (mMonster)
		mMonster->Draw();

	// 항상 nullptr 체크하는 버릇은 좋은거다
	// 실수방지
	if (mPlayer)
		mPlayer->Draw();
}

void CGameManager::Release()
{
	//게임종료 
	//플레이어 해제 
	if (mPlayer)
	{
		delete mPlayer;
		mPlayer = nullptr;
	}

	if (mMonster)
	{
		delete mMonster;
		mMonster = nullptr;
		
	}
}

void CGameManager::Input()
{
	COUTN("-------------------------------------------");
	COUT("행동을 선택해 주세요 : ");
	cin >> mInputMessage;
	SYSPAUSE;
	COUTN("-------------------------------------------");
}




