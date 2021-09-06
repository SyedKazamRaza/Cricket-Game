#pragma once
#include <string>
#include <iostream>
#include "scoreCard.h"
#include <fstream>                     //including header files that required.
#include "toss.h"
#include <iomanip>
#include "player.h"
using namespace std;
class Team :public scorecard                //inheriting from scorecard class.
{
private:
	Player p[11];                              //objects of Player class.
	int wickets;
	int yourTeamID;
	int opponentID;
	int score;
	string teamName;
	int tempY;
	int tempO;
	static int fteam;                      //static variable, commom for all objects of Team class.
	Toss t;
public:
	Team();
	void setToss(Toss);                            //functions prototypes.
	void selectTeam();
	void setTeam(int);
	void selectOpponent();
	void displayTeam();
	void yourSummary();
	void oppSummary();
};
