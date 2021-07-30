#pragma once
#include <string>
using namespace std;

class user {
private:
    string name;
    string phonenum;
    string email;
    string id;
    int pw;

public:
    user();
    user(string name, string phonenum, string email, string id, int pw);
    ~user();

    void setname(string name);
    string getname();

    void setphonenum(string phonenum);
    string getphonenum();

    void setemail(string email);
    string getemail();

    void setid(string id);
    string getid();

    void setpw(int pw);
    int getpw();
};