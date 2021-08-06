#define ll long long
#include "movie.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

movie::movie() {
	this->name = "";
	this->time = "";
	this->seat = 0;
}

movie::movie(string name, string time, ll seat) {
	this->name = name;
	this->time = time;
	this->seat = seat;
}

string movie::getname() {
	return name;
}

void movie::setname(string name) {
	this->name = name;
}

string movie::gettime() {
	return time;
}

void movie::settime(string time) {
	this->time = time;
}

ll movie::getseat() {
	return seat;
}

void movie::setseat(ll seat) {
	this->seat = seat;
}

