// PlayingWithC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NPC.h"
#include "Room.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int userAge = 0;
char userFavLetter = '\0';
bool gameloop = true;
long ticks = 0;
string command = "";
bool hasCommand = false;
Player* player = new Player();
std::vector<NPC> npcs;
std::vector<Room> rooms;
bool log(const std::string &text){
	std::ofstream log_file(	"log_file.txt", std::ios_base::out | std::ios_base::app);
	log_file << "\r\n" <<text;
	return true;
}
Room findRoomById(int id) {
	vector<Room>::iterator i;
	int n = 0;
	for (i = rooms.begin(); i != rooms.end(); ++i)
	{
		if (i->id == id) return rooms[n];
		n++;
	}
	return rooms[0];
}
string doCommand(string command) {
	if (command == "look") {
		return findRoomById(player->RoomID).look();
	}
	return "";
}

void task1(std::string msg)
{
	while (gameloop) {
		ticks++;
		if (hasCommand) {
			ticks = 0;
			cout << doCommand(command) << "\r\n";
			hasCommand = false;
		}
	}
}

void getInput() {
	cin >> command;
	if (command != "quit" && command != "exit") {
		hasCommand = true;
		getInput();
	}
	else {
		hasCommand = false;
		gameloop = false;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Please enter your name: ";
	cin >> player->Name;
	cout << "welcome " << player->Name;

	NPC* npc = new NPC();
	npc->Name = "Wolf";
	npcs.push_back(*npc);

	Room* room = new Room();
	room->Name = "Entry Hall";
	room->id = 1;
	room->npcs.push_back(npc);
	room->Description = "This area has a large highly polished marble entry way.";
	rooms.push_back(*room);
	player->RoomID = room->id;
	command = "look";
	hasCommand = true;

	std::thread t1(task1, "Hello");
	getInput();
	cout << "Thank you for playing!";
	gameloop = false;

	t1.join();
	return 0;
}

