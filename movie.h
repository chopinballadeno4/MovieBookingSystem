#pragma once
#define ll long long
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class movie {
	string name;
	vector<string> time;
	vector<string> seat;

public:
	movie();
	movie(string name, vector<string> time, vector<string> seat);
	~movie();

	string getname();
	void setname(string name);

	vector<string> gettime();
	void settime(vector<string> time);

	vector<string> getseat();
	void setseat(vector<string> seat);
};