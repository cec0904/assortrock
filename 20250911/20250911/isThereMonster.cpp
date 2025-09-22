#include <iostream>
#include <cstring>
using namespace std;

#define MONSTER_LIST_COUNT 10
#define MONSTER_NAME_MAX_LENGTH 100

// "Goblin, Orc, Dragon, Skeleton, Zombie, Troll, Vampire, Ghost, Hydra, Slime";
// 해당 문자열 분리해서		//strtok
// 배열에 넣고
// cin 입력시 해당 몬스터 문자열이 있는지 여부 출력		// strcmp
// 
// 
//


int main()
{
	char Monsters[] = { "Goblin,Orc,Dragon,Skeleton,Zombie,Troll,Vampire,Ghost,Hydra,Slime" };

	char monsterList[MONSTER_LIST_COUNT][MONSTER_NAME_MAX_LENGTH]{};

	char* token = nullptr;
	char* context = nullptr;
	token = strtok_s(Monsters, ",", &context);
	
	int count = 0;
	while (token != nullptr)
	{
		strcpy_s(monsterList[count], MONSTER_NAME_MAX_LENGTH, token);

		char Input[MONSTER_NAME_MAX_LENGTH];
		cout << "찾고 싶은 몬스터는 ? " << endl;
		cin >> Input;


		bool bIsMonsterValid = false;


		for (int i = 0; i < MONSTER_LIST_COUNT; i++)
		{
			if (strcmp(Input, monsterList[i]) == 0)
			{
				bIsMonsterValid = true;
				cout << "몬스터가 리스트에 존재합니다." << endl;
			}

		}

		if (bIsMonsterValid)
		{
			cout << "몬스터가 리스트에 존재합니다.";
		}
		else
		{
			cout << " 몬스터가 리스트에 존재하지 않습니다.";
		}
	}


	
}