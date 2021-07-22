//#define endl '\n' 왜 오류가 나오는지 잘 모르겠음
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>
using namespace std;

void makeId() {

}

void findId() {

}

boolean inputId(string id, int pw) {
    return false;
}

void login() {
    int selectnum;
    string id;
    int pw=0;
    cout << "===============================================" << '\n';
    cout << "=   1. 로그인   2. ID/PW 찾기   3. 회원가입   =" << '\n';
    cout << "===============================================" << '\n';
    cout << "번호 입력: ";
    cin >> selectnum;
    cout << 'k';

    if (selectnum == 1) {
        cout << '\n';
        cout << '\n';
        cout << '\n';
        if (inputId(id,pw)) { // 로그인 성공
            // ~~ 로그인시 이동할 다음페이지
        }
        else {
            // sleep을 통해 endl 랑 \n 차이 비교
            cout << "\n!! 아이디와 비밀번호를 다시 입력 해주세요.";
            Sleep(3000); // 3초후 로그인페이지 호출
            system("cls");
            login();
        }
        
    }
    else if (selectnum == 2) {
        system("cls");
        findId();
        system("cls");
        login();
    }
    else if (selectnum == 3) {
        system("cls");
        makeId();
        system("cls");
        login();
    }
    else {
        cout << "\n!! 번호를 다시 입력 해주세요.";
        Sleep(3000); // 3초후 로그인페이지 호출
        system("cls");
        login();
    }

    return;
}

int main()
{
    login();
    return 0;
}

