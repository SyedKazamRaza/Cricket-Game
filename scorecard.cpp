#include "scorecard.h"
#include <iostream>
using namespace std;
const int mxAngle = 6;      //for angle of deviation.
const int mnAngle = -6;
const int maxL = 68;
const int minL = 20;
const int maxW = 8;
const int minW = 1;                    //declaring constant variables used for Random numbers.
const int maxH = 8;
const int minH = 1;
const int maxS = 1;
const int minS = 0;
const int maxRuns = 6;
const int minRuns = 0;
scorecard::scorecard() {
	yourRuns = new int[11];
	oppRuns = new int[11];
	for (int i = 0; i < 11; i++) {
		yourRuns[i] = oppRuns[i] = 0;                  //initializing players runs.
	}
}
void scorecard::scoreInitilizer()
{
	runs = 0;
	isStrike = 0;
	choice = '0';
	balls = 1;
	totalBalls = 0;
	noOfFours = 0;
	noOfSixes = 0;
	noOfWickets = 0;
	enter_length = 0;
	enter_width = 0;
	enter_height = 0;
	Entered_angle_of_deviation = 0;
}

void scorecard::showScorecard1()                        //function for displaying scoreCard.
{
	cout << "		******ScoreCard******" << endl;
	cout << "Total Runs Scored: " << yourTotalScore << endl;
	cout << "Wickets Fallen: " << noOfWickets << endl;
	cout << "No. of SiXES: " << noOfSixes << endl;
	cout << "No. of FOURS: " << noOfFours << endl;
}
void scorecard::setOvers()
{
	cout << "Enter the number of overs(max 50): ";
	cin >> overs;
	while (overs <= 0 || overs > 50)
	{
		cout << "Invalid! Re-enter overs: ";
		cin >> overs;
	}
}
void scorecard::showScorecard2()
{
	cout << "			*****ScoreCard*****" << endl;
	cout << "Total Runs Scored: " << oppTotalScore << endl;
	cout << "Wickets Fallen: " << noOfWickets << endl;
	cout << "No. of SiXES: " << noOfSixes << endl;
	cout << "No. of FOURS: " << noOfFours << endl;
}
void scorecard::batting()
{
	yourTotalScore = 0;
	scoreInitilizer();
	cout << "Total Overs: " << overs << endl;
	totalBalls = overs * 6;
	unsigned seed = time(0);               //for random numbers.
	srand(seed);
	int ov = 0, b = 0, ch = 0, p = 0, x = 0;
	do
	{
		cout << "Press Y to play the ball and A for autoplay the Innings: ";
		cin >> choice;
		while (choice != 'A' && choice != 'a' && choice != 'Y' && choice != 'y')
		{
			cout << "Invalid character! Press Y to play the ball and A for autoplay Innings: ";
			cin >> choice;
		}
		if (choice == 'Y' || choice == 'y')                   //if user want to play a ball.
		{
			cout << "Press 1 for strike and 0 for defensive: ";
			cin >> isStrike;
			enter_length = (rand() % (maxL - minL + 1) + minL);
			enter_width = (rand() % (maxW - minW + 1) + minW);
			enter_height = (rand() % (maxH - minH + 1) + minH);
			Entered_angle_of_deviation = (rand() % (mxAngle - (mnAngle)+1) + mnAngle);
			cout << "				Next ball:		";
			if (enter_length > lengthOfPitch)                               //if ball bounce after the stumps it is considered as No Ball.
			{
				yourTotalScore++;
				cout << "No ball    ";
				ch = 1;
				if (isStrike)
				{
					runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
					while (runs != 4 && runs != 6)
					{
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
					}
					if (runs == 4) {
						noOfFours++;
						cout << "FOUR" << endl;
					}
					else {
						noOfSixes++;
						cout << "SIX" << endl;
					}
				}
				else
				{
					runs = 0;
					cout << runs << endl;
				}
				balls--;
				yourRuns[x] = yourRuns[x] + runs;
				yourTotalScore = yourTotalScore + runs;
			}
			else if (enter_width > 7)
			{
				yourTotalScore++;
				cout << "Wide     ";
				ch = 1;
				if (isStrike) {
					runs = 4;
					noOfFours++;
					cout << "FOUR" << endl;
				}
				else {
					runs = 0;
					cout << runs << endl;
				}
				balls--;
				yourTotalScore = yourTotalScore + runs;
			}
			else if (enter_height > const_heigth)
			{
				cout << "A dangerous Bouncer!   ";
				if (isStrike)
				{
					runs = 6;
					cout << "SIX" << endl;
					noOfSixes++;
				}
				else {
					runs = 0;
					cout << runs << endl;
				}
				yourRuns[x] = yourRuns[x] + runs;
				yourTotalScore = yourTotalScore + runs;
			}
			else if (Entered_angle_of_deviation > 5 || Entered_angle_of_deviation < -5)           //condition if user wants to 
			{																							//spin the ball or not.
				cout << "A Sharp Spin!   ";
				if (isStrike)
				{
					runs = (rand() % (maxRuns - minRuns + 1) - minRuns);
					if (runs == 5)
					{
						cout << "That's a Wicket." << endl;
						noOfWickets++;
						x++;
						if (noOfWickets != 10)
						{
							cout << "Next batsman comes to crease:" << endl;
						}
					}
					else if (runs == 4) {
						noOfFours++;
						cout << "FOUR" << endl;
					}
					else if (runs == 6) {
						noOfSixes++;
						cout << "SIX" << endl;
					}
					else {
						cout << runs << endl;
					}
					if (runs != 5) {
						yourTotalScore = yourTotalScore + runs;
						yourRuns[x] = yourRuns[x] + runs;
					}
				}
				else {
					runs = 0;
					yourTotalScore = yourTotalScore + runs;
					cout << runs << endl;
					yourTotalScore = yourTotalScore + runs;
				}
			}
			else
			{
				cout << "Normal ball     ";
				runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
				if (runs == 5)
				{
					cout << "That's a Wicket." << endl;
					noOfWickets++;
					x++;
					if (noOfWickets != 10)
					{
						cout << "Next batsman comes to crease:" << endl;
					}
				}
				else if (runs == 4) {
					noOfFours++;
					cout << "FOUR" << endl;
				}
				else if (runs == 6) {
					noOfSixes++;
					cout << "SIX" << endl;
				}
				else
				{
					cout << runs << endl;
				}
				if (runs != 5) {
					yourRuns[x] = yourRuns[x] + runs;
					yourTotalScore = yourTotalScore + runs;
				}
			}
			cout << "Over " << ov << "." << b + 1 << ":" << endl;
			balls++;

			if (ch != 1)
			{
				b++;
			}
			if (balls != totalBalls && p == 1 && ch != 1)
			{
				cout << "				Over completed." << endl;
				cout << "Score: " << yourTotalScore << " / " << noOfWickets << endl;
			}
			p = 0;
			if (b == 5)
			{
				ov++;
				b = -1;
				p = 1;
			}
			ch = 0;
			cout << endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
		}
		else                                       //if user want to autoplay the innings.
		{
			int c = b;
			int tempOV = ov;
			for (int i = balls; balls <= totalBalls && noOfWickets < 10; i++)
			{
				isStrike = (rand() % (maxS - minS + 1) - minS);
				cout << "			Next ball:					";
				enter_length = (rand() % (maxL - minL + 1) + minL);
				enter_width = (rand() % (maxW - minW + 1) + minW);
				enter_height = (rand() % (maxH - minH + 1) + minH);
				Entered_angle_of_deviation = (rand() % (mxAngle - (mnAngle)+1) + mnAngle);

				if (enter_length > lengthOfPitch)
				{
					yourTotalScore++;
					cout << "No ball    ";
					ch = 1;
					if (isStrike)
					{
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						while (runs != 4 && runs != 6)
						{
							runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						}
						if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else {
							noOfSixes++;
							cout << "SIX" << endl;
						}
					}
					else
					{
						runs = 0;
						cout << runs << endl;
					}
					balls--;
					yourRuns[x] = yourRuns[x] + runs;
					yourTotalScore = yourTotalScore + runs;
				}
				else if (enter_width > 7)
				{
					yourTotalScore++;
					ch = 1;
					cout << "Wide     ";
					if (isStrike) {
						runs = 4;
						noOfFours++;
						cout << "FOUR" << endl;
					}
					else {
						runs = 0;
						cout << runs << endl;
					}
					balls--;
					yourTotalScore = yourTotalScore + runs;
				}
				else if (enter_height > const_heigth)
				{
					cout << "A dangerous Bouncer!   ";
					if (isStrike)
					{
						runs = 6;
						cout << "SIX" << endl;
						noOfSixes++;
					}
					else {
						runs = 0;
						cout << runs << endl;
					}
					yourTotalScore = yourTotalScore + runs;
					yourRuns[x] = yourRuns[x] + runs;
				}
				else if (Entered_angle_of_deviation > 5 || Entered_angle_of_deviation < -5)
				{
					cout << "A Sharp Spin!   ";
					if (isStrike)
					{
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						if (runs == 5)
						{
							cout << "That's a Wicket." << endl;
							noOfWickets++;
							x++;
							if (noOfWickets != 10)
							{
								cout << "Next batsman comes to crease:" << endl;
							}
						}
						else if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else if (runs == 6) {
							noOfSixes++;
							cout << "SIX" << endl;
						}
						else {
							cout << runs << endl;
						}
						if (runs != 5) {
							yourTotalScore = yourTotalScore + runs;
							yourRuns[x] = yourRuns[x] + runs;
						}
					}
					else {
						runs = 0;
						cout << runs << endl;
					}
				}
				else
				{
					cout << "Normal Ball!    ";
					runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
					if (runs == 5)
					{
						cout << "That's a Wicket." << endl;
						noOfWickets++;
						x++;
						if (noOfWickets != 10)
						{
							cout << "Next batsman comes to crease:" << endl;
						}
					}
					else if (runs == 4) {
						noOfFours++;
						cout << "FOUR" << endl;
					}
					else if (runs == 6) {
						noOfSixes++;
						cout << "SIX" << endl;
					}
					else {
						cout << runs << endl;
					}
					if (runs != 5) {
						yourTotalScore = yourTotalScore + runs;
						yourRuns[x] = yourRuns[x] + runs;
					}
				}
				cout << "Over " << tempOV << "." << c + 1 << ":" << endl;
				balls++;
				if (ch != 1)
				{
					c++;
				}
				if (balls != totalBalls && p == 1 && ch != 1)
				{
					cout << "				>>> Over completed. <<<" << endl;
					cout << "Score: " << yourTotalScore << " / " << noOfWickets << endl;
				}
				p = 0;
				if (c == 5)
				{
					tempOV++;
					c = -1;
					p = 1;
				}
				ch = 0;
				cout << "-------------------------------------------------------------------------------------------" << endl;
				if (t == 1 && yourTotalScore > target)
				{
					break;
				}
			}
			if (t == 1 && yourTotalScore > target)
			{
				break;
			}
		}
	} while ((choice == 'Y' || choice == 'y') && (balls <= totalBalls) && noOfWickets < 10);
}

void scorecard::bowling()                                   
{
	oppTotalScore = 0;
	scoreInitilizer();
	cout << endl << endl << "Enter inputs by following these lengths:" << endl;          //guiding the user for entering valid input.
	cout << "Length of pitch: " << lengthOfPitch << " feets" << endl;
	cout << "Heigth of batsman: " << const_heigth << " feets" << endl;
	cout << "Width of pitch: " << widthOfPitch << " feets" << endl;
	cout << "Angle of deviation more than 5 and less than -5 is considered as SPIN" << endl << endl;
	cout << "Put distance:" << endl;
	cout << "				->b/w 50 and 66 to bounce on front half of pitch." << endl;
	cout << "				->b/w 35 and 49 for spinning the ball." << endl;
	cout << "				->b/w 20 and 34 for bouncer." << endl;
	totalBalls = overs * 6;
	unsigned seed = time(0);
	srand(seed);

	int ov = 0, b = 0, ch = 0, p = 0, y = 0;
	do {
		cout << "Press B to bowl the next ball and A for autoplay the Innings:";
		cin >> choice;
		while (choice != 'A' && choice != 'a' && choice != 'b' && choice != 'B')
		{
			cout << "Invalid character! Press B to play the ball and A for autoplay the Innings: ";
			cin >> choice;
		}
		if (choice == 'b' || choice == 'B')                 //if user choose to bowl the ball.
		{
			cout << "Enter postion of bounce: " << endl;
			cout << "Enter the distance of bounce from wicket b/w 20 to 66 (distance more than 66 is NO ball): ";   cin >> enter_length;
			while (enter_length < 20)
			{
				cout << "Invalid value! Enter the distance of bounce from wicket b/w 20 to 66 ";   cin >> enter_length;
			}
			isStrike = (rand() % (maxS - minS + 1) + minS);
			if (enter_length > lengthOfPitch)
			{
				cout << "				Next ball:				";
				oppTotalScore++;
				cout << "No ball    ";
				ch = 1;
				if (isStrike) {
					runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
					while (runs != 4 && runs != 6)
					{
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
					}
					if (runs == 4) {
						noOfFours++;
						cout << "FOUR" << endl;
					}
					else {
						noOfSixes++;
						cout << "SIX" << endl;
					}
				}
				else {
					runs = 0;
					cout << runs << endl;
				}
				balls--;
				oppRuns[y] = oppRuns[y] + runs;
				oppTotalScore = oppTotalScore + runs;
			}
			else if (enter_length >= 50 && enter_length <= 66)
			{
				cout << "Enter distance from stumps from 1 to 8 (distance more than 5 is wide):  ";    cin >> enter_width;
				while (enter_width < 1 || enter_width>8)
				{
					cout << "Invalid input!" << endl << "Enter distance from stumps from 1 to 8 (distance more than 5 is wide):  ";
					cin >> enter_width;
				}
				cout << "				Next ball:				";
				if (enter_width > 5) {
					oppTotalScore++;
					cout << "Wide Ball    ";
					ch = 1;
					if (isStrike) {
						runs = 4;
						noOfFours++;
						cout << "FOUR" << endl;
					}
					else {
						runs = 0;
						cout << runs << endl;
					}
					balls--;
					oppTotalScore = oppTotalScore + runs;
				}
				else {
					runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
					if (isStrike)
					{
						if (runs == 5) {
							cout << "That's a Wicket.	";
							y++;
							noOfWickets++;
							int outStatus = (rand() % (3 - 1 + 1) + 1);

							if (outStatus == 1)
								cout << "Bold!" << endl;
							else if (outStatus == 2)
								cout << "LBW" << endl;
							else
								cout << "catch OUT" << endl;
							if (noOfWickets != 10)
							{
								cout << "Next batsman comes to crease:" << endl;
							}
						}
						else if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else if (runs == 6) {
							noOfSixes++;
							cout << "SIX" << endl;
						}
						else {
							cout << runs << endl;
						}
						if (runs != 5) {
							oppRuns[y] = oppRuns[y] + runs;
							oppTotalScore = oppTotalScore + runs;
						}
					}
					else {
						runs = 0;
						cout << runs << endl;
					}
				}
			}
			else if (enter_length >= 35 && enter_length < 50)
			{
				cout << "Enter Angle of swing of ball from -7 to +7: ";    cin >> Entered_angle_of_deviation;
				while (Entered_angle_of_deviation > 7 || Entered_angle_of_deviation < -7)
				{
					cout << "Invalid Input! Enter Angle of swing of ball from -7 to +7: ";    cin >> Entered_angle_of_deviation;
				}
				cout << "				Next ball:				";
				if (Entered_angle_of_deviation > 5 || Entered_angle_of_deviation < -5)
				{
					cout << "Great swing!!";
					if (isStrike) {
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						if (runs == 5) {
							cout << "That's a Wicket.	";
							y++;
							int outStatus = (rand() % (3 - 1 + 1) + 1);
							noOfWickets++;
							if (outStatus == 1)
								cout << "Bold!" << endl;
							else if (outStatus == 2)
								cout << "LBW" << endl;
							else
								cout << "catch OUT" << endl;
							if (noOfWickets != 10)
							{
								cout << "Next batsman comes to crease:" << endl;
							}
						}
						else if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else if (runs == 6) {
							noOfSixes++;
							cout << "SIX" << endl;
						}
						else {
							cout << runs << endl;
						}
					}
					else {
						runs = 0;
						cout << runs << endl;
					}
				}
				else
				{
					runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
					if (isStrike)
					{
						if (runs == 5) {
							cout << "That's a Wicket.	";
							noOfWickets++;
							y++;
							int outStatus = (rand() % (2 - 1 + 1) + 1);
							if (outStatus == 1)
								cout << "Bold!" << endl;
							else
								cout << "catch OUT" << endl;
							if (noOfWickets != 10)
							{
								cout << "Next batsman comes to crease:" << endl;
							}
						}
						else if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else if (runs == 6) {
							noOfSixes++;
							cout << "SIX" << endl;
						}
						else {
							cout << runs << endl;
						}
					}
					else {
						runs = 0;
						cout << runs << endl;
					}
				}
				if (runs != 5) {
					oppRuns[y] = oppRuns[y] + runs;
					oppTotalScore = oppTotalScore + runs;
				}
			}
			else
			{
				cout << "Enter height of bounce from 1 to 8 (more than 6 is bouncer): ";     cin >> enter_height;
				while (enter_height < 1 || enter_height>8)
				{
					cout << "Invalid input! Enter height of bounce from 1 to 8 "; cin >> enter_height;
				}
				cout << "			Next ball:			";
				if (enter_height > const_heigth&& enter_height <= 8) {
					cout << " A Dangerous bouncer!		";
					if (isStrike)
					{
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						if (runs == 5) {
							cout << "That's a Wicket.		CatchOut" << endl;
							y++;
							noOfWickets++;
							y++;
							if (noOfWickets != 10)
							{
								cout << "Next batsman comes to crease:" << endl;
							}
						}
						else if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else if (runs == 6) {
							noOfSixes++;
							cout << "SIX" << endl;
						}
						else {
							cout << runs << endl;
						}
					}
					else
					{
						runs = 0;
						cout << runs << endl;
					}
				}
				else
				{
					if (isStrike)
					{
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						if (runs == 5) {
							cout << "That's a Wicket.	";
							y++;
							noOfWickets++;
							int outStatus = (rand() % (3 - 1 + 1) + 1);

							if (outStatus == 1)
								cout << "Bold!" << endl;
							else if (outStatus == 2)
								cout << "LBW" << endl;
							else
								cout << "catch OUT" << endl;
							if (noOfWickets != 10)
							{
								cout << "Next batsman comes to crease:" << endl;
							}
						}
						else if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else if (runs == 6) {
							noOfSixes++;
							cout << "SIX" << endl;
						}
						else {
							cout << runs << endl;
						}
					}
					else {
						runs = 0;
						cout << runs << endl;
					}
				}
				if (runs != 5) {
					oppRuns[y] = oppRuns[y] + runs;
					oppTotalScore = oppTotalScore + runs;
				}
			}
			cout << "Over " << ov << "." << b + 1 << ":" << endl;
			balls++;
			oppTotalScore = oppTotalScore + runs;
			if (ch != 1)
			{
				b++;
			}
			if (balls != totalBalls && p == 1 && ch != 1)
			{
				cout << "				Over completed." << endl;
				cout << "Score: " << oppTotalScore << " / " << noOfWickets << endl;
			}
			p = 0;
			if (b == 5)
			{
				ov++;
				b = -1;
				p = 1;
			}
			ch = 0;
			cout << endl;
			cout << "---------------------------------------------------------------------------------------------" << endl;
		}

		else {                                      //if user choose to autoplay the innings.
			for (int i = balls; balls <= totalBalls && noOfWickets < 10; i++)
			{
				isStrike = (rand() % (maxS - minS + 1) + minS);
				enter_length = (rand() % (maxL - minL + 1) + minL);
				enter_width = (rand() % (maxW - minW + 1) + minW);
				enter_height = (rand() % (maxH - minH + 1) + minH);
				Entered_angle_of_deviation = (rand() % (mxAngle - (mnAngle)+1) + mnAngle);
				cout << "			Next ball:			";
				if (enter_length > lengthOfPitch)
				{
					oppTotalScore++;
					cout << "No ball		";
					ch = 1;
					if (isStrike) {
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						while (runs != 4 && runs != 6)
						{
							runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						}
						if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else {
							noOfSixes++;
							cout << "SIX" << endl;
						}
					}
					else {
						runs = 0;
						cout << runs << endl;
					}
					balls--;
					oppRuns[y] = oppRuns[y] + runs;
					oppTotalScore = oppTotalScore + runs;
				}
				else if (enter_length >= 50 && enter_length <= 66)
				{
					if (enter_width > 5) {
						oppTotalScore++;
						cout << "Wide     ";
						ch = 1;
						if (isStrike) {
							runs = 4;
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else {
							runs = 0;
							cout << runs << endl;
						}
						balls--;
						oppTotalScore = oppTotalScore + runs;
					}
					else {
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						if (runs == 5) {
							cout << "That's a Wicket.	";
							noOfWickets++;
							y++;
							int outStatus = (rand() % (3 - 1 + 1) + 1);

							if (outStatus == 1)
								cout << "Bold!" << endl;
							else if (outStatus == 2)
								cout << "LBW" << endl;
							else
								cout << "catch OUT" << endl;
							if (noOfWickets != 10)
							{
								cout << "Next batsman comes to crease:" << endl;
							}
						}
						else if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else if (runs == 6) {
							noOfSixes++;
							cout << "SIX" << endl;
						}
						else {
							cout << runs << endl;
						}
						if (runs != 5) {
							oppRuns[y] = oppRuns[y] + runs;
							oppTotalScore = oppTotalScore + runs;
						}
					}
				}
				else if (enter_length >= 35 && enter_length < 50)
				{
					if (Entered_angle_of_deviation > 5 || Entered_angle_of_deviation < -5)
					{
						cout << "Swing    ";
						if (isStrike) {
							runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
							if (runs == 5) {
								cout << "That's a Wicket.	";
								y++;
								int outStatus = (rand() % (3 - 1 + 1) + 1);
								noOfWickets++;
								if (outStatus == 1)
									cout << "Bold!" << endl;
								else if (outStatus == 2)
									cout << "LBW" << endl;
								else
									cout << "catch OUT" << endl;
								if (noOfWickets != 10)
								{
									cout << "Next batsman comes to crease:" << endl;
								}
							}
							else if (runs == 4) {
								noOfFours++;
								cout << "FOUR" << endl;
							}
							else if (runs == 6) {
								noOfSixes++;
								cout << "SIX" << endl;
							}
							else {
								cout << runs << endl;
							}
						}
						else {
							runs = 0;
							cout << runs << endl;
						}
					}
					else
					{
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						if (runs == 5) {
							cout << "That's a Wicket.	";
							noOfWickets++;
							y++;
							int outStatus = (rand() % (3 - 1 + 1) + 1);
							if (outStatus == 1)
								cout << "Bold!" << endl;
							else if (outStatus == 2)
								cout << "LBW" << endl;
							else
								cout << "catch OUT" << endl;
							if (noOfWickets != 10)
							{
								cout << "Next batsman comes to crease:" << endl;
							}
						}
						else if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else if (runs == 6) {
							noOfSixes++;
							cout << "SIX" << endl;
						}
						else {
							cout << runs << endl;
						}
					}
					if (runs != 5) {
						oppRuns[y] = oppRuns[y] + runs;
						oppTotalScore = oppTotalScore + runs;
					}
				}

				else
				{
					if (enter_height > const_heigth&& enter_height <= 8) {
						cout << "A dangerous bouncer.	";
						if (isStrike)
						{
							runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
							if (runs == 5) {
								cout << "That's a Wicket.		CatchOut" << endl;
								y++;
								noOfWickets++;
								if (noOfWickets != 10)
								{
									cout << "Next batsman comes to crease:" << endl;
								}
							}
							else if (runs == 4) {
								noOfFours++;
								cout << "FOUR" << endl;
							}
							else if (runs == 6) {
								noOfSixes++;
								cout << "SIX" << endl;
							}
							else {
								cout << runs << endl;
							}
						}
						else
						{
							runs = 0;
							cout << runs << endl;
						}
					}
					else
					{
						runs = (rand() % (maxRuns - minRuns + 1) + minRuns);
						if (runs == 5) {
							cout << "That's a Wicket.	";
							noOfWickets++;
							y++;
							int outStatus = (rand() % (3 - 1 + 1) + 1);

							if (outStatus == 1)
								cout << "Bold!" << endl;
							else if (outStatus == 2)
								cout << "LBW" << endl;
							else
								cout << "catch OUT" << endl;
							if (noOfWickets != 10)
							{
								cout << "Next batsman comes to crease:" << endl;
							}
						}
						else if (runs == 4) {
							noOfFours++;
							cout << "FOUR" << endl;
						}
						else if (runs == 6) {
							noOfSixes++;
							cout << "SIX" << endl;
						}
						else {
							cout << runs << endl;
						}
					}
					if (runs != 5) {
						oppRuns[y] = oppRuns[y] + runs;
						oppTotalScore = oppTotalScore + runs;
					}
				}

				cout << "Over " << ov << "." << b + 1 << ":" << endl;
				balls++;
				if (ch != 1)
				{
					b++;
				}
				if (balls != totalBalls && p == 1 && ch != 1)
				{
					cout << "				Over completed." << endl;
					cout << "Score: " << oppTotalScore << " / " << noOfWickets << endl;
				}
				p = 0;
				if (b == 5)
				{
					ov++;
					b = -1;
					p = 1;
				}
				ch = 0;
				cout << endl;
				cout << "-------------------------------------------------------------------------------------------" << endl;
				if (t == 1 && yourTotalScore > target)
				{
					break;
				}
			}
			if (t == 1 && yourTotalScore > target)
			{
				break;
			}
		}
	} while ((choice == 'B' || choice == 'b') && (balls <= totalBalls) && noOfWickets < 10);
}

void scorecard::DecisionOfGame()                            //this function display which Team win the match.
{
	cout << "*****Match Result:";
	if (yourTotalScore > oppTotalScore)
	{
		cout << endl << "		Congrats! You Won the match." << endl;
	}
	else if (yourTotalScore < oppTotalScore)
	{
		cout << endl << "		You Loss the Match." << endl;
	}
	else
	{
		cout << "			Match Drawn." << endl;
	}
}