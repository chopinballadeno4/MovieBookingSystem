#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "userpart.h"
using namespace std;

//-------------------------------------------------------------------------

int main() {
    makeuserlist(); 
    login(); // 여기서 user 파일 넘겨주기 값변경 가능.. 레퍼런스로
    return 0;
}

