#include <iostream>
#include "toss.h"
#include "team.h"                     //including header files.
using namespace std;

int main()
{printf("\n'Beware of bugs in the above code; I have only proved it correct, not tried it.'\n");printf("\n-------------------------------Code OutPut--------------------------------------\n");
	cout << "						:) Cricket Match (:" << endl;
	Team team1, team2;                                               //objects of Team class.
	team1.selectTeam();
	cout << endl << "		>>>Your Playing Squard<<<" << endl;
	team1.displayTeam();

	team2.selectOpponent();
	cout << endl << "		>>>Computer Playing Squard<<<" << endl;
	team2.displayTeam();

	Toss toss;                                                          //Calling appropraite functions 
	toss.DecisionOfToss();                                                             //of Different classes.

	cout << "			---->>>>>Match Summary<<<<<----" << endl;
	team1.setToss(toss);
	team2.setToss(toss);
	team1.yourSummary();                                           //displaying match Summary.
	team2.oppSummary();
	cout << "				THE END!" << endl;
	return 0;
}