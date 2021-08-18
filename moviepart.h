#pragma once
#include "movie.h"
#include "user.h"
#include "userpart.h"


namespace Movie {
	void makemovielist();
	void separate(string name, string time , string seat);
	void reserve(user& who);
	void moviechart();
	void Editpersonalinformation();
}