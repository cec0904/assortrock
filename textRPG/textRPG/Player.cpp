#include "Player.h"
#include "GameManager.h"
#include "Monster.h"


CPlayer::CPlayer()
	:mState(ePlayerState::research)
{

}

CPlayer::~CPlayer()
{

}


bool CPlayer::Init()
{
	//이때 타이틀 보여주면서 
	printf("\n");
	printf("  ████   ████  ████   ████  ████   ████  ████   ████\n");
	printf("  █  █   █  █  █  █   █  █  █  █   █  █  █  █   █  █\n");
	printf("  █  █   █  █  █  █   █  █  █  █   █  █  █  █   █  █\n");
	printf("  █  █   █  █  █  █   █  █  █  █   █  █  █  █   █  █\n");
	printf("  ████   ████  ████   ████  ████   ████  ████   ████\n");
	printf("\n");
	printf("      ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ\n");
	printf("      ㅁ                                    ㅁ\n");
	printf("      ㅁ          멸  망  의   탑           ㅁ\n");
	printf("      ㅁ                                    ㅁ\n");
	printf("      ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ\n");
	printf("                Doom Tower\n\n");

	COUT("이름을 입력해주세요 : ")
	cin >> mName;

	int selectJob = 0;

	do
	{
		COUTN("직업을 선택해주세요.");
		COUTN("1.전사 2.마법사 3.궁수 4.도적");
		cin >> selectJob;
	} while (selectJob < 1 || selectJob > 4);

	//직업에 따라 시작 스탯을 다르게 한다. 
	mJob = (eJobClass)selectJob;
	switch (mJob)
	{
	case eJobClass::Warrior :			// 전사
		AllStateSet(200, 10, 10, 10);
		break;
	case eJobClass::Wizard :			// 마법사
		AllStateSet(150, 12, 6, 12);
		break;
	case eJobClass::Archer:				// 궁수
		AllStateSet(100, 15, 7, 15);
		break;
	case eJobClass::Rogue :				// 도적
		AllStateSet(130, 14, 6, 13);
		break;
	}
	

	return true;


}

void CPlayer::Draw()
{
	//플레이어의 기본 정보를 출력해준다. 
	PlayerInfoDraw();


	if (mState == ePlayerState::research)
	{
	//플레이어가 할수있는일
	PlayerSearchDraw();

	}
	else if (mState == ePlayerState::combat)
	{
		PlayerCombatDraw();
	}
}

void CPlayer::Update()
{
	int message = CGameManager::GetInst()->GetInputMessage();

	switch (mState)
	{
	case ePlayerState::research:
		BasicStateUpdate(message);
		break;
	case ePlayerState::combat:
		CombatStateUpdate(message);
		break;
	case ePlayerState::win:
		WinUpdate(message);
	case ePlayerState::lose:
		LoseUpdate(message);
		
	}
}

void CPlayer::PlayerInfoDraw()
{
	COUTN("-------------- 플레이어 정보 --------------");
	//이름
	COUT("이름\t: " << mName << "\t\t|\t");
	//직업
	COUTN("직업\t: " << JobToString(mJob));
	//경험치/최대 목표 경험치 
	COUT("경험치\t: " << mEXP << " / " << mMaxExp << "\t|\t");
	//레벨
	COUTN("레벨\t: " << mLevel);
	//체력 
	COUT("체력\t: " << mHP << " / " << mMaxHP << "\t|\t");
	//돈
	COUTN("돈\t: " << mMoney);
	//ATK
	COUT("공격력\t: " << mATK << "\t\t|\t");
	//DEF
	COUTN("방어력\t: " << mDEF);
	//SPD
	COUTN("스피드\t: " << mSPD << "\t\t|\t");
	COUTN("-------------------------------------------");
}

void CPlayer::PlayerSearchDraw()
{
	COUTN("");
	COUTN("\t=================================");
	COUTN("\t|            행동 선택           |");
	COUTN("\t---------------------------------");
	COUTN("\t|     [1] 탐색        [2] 휴식   |");
	COUTN("\t=================================");
}

void CPlayer::PlayerCombatDraw()
{
	COUTN("");
	COUTN("\t=================================");
	COUTN("\t|   [1] 공격          [2] 방어   |");
	COUTN("\t---------------------------------");
	COUTN("\t|   [3] 버프          [4] 도망   |");
	COUTN("\t=================================");
}

std::string CPlayer::JobToString(eJobClass _job)
{
	switch (_job)
	{
	case eJobClass::Warrior:
		return string("전사");
	case eJobClass::Wizard:
		return string("마법사");
	case eJobClass::Archer:
		return string("궁수");
	case eJobClass::Rogue:
		return string("도적");
	}
}

void CPlayer::BasicStateUpdate(int _message)
{
	switch (_message)
	{
	case 1:	// 탐색 
		SearchUpdate(_message);
		break;
	case 2:	// 휴식 

		break;
	}
}

void CPlayer::CombatStateUpdate(int _message)
{
	CGameManager* GameMgr = CGameManager::GetInst();
	CPlayer* pPlayer = GameMgr->GetPlayer();
	CMonster* pMonster = GameMgr->GetMonster();
	switch (_message)
	{
	case 1:
		mCombatMod = ePlayerCombatMod::Attack;

		if (pMonster->GetSPD() < pPlayer->GetSPD())
		{
			pPlayer->TakeDamage(pPlayer->GetATK() - pMonster->GetDEF());
			// 호출한 객체에게 피해를 주는 멤버 함수
			// 몬스터에게 내 공격력 만큼 피해를 준다.
			cout << pMonster->GetName() << "에게 " << mATK << "만큼 피해를 주었습니다." << endl;
			Sleep(1500);
			pMonster->TakeDamage(pMonster->GetATK() - pPlayer->GetDEF());
			cout << pMonster->GetName() << "가 " << mATK << "만큼 피해를 주었습니다." << endl;
			
		}
		else
		{
			pPlayer->TakeDamage(pPlayer->GetATK() - pMonster->GetDEF());
			cout << pMonster->GetName() << "(이)가 " << mATK << "만큼 피해를 주었습니다." << endl;
			Sleep(1500);
			pMonster->TakeDamage(pMonster->GetATK() - pPlayer->GetDEF());
			// 호출한 객체에게 피해를 주는 멤버 함수
			// 몬스터에게 내 공격력 만큼 피해를 준다.
			cout << pMonster->GetName() << "에게 " << mATK << "만큼 피해를 주었습니다." << endl;
		}

		SYSPAUSE;
		
		if (CGameManager::GetInst()->GetMonster()->GetHP() <= 0)
		{
			int a = rand() % 10 + 1;
			int b = rand() % 10 + 1;

			cout << a << "경험치와 " << b << "골드를 획득했습니다." << endl;
			SYSPAUSE;
			mEXP += a;
			mMoney += b;

			CGameManager::GetInst()->DeleteMonster();
			mState = ePlayerState::research;
		}
		break;
	case 2:
		
		if (pMonster->GetATK() <= pPlayer->GetDEF())
		{
			cout << "방어! 받은 피해: ";
			pPlayer->TakeDefense(1);
		}
		else if(pMonster->GetATK() > pPlayer->GetDEF())
		{
			cout << "방어! 받은 피해: ";
			TakeDefense(pMonster->GetATK() - pPlayer->GetDEF());
		}
		//else if (pPlayer->GetATK() > pMonster->GetDEF())
		//{
		//	cout << "방어! 몬스터가 받은 피해: " << pMonster->GetDEF() - pPlayer->GetATK() << endl;
		//}
		//else if (pPlayer->GetATK() < pMonster->GetDEF())
		//{
		//	cout << "방어! 몬스터가 받은 피해: 1";
		//}

		
		break;
	case 3:
		mCombatMod = ePlayerCombatMod::SpeedDown;
		pMonster->TakeSpeedDown(1);
		COUTN(mName << "이 상대 스피드를 낮췄습니다.");
		SYSPAUSE;
		break;
	case 4:
		mCombatMod = ePlayerCombatMod::Run;
		COUTN(mName << "이 도망을 선택했습니다.");
		mState = ePlayerState::research;
		GameMgr->DeleteMonster();
		SYSPAUSE;
		break;

	}
}
void CPlayer::WinUpdate(int _message)
{
	
}

void CPlayer::LoseUpdate(int _message)
{
}

void CPlayer::SearchUpdate(int _message)
{
	//나중에 함수화 해야한다. 

		//탐색 중입니다. 
	COUTN("탐색 중 입니다.");
	// 3초정도 뜸들이고 
	Sleep(500);
	COUTN("...");
	Sleep(500);
	COUTN("...");
	Sleep(500);
	COUTN("...");

	int temp = 0;
	temp = (rand() % (int)eEventType::MAX);

	

	/*1. 아무것도 못찾음
	2. 몬스터 조우
	3. 보물 찾기
	4. 다음 층 이동
	*/

	switch (eEventType::Enemy)
	//switch ((eEventType)temp)
	{
	case eEventType::NONE:
		//아무것도 못찾았습니다. 
		//그럼 그냥 다시 행동 선택하게 한다. 
		COUTN("아무것도 못찾았습니다.");
		SYSPAUSE;
		break;
	case eEventType::Next:
		//타워의 다음층으로 이동시켜야한다. 
		// 층을 어디에 저장할지 생각해 봐야할거같다. 
		CGameManager::GetInst()->NextStage();
		break;
	case eEventType::Treasure:
		//보물을 찾았습니다.
		//골드(돈)가 증가하면 될거같고.
		temp = 0;
		temp = rand() % 1000;
		COUTN(temp << "원을 찾았습니다.");
		mMoney += temp;
		SYSPAUSE;
		break;

	case eEventType::Enemy:
		// 적을 생성한다
		if (CGameManager::GetInst()->IsValidMonster())
		{
			assert(0);
			
			
			return;
		}
		// 이때 몬스터를 만들어주고 싶다.
		CGameManager::GetInst()->CreateMonster();
		// 플에이어는 전투 중 상태로 변경한다.
		mState = ePlayerState::combat;
		break;

	}
	

}


