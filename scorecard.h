#pragma once
#include <cstdlib>
#include <ctime>
const int lengthOfPitch = 66;  //feets
const int widthOfPitch = 8;  //feets
const int const_heigth = 6;

class scorecard
{
private:
	int enter_length;
	int enter_width;
	int enter_height;
	int Entered_angle_of_deviation;
	bool isStrike;
	char choice;
	int overs;
	int balls;
	int totalBalls;
	int runs;
	int noOfFours;
	int noOfSixes;
	int noOfWickets;
protected:
	int yourTotalScore;
	int oppTotalScore;
	int target;                           //Inherited class can access these variables.
	int t;
	int* yourRuns;
	int* oppRuns;
public:
	scorecard();
	void scoreInitilizer();
	void setOvers();
	void batting();                        //functions prototypes.
	void bowling();
	void showScorecard1();
	void showScorecard2();
	void DecisionOfGame();

};
