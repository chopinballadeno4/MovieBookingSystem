#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "userpart.h"
#include "movie.h"
#include "moviepart.h"
using namespace std;

//-------------------------------------------------------------------------

int main() {
    User::makeuserlist(); 
    User::login(); // 여기서 user 파일 넘겨주기 값변경 가능.. 레퍼런스로
    
    return 0;
}

