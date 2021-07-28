//#define endl '\n' 왜 오류가 나오는지 잘 모르겠음
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <stdio.h>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <sstream>

#include "user.h"
using namespace std;

//-------------------------------------------------------------------------

vector<user> userlist;

void makeuserlist() {
    string filePath = "C:\\Users\\dnrtj\\Desktop\\프로젝트\\MovieBookingDB\\user.txt";
    ifstream openFile(filePath.data());
    if (openFile.is_open()) {
        string line;
        while (getline(openFile, line)) {
            stringstream ss(line);
            string name; ss >> name;
            string phonenum; ss >> phonenum;
            string email; ss >> email;
            string id; ss >> id;
            int pw; ss >> pw;
            //userlist.push_back(user(name, phonenum, email, id, pw));
            user tempuser(name, phonenum, email, id, pw);
            userlist.push_back(tempuser);
        }
        openFile.close();
    }
}



//-------------------------------------------------------------------------


void makeId() {
    string name;
    string phonenum;
    string email;
    string id;
    int pw;

    cout << "====== 회원 가입 =====" << "\n"; cout << "\n";
    while(true) {
        cout << "1. 이름 : "; cin >> name; cout << "\n";
        cout << "2. 전화번호 : "; cin >> phonenum; cout << "\n";
        cout << "3. email : "; cin >> email; cout << "\n";
        cout << "4. id : "; cin >> id; cout << "\n";
        cout << "5. pw : "; cin >> pw; cout << "\n";
    }
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

    if (selectnum == 1) { // 로그인 선택시
        cout << '\n';
        cout << '\n';
        cout << '\n';
        if (inputId(id,pw)) { 
            
        }
        else {
            // sleep을 통해 endl 랑 \n 차이 비교
            cout << "\n!! 아이디와 비밀번호를 다시 입력 해주세요.";
            Sleep(3000); 
            system("cls");
            login();
        }
        
    }
    else if (selectnum == 2) { // ID/PW 찾기 선택시
        system("cls");
        findId();
        Sleep(3000);
        system("cls");
        login();
    }
    else if (selectnum == 3) { // 회원가입 선택시
        system("cls");
        makeId();
        Sleep(3000);
        system("cls");
        login();
    }
    else { // 엉뚱한 번호 선택시
        cout << "\n!! 번호를 다시 입력 해주세요.";
        Sleep(3000);
        system("cls");
        login();
    }
    return;
}

//-------------------------------------------------------------------------

int main()
{
    makeuserlist(); // user 클래스 vector로 
    login();
    return 0;
}

