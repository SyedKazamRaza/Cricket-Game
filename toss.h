#pragma once
#include <iostream>
#include "scoreCard.h"
#include <cstdlib>             //library for srand
#include <ctime>               //library for time(0)
using namespace std;
const int max = 1;
const int min = 0;                  

class Toss :public scorecard             //inheriting Toss class from scorecard class.
{
private:
	char choose;
	char decision;
public:
	Toss();
	void DecisionOfToss();
	int* getYourRuns();
	int* getOppRuns();
};
