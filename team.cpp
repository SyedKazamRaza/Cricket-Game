#include "team.h"
int Team::fteam = 0;                  //initializing static variable.
Team::Team()
{
	wickets = 0;
	score = 0;
	teamName = "0";
	yourTeamID = 0;
	opponentID = 0;
}
void Team::selectTeam()                                //function for selecting the teams.
{
	cout << "Select the teams: " << endl;
	cout << "Teams: " << endl;
	cout << "1   Pakistan" << endl << "2   India" << endl << "3   Austalia" << endl;
	cout << "Press relevant integer to select your team: ";
	cin >> yourTeamID;
	while (yourTeamID != 1 && yourTeamID != 2 && yourTeamID != 3)
	{
		cout << "You can only select team from obove teams.ReEnter number: ";
		cin >> yourTeamID;
	}
	fteam = yourTeamID;
	setTeam(yourTeamID);                           //calling the function to set team.
}

void Team::selectOpponent()
{
	cout << "Press relevant integer to select opponent team: ";
	cin >> opponentID;
	while (opponentID == fteam || (opponentID != 1 && opponentID != 2 && opponentID != 3))
	{
		if (opponentID == fteam)
		{
			cout << "Select another team as your opponent.ReEnter number: ";
			cin >> opponentID;
		}
		else
		{
			cout << "You can only select opponent from above teams.ReEnter number : ";
			cin >> opponentID;
		}
	}
	setTeam(opponentID);
}

void Team::setTeam(int n)
{
	ifstream fin;
	if (n == 1)
		fin.open("Pakistan.txt");
	else if (n == 2)
		fin.open("India.txt");                   //Reading data from different files depending upon the selected teams.
	else
		fin.open("Austalia.txt");       
	if (!fin)
	{
		cout << "File Not Found." << endl;
	}
	else
	{
		for (int i = 0; i < 11 && fin; i++)
		{
			fin >> p[i].player_no;
			fin >> p[i].player_name;
			fin >> p[i].NoOfmatches;
			fin >> p[i].TotalRuns;
			fin >> p[i].NoOfWickets;
			fin >> p[i].highestScore;
			fin >> p[i].battingAvg;
			fin >> p[i].ranking;
		}
		fin.close();
	}
}

void Team::displayTeam()
{
	cout << left;
	cout << setw(7) << "Player#   " << setw(12) << "Name " << setw(7) << "Matches " << setw(5) << "Runs " << setw(7) << " Wickets " << setw(12) << "HighestScore " << setw(6) << "BatAvg " << setw(10) << "BatRanking " << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 11; i++)
	{
		cout << left;
		cout << setw(7) << p[i].player_no << " ";
		cout << setw(12) << p[i].player_name << " ";
		cout << setw(7) << p[i].NoOfmatches << " ";
		cout << setw(4) << p[i].TotalRuns << " ";
		cout << setw(7) << p[i].NoOfWickets << " ";                //displaying player's profiles.
		cout << setw(12) << p[i].highestScore << " ";
		cout << setw(6) << p[i].battingAvg << "  ";
		cout << setw(10) << p[i].ranking << "  ";
		cout << endl;
	}
}

void Team::yourSummary()
{
	yourRuns = t.getYourRuns();                              //calling function of Toss class.
	cout << "******************************************************************" << endl;
	cout << "        ->Your Team Scorecard<-" << endl;
	cout << setw(7) << "Player_no" << "	" << setw(12) << "Players" << "	 " << "Score" << endl;
	for (int i = 0; i < 11; i++)
	{
		cout  <<setw(7) << p[i].player_no << "		" << setw(12) << p[i].player_name << "	     " << yourRuns[i] << endl;
	}
}
void Team::oppSummary()
{
	oppRuns = t.getOppRuns();
	cout << "*****************************************************************" << endl;
	cout << "		->Opponent Team Scorecard<-" << endl;
	cout << setw(7) << "Player_no" << "	" << setw(12) << "Players" << "	" << "Score" << endl;
	for (int i = 0; i < 11; i++)
	{
		cout << setw(7) << p[i].player_no << "		" << setw(12) << p[i].player_name << "	" << oppRuns[i] << endl;
	}
	cout << "*****************************************************************" << endl;
}

void Team::setToss(Toss temp)
{
	this->t = temp;
}