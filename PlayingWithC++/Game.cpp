#include "stdafx.h"
#include "Game.h"
using namespace std;
Game::Game() {}

void Game::AddRooms() {
	Room* room = new Room();
	room->Name = "Entry Hall";
	room->id = 1;
	room->Description = "This area has a large highly polished marble entry way.";
	rooms.push_back(room);
	AddNPCs(room);
}
Room Game::findRoomById(int id) {
	std::vector<Room*>::iterator it;
	int n = 0;
	for (it = this->rooms.begin(); it != this->rooms.end(); it++)
	{
		if ((*it)->id == id) return *this->rooms[n];
		n++;
	}
	return *this->rooms[0];
}
Room Game::AddNPCs(Room *room) {
	NPC* npc = new NPC();
	npc->Name = "Wolf";
	room->npcs.push_back(npc);
	npcs.push_back(npc);
	return *room;
	//room.npcs.push_back(npc);
}

Game::~Game()
{
}
