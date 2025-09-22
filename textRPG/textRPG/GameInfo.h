#pragma once
//모두 컴파일된 헤더
#include <iostream>
#include <Windows.h>

#include <assert.h>

#include <string>
#include <vector>

using namespace std;

//std 하나씩 붙이자 using X

//싱글톤 매크로 
#define DECLARE_SINGLETON(classname) private:\
classname();\
~classname();\
public:\
	static classname* GetInst()\
	{\
		static classname Inst;\
		return &Inst;\
	}

#define SYSCLS system("cls")
#define SYSPAUSE system("pause")

#define COUT(TEXT) std::cout << TEXT;
#define COUTN(TEXT) std::cout << TEXT << std::endl;

#define DEFAULT_HP 100
#define DEFAULT_ATK 10
#define DEFAULT_DEF 5

enum class eJobClass
{
	NONE,
	Warrior,
	Wizard,
	Archer,
	Rogue,
	MAX
};

enum class ePlayerState
{
	//탐색
	research,
	//전투
	combat,
	END
};

enum class eEventType
{
	NONE,
	Treasure,
	Enemy,
	Next,
	MAX
};

enum class eMonsterType
{
	Slime,		//하
	Goblin,		//중
	Orc,		//상
	End
};


namespace GlobalFunc
{
    static void PrintSlimeImage()
    {
        std::cout << R"(
                     *
                    *
                *  *  *
              *         *
             *  [  [     *
              *         *
                *  *  *
)" << std::endl;
    }



    static void PrintUpFloor()
    {
        for (int openingWidth = 0; openingWidth < 12; ++openingWidth)
        {
            SYSCLS;
            const int height = 12;
            const int width = 30;
            const int center = width / 2;
            std::string message = "Next Stage";

            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    // 문틀 그리기
                    if ((y == 0 || y == height - 1) && (x > 0 && x < width - 1)) {
                        printf("-");
                    }
                    else if (y > 0 && y < height - 1 && (x == 0 || x == width - 1)) {
                        printf("|");
                    }
                    else if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                        printf("+");
                    }
                    // 문짝 그리기
                    else {
                        int leftDoorEdge = center - openingWidth;
                        int rightDoorEdge = center + openingWidth;

                        // 왼쪽 문
                        if (x > 0 && x <= leftDoorEdge) {
                            // 문고리
                            if (y == height / 2 && x == leftDoorEdge - 1) {
                                printf("o");
                            }
                            else {
                                printf("#");
                            }
                        }
                        // 오른쪽 문
                        else if (x >= rightDoorEdge && x < width - 1) {
                            // 문고리
                            if (y == height / 2 && x == rightDoorEdge + 1) {
                                printf("o");
                            }
                            else {
                                printf("#");
                            }
                        }
                        // 문이 완전히 열렸을 때 메시지 표시
                        else if (openingWidth >= center - (message.length() / 2) - 2 && y == height / 2) {
                            int msg_start_pos = center - message.length() / 2;
                            if (x >= msg_start_pos && x < msg_start_pos + message.length()) {
                                printf("%c", message[x - msg_start_pos]);
                            }
                            else {
                                printf(" ");
                            }
                        }
                        // 그 외 빈 공간
                        else {
                            printf(" ");
                        }
                    }
                }
                printf("\n");

            }
            Sleep(500);
        }
    }

}