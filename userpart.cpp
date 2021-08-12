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

    void makeuserlist() { // user txt���� ã�Ƽ� list�� �����
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
                //userlist.push_back(user(name, phonenum, email, id, pw)); �̷��� �� �ȵǴ���
                user tempuser(name, phonenum, email, id, pw);
                userlist.push_back(tempuser);
            }
            openFile.close();
        }
    }

    void makeId() { // ȸ������
        string name;
        string phonenum;
        string email;
        string id;
        int pw;

        cout << "====== ȸ�� ���� ======" << '\n';
        cout << "1. �̸�: "; cin >> name;
        cout << "2. ��ȭ��ȣ: "; cin >> phonenum;
        cout << "3. email: "; cin >> email;
        cout << "4. id: "; cin >> id;
        cout << "5. pw: "; cin >> pw;

        for (int i = 0; i < userlist.size(); i++) {
            if (userlist.at(i).getphonenum().compare(phonenum) == 0) {
                blank();
                cout << "!!!�̹� ���Ե� ����� �Դϴ�.";
                return;
            }
            if (userlist.at(i).getid().compare(id) == 0) {
                blank();
                cout << "!!!�̹� �����ϴ� ID�Դϴ�.";
                return;
            }
        }

        string filePath = filepath;
        ofstream writeFile(filePath.data(), ios::app);
        if (writeFile.is_open()) {
            writeFile << name + " " + phonenum + " " + email + " " + id + " " + to_string(pw) << '\n';
            blank();
            cout << "ȸ������ �Ϸ�...!";
        }
        writeFile.close();
    }

    void findId() { // ID/PW ã��
        int selectnum;
        cout << "====== ID/PW ã�� ======" << '\n';
        cout << "1.ID  2.PW  3.�ǵ��ư���" << '\n';
        cout << "\n�޴� ���� : ";
        cin >> selectnum;
        blank();

        if (selectnum == 1) {
            string name;
            string phonenum;
            cout << "** IDã��" << "\n";
            cout << "�̸��� �Է����ּ���: "; cin >> name;
            cout << "��ȭ��ȣ�� �Է����ּ���: "; cin >> phonenum;
            cout << '\n';
            for (int i = 0; i < userlist.size(); i++) {
                if (userlist.at(i).getname().compare(name) == 0 && userlist.at(i).getphonenum().compare(phonenum) == 0) {
                    cout << "\nID: " + userlist.at(i).getid();
                    Sleep(3000);
                    return;
                }
            }
            cout << "\n!!!��ϵ� ������ �ƴմϴ�.";
            sc();
            findId();
        }
        else if (selectnum == 2) {
            string ID;
            string email;
            cout << "** PWã��" << "\n";
            cout << "ID�� �Է����ּ���: "; cin >> ID;
            cout << "email�� �Է����ּ���: "; cin >> email;
            cout << '\n';
            for (int i = 0; i < userlist.size(); i++) {
                if (userlist.at(i).getid().compare(ID) == 0 && userlist.at(i).getemail().compare(email) == 0) {
                    cout << "\nPW: " + to_string(userlist.at(i).getpw());
                    Sleep(3000);
                    return;
                }
            }
            cout << "\n!!!��ϵ� ������ �ƴմϴ�.";
            sc();
            findId();
        }
        else if (selectnum == 3) {

            return;
        }
        else {
            cout << "!!!�߸��� ��ȣ �Դϴ�.";
            sc();
            findId();
        }
    }

    user& inputId(string id, int pw) { // user ã�Ƽ� return ���ֱ�
        for (int i = 0; i < userlist.size(); i++) {
            user& a1 = userlist.at(i);
            if (a1.getid().compare(id) == 0 && a1.getpw() == pw) {
                return a1;
            }
        }
        throw pw;
    }

    user& login() { // �α��� ����ȭ�� 
        int selectnum;
        cout << "===============================================" << '\n';
        cout << "=              ...�۸۱���...                 =" << '\n';
        cout << "=                                             =" << '\n';
        cout << "=   1. �α���   2. ID/PW ã��   3. ȸ������   =" << '\n';
        cout << "===============================================" << '\n';
        cout << "�޴� ����: ";
        cin >> selectnum;
        blank();

        if (selectnum == 1) { // �α��� ���ý�
            string id;
            int pw = 0;
            cout << "ID: "; cin >> id;
            cout << "PW: "; cin >> pw; cout << '\n';
            try {
                user& who = inputId(id, pw);
                cout << "�α��μ���";
                return who; // ���⿡���� return �ص� ��?
            }
            catch (int exception) {
                cout << "\n";
                cout << "!!!IDȤ�� PW�� �߸� �Ǿ����ϴ�.";
                sc();
                login();
            }
        }
        else if (selectnum == 2) { // ID/PW ã�� ���ý�
            system("cls");
            findId();
            system("cls");
            login();
        }
        else if (selectnum == 3) { // ȸ������ ���ý�
            system("cls");
            makeId();
            sc();
            login();
        }
        else { // ������ ��ȣ ���ý�
            cout << "\n!!!��ȣ�� �ٽ� �Է� ���ּ���.";
            sc();
            login();
        }
    }
}