#include <iostream>

#include <sstream>  //stringstream 을 사용하기 위한 헤더다.
#include <string>

#include <direct.h>
#include <vector>
#include <fstream>

struct PlayerInfo
{
    std::string name;
    std::string job;
    int money;
};


int main()
{
    std::vector<PlayerInfo> players;
    players.push_back(PlayerInfo({ "윤영호", "전사", 100 }));
    players.push_back(PlayerInfo({ "유제상", "마법사", 100 }));
    players.push_back(PlayerInfo({ "허재영", "도적 ", 100 }));

    std::ofstream oFile("VectorData.txt");

    //vector 에 저장된 데이터 파일로 출력하기(저장하기)
    if (oFile.is_open())
    {
        for (auto& player : players)
        {
            oFile << player.name << "," << player.job << "," << player.money << "\n";
        }
        oFile.close();
    }

    players.clear();

    std::ifstream iFile("VectorData.txt");

    if (iFile.is_open())
    {
        std::string line = " ";
        while (std::getline(iFile, line))
        {
            //한줄씩 읽는데 
            //해당 줄이 공백인가 확인해야 한다. 
            if (line.empty())
            {
                continue;
            }

            std::stringstream tempStringStream(line);
            PlayerInfo player;
            std::string strMoney;

            std::getline(tempStringStream, player.name, ',');  //strtok();
            std::getline(tempStringStream, player.job, ',');
            std::getline(tempStringStream, strMoney, ',');

            player.money = std::stoi(strMoney); // 문자열을 정수로 

            players.push_back(player);
        }



    }



    return 0;
}