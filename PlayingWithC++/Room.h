#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Player.h"
#include "NPC.h"
using namespace std;
class Room
{
private:
	int member;

public:
	Room();
	int id = 0;
	string Name = "";
	string Description = "";
	std::vector<Player*> players;
	std::vector<NPC*> npcs;
	string look();
	~Room();

};