#include "toss.h"

Toss::Toss()
{
	choose = '0';                  //initializing private members.
	decision = '0';
}
void Toss::DecisionOfToss()
{
	setOvers();
	unsigned seed = time(0);                     //for random numbers. 
	srand(seed);
	int c;
	cout << "					Toss Time" << endl;
	cout << "Enter your choice (H for head & T for tail): ";
	cin >> choose;
	while (choose != 'T' && choose != 't' && choose != 'H' && choose != 'h')
	{
		cout << "Enter only valid character: " << endl;
		cin >> choose;
	}
	int ch;
	if (choose == 'H' || choose == 'h')
		ch = 1;
	else
		ch = 0;
	c = (rand() % (max - min + 1) + min);
	if (c == ch)                                      //1 stands for Head and 0 for tail
	{
		cout << "You Win the Toss." << endl;
		cout << "Press T for Bat first and L for ball first: ";
		cin >> decision;
		while (decision != 't' && decision != 'T' && decision != 'l' && decision != 'L')
		{
			cout << "Enter the valid number: ";
			cin >> decision;
		}
		if (decision == 'T' || decision == 't')
		{
			cout << "			<----You are Batting first-->" << endl;
			batting();
			target = yourTotalScore;
			showScorecard1();
			cout << "					Target: " << yourTotalScore + 1 << endl;
			t = 1;
			bowling();
			showScorecard2();
		}
		else
		{
			cout << "			<----You are Bowling first-->" << endl;
			bowling();
			target = oppTotalScore;
			showScorecard2();
			cout << "						Target: " << oppTotalScore + 1 << endl;
			t = 1;
			batting();
			showScorecard1();
		}                                                            //calling functions of batting and bowling in 
	}																					//different orders.
	else
	{
		cout << "You Loss the Toss ";
		int v = (rand() % (max - min + 1) + min);               //computer choose to bat or bowl randomly.
		if (v == 1)
		{
			cout << "and your opponent decided to bowl first." << endl;
			cout << "			<---You are Batting first--->" << endl;
			batting();
			showScorecard1();
			target = yourTotalScore;
			cout << "						Target: " << yourTotalScore + 1 << endl;
			t = 1;
			bowling();
			showScorecard2();
		}
		else
		{
			cout << "and your opponent decided to bat first." << endl;
			cout << "			<---You are bowling first--->" << endl;
			bowling();
			showScorecard2();
			target = oppTotalScore;
			cout << "					Target: " << oppTotalScore + 1 << endl;
			t = 1;
			batting();
			showScorecard1();
		}
	}
	DecisionOfGame();                                       //function for decision of Game.
}

int* Toss::getOppRuns() {
	return oppRuns;
}
int* Toss::getYourRuns() {
	return yourRuns;
}