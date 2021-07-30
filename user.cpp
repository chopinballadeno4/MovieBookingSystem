#include <string>
#include "user.h"
using namespace std;


   user::user() {
       this->name = "";
       this->phonenum = "";
       this->email = "";
       this->id = "";
       this->pw = 0;
   }
   user::user(string name, string phonenum, string email, string id, int pw) {
        //this->name = name;
        this->name = name;
        this->phonenum = phonenum;
        this->email = email;
        this->id = id;
        this->pw = pw;
    }

    user::~user() {}

    void user::setname(string name) {
        this->name = name;
    }
    string user::getname() {
        return name;
    }

    void user::setphonenum(string phonenum) {
        this->phonenum = phonenum;
    }
    string user::getphonenum() {
        return phonenum;
    }

    void user::setemail(string email) {
        this->email = email;
    }
    string user::getemail() {
        return email;
    }

    void user::setid(string id) {
        this->id = id;
    }
    string user::getid() {
        return id;
    }

    void user::setpw(int pw) {
        this->pw = pw;
    }
    int user::getpw() {
        return pw;
    }