#pragma once
#define ll long long
#include <iostream>
#include <string>

using namespace std;

class movie {
	string name;
	string time;
	ll seat;

public:
	movie();
	movie(string name, string time, ll seat);
	~movie();

	string getname();
	void setname(string name);

	string gettime();
	void settime(string time);

	ll getseat();
	void setseat(ll seat);
};