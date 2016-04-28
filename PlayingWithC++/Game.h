#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include "Player.h"
#include "NPC.h"
#include "Room.h"
using namespace std;
class Game
{
private:
	Game* _game;
public:
	Game();
	Room AddNPCs(Room*);
	void AddRooms();
	Room findRoomById(int);
	std::vector<Player*> players;
	std::vector<NPC*> npcs;
	std::vector<Room*> rooms;
	
	~Game();

};
