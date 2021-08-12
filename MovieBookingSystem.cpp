#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "userpart.h"
#include "movie.h"
#include "moviepart.h"
using namespace std;

//-------------------------------------------------------------------------

int main() {
    User::makeuserlist(); 
    user& who = User::login();
    Movie::makemovielist();
    Movie::reserve(who);
    return 0;
}

