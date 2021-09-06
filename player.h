#pragma once
#include <iostream>
using namespace std;

class Player
{
private:
	friend class Team;              //Team class can all access all attributes of Player class.
	int player_no;
	string player_name;
	int NoOfmatches;
	int TotalRuns;
	int NoOfWickets;              //attributes of player class.
	int highestScore;
	double battingAvg;
	int ranking;
public:
	Player();

};