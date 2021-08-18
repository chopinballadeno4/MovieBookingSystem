#define filepath "C:\\Users\\dnrtj\\Desktop\\project\\MovieBookingDB\\movie.txt"
#define LL long long
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>
#include "movie.h"
#include "moviepart.h"
#include "user.h"
#include "userpart.h"


using namespace std;

vector<movie> movielist;

namespace Movie {
	const void sc() {
		Sleep(3000);
		system("cls");
	}

	const void blank() {
		cout << '\n';
		cout << '\n';
		cout << '\n';
	}

	void separate(string name, string time , string seat) {
		string temp;
		
		stringstream st(time);
		vector<string> vt;
		
		stringstream ss(seat);
		vector<string> vs;

		while(getline(st, temp, '/')) {
			vt.push_back(temp);
		}

		while(getline(ss, temp, '/')) {
			vs.push_back(temp);
		}

		movie tempmovie(name, vt, vs);
		movielist.push_back(tempmovie);
	}

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
				separate(moviename, time, seat);
			}
			openFile.close();
		}
	}

	void reserve(user& who) {
		
	}

	void moviechart() {
		cout << "======== 영화 목록 ========" << '\n';
		
		for (int i = 0; i < movielist.size(); i++) {
			string moviename = movielist.at(i).getname();
			string time = ;
			string seat = ;
			cout << "영화 제목: " + moviename << '\n';
			cout << "상영 시간표: " + time

		}
	}
	
	void Editpersonalinformation() {
		
	}
}




