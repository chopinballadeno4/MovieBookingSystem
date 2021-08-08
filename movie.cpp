#define ll long long
#include "movie.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

movie::movie() {
	this->name = "";
	this->time = "";
	this->seat = "";
}

movie::movie(string name, string time, string seat) {
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

string movie::gettime() {
	return time;
}

void movie::settime(string time) {
	this->time = time;
}

string movie::getseat() {
	return seat;
}

void movie::setseat(string seat) {
	this->seat = seat;
}

