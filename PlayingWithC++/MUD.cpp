// PlayingWithC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
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
Game* game = new Game();
bool log(const std::string &text){
	std::ofstream log_file(	"log_file.txt", std::ios_base::out | std::ios_base::app);
	log_file << "\r\n" <<text;
	return true;
}

string doCommand(string command) {
	if (command == "look") return game->findRoomById(player->RoomID).look();
	if (command == "hello") return "The Darkness replies...";
	return "\r\n";
}

void task1()
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
	game->players.push_back(player);
	game->AddRooms();
	//command = "look";
	//hasCommand = true;

	std::thread t1(task1);
	getInput();
	cout << "Thank you for playing!";
	gameloop = false;
	t1.join();
	return 0;
}

