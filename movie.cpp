#define ll long long
#include "movie.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

movie::movie() {
	this->name = "";
}

movie::movie(string name, vector<string> time, vector<string> seat) {
	this->name = name;
	this->time = time;
	this->seat = seat;
}

movie::~movie() {
}

string movie::getname() {
	return name;
}

void movie::setname(string name) {
	this->name = name;
}

vector<string> movie::gettime() {
	return time;
}

void movie::settime(vector<string> time) {
	this->time = time;
}

vector<string> movie::getseat() {
	return seat;
}

void movie::setseat(vector<string> seat) {
	this->seat = seat;
}

