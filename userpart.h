#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include "user.h"

using namespace std;

//vector<user> userlist;

namespace User {
	const void sc();
	const void blank();

	void makeuserlist();
	void makeId();
	void findId();
	user& inputId(string id, int pw);
	void login();
}