#include "stdafx.h"
#include "Room.h"


Room::Room() {}
string Room::look() {
	string retval = this->Description + "\r\n";
	for each (Player* player in players)
	{
		retval += player->Name + " is standing here...\r\n";
	}
	for each (NPC* npc in npcs)
	{
		retval += "A " + npc->Name + " is present...\r\n";
	}
	return retval;
}
Room::~Room()
{
}