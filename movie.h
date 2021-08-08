#pragma once
#define ll long long
#include <iostream>
#include <string>

using namespace std;

class movie {
	string name;
	string time;
	string seat;

public:
	movie();
	movie(string name, string time, string seat);
	~movie();

	string getname();
	void setname(string name);

	string gettime();
	void settime(string time);

	string getseat();
	void setseat(string seat);
};