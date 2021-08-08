#define filepath "C:\\Users\\dnrtj\\Desktop\\project\\MovieBookingDB\\movie.txt"
#define LL long long
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "movie.h"
#include "moviepart.h"

using namespace std;

vector<movie> movielist;

namespace Movie {
	void makemovielist() {
		string filePath = filepath;
		ifstream openFile(filePath.data());
		if (openFile.is_open()) {
			string line;
			while (getline(openFile, line)) {
				stringstream ss(line);
				string moviename; ss >> moviename;
				string time; ss >> time;
				string seat; ss >> seat;
				movie tempmovie(moviename, time, seat);
				movielist.push_back(tempmovie);
			}
			openFile.close();
		}
	}


}




