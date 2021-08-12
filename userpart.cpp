#define _CRT_SECURE_NO_WARNINGS
#define filepath "C:\\Users\\dnrtj\\Desktop\\project\\MovieBookingDB\\user.txt"
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "user.h"
#include "userpart.h"
#include "movie.h"
#include "moviepart.h"

using namespace std;

vector<user> userlist;

namespace User {
    const void sc() {
        Sleep(3000);
        system("cls");
    }

    const void blank() {
        cout << '\n';
        cout << '\n';
        cout << '\n';
    }

    void makeuserlist() { // user txt파일 찾아서 list로 만들기
        string filePath = filepath;
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
                //userlist.push_back(user(name, phonenum, email, id, pw)); 이렇게 왜 안되는지
                user tempuser(name, phonenum, email, id, pw);
                userlist.push_back(tempuser);
            }
            openFile.close();
        }
    }

    void makeId() { // 회원가입
        string name;
        string phonenum;
        string email;
        string id;
        int pw;

        cout << "====== 회원 가입 ======" << '\n';
        cout << "1. 이름: "; cin >> name;
        cout << "2. 전화번호: "; cin >> phonenum;
        cout << "3. email: "; cin >> email;
        cout << "4. id: "; cin >> id;
        cout << "5. pw: "; cin >> pw;

        for (int i = 0; i < userlist.size(); i++) {
            if (userlist.at(i).getphonenum().compare(phonenum) == 0) {
                blank();
                cout << "!!!이미 가입된 사용자 입니다.";
                return;
            }
            if (userlist.at(i).getid().compare(id) == 0) {
                blank();
                cout << "!!!이미 존재하는 ID입니다.";
                return;
            }
        }

        string filePath = filepath;
        ofstream writeFile(filePath.data(), ios::app);
        if (writeFile.is_open()) {
            writeFile << name + " " + phonenum + " " + email + " " + id + " " + to_string(pw) << '\n';
            blank();
            cout << "회원가입 완료...!";
        }
        writeFile.close();
    }

    void findId() { // ID/PW 찾기
        int selectnum;
        cout << "====== ID/PW 찾기 ======" << '\n';
        cout << "1.ID  2.PW  3.되돌아가기" << '\n';
        cout << "\n메뉴 선택 : ";
        cin >> selectnum;
        blank();

        if (selectnum == 1) {
            string name;
            string phonenum;
            cout << "** ID찾기" << "\n";
            cout << "이름을 입력해주세요: "; cin >> name;
            cout << "전화번호를 입력해주세요: "; cin >> phonenum;
            cout << '\n';
            for (int i = 0; i < userlist.size(); i++) {
                if (userlist.at(i).getname().compare(name) == 0 && userlist.at(i).getphonenum().compare(phonenum) == 0) {
                    cout << "\nID: " + userlist.at(i).getid();
                    Sleep(3000);
                    return;
                }
            }
            cout << "\n!!!등록된 계정이 아닙니다.";
            sc();
            findId();
        }
        else if (selectnum == 2) {
            string ID;
            string email;
            cout << "** PW찾기" << "\n";
            cout << "ID를 입력해주세요: "; cin >> ID;
            cout << "email를 입력해주세요: "; cin >> email;
            cout << '\n';
            for (int i = 0; i < userlist.size(); i++) {
                if (userlist.at(i).getid().compare(ID) == 0 && userlist.at(i).getemail().compare(email) == 0) {
                    cout << "\nPW: " + to_string(userlist.at(i).getpw());
                    Sleep(3000);
                    return;
                }
            }
            cout << "\n!!!등록된 계정이 아닙니다.";
            sc();
            findId();
        }
        else if (selectnum == 3) {

            return;
        }
        else {
            cout << "!!!잘못된 번호 입니다.";
            sc();
            findId();
        }
    }

    user& inputId(string id, int pw) { // user 찾아서 return 해주기
        for (int i = 0; i < userlist.size(); i++) {
            user& a1 = userlist.at(i);
            if (a1.getid().compare(id) == 0 && a1.getpw() == pw) {
                return a1;
            }
        }
        throw pw;
    }

    user& login() { // 로그인 메인화면 
        int selectnum;
        cout << "===============================================" << '\n';
        cout << "=              ...멍멍극장...                 =" << '\n';
        cout << "=                                             =" << '\n';
        cout << "=   1. 로그인   2. ID/PW 찾기   3. 회원가입   =" << '\n';
        cout << "===============================================" << '\n';
        cout << "메뉴 선택: ";
        cin >> selectnum;
        blank();

        if (selectnum == 1) { // 로그인 선택시
            string id;
            int pw = 0;
            cout << "ID: "; cin >> id;
            cout << "PW: "; cin >> pw; cout << '\n';
            try {
                user& who = inputId(id, pw);
                cout << "로그인성공";
                return who; // 여기에서만 return 해도 됌?
            }
            catch (int exception) {
                cout << "\n";
                cout << "!!!ID혹은 PW가 잘못 되었습니다.";
                sc();
                login();
            }
        }
        else if (selectnum == 2) { // ID/PW 찾기 선택시
            system("cls");
            findId();
            system("cls");
            login();
        }
        else if (selectnum == 3) { // 회원가입 선택시
            system("cls");
            makeId();
            sc();
            login();
        }
        else { // 엉뚱한 번호 선택시
            cout << "\n!!!번호를 다시 입력 해주세요.";
            sc();
            login();
        }
    }
}