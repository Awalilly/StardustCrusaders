#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED


#include <stdio.h>
#include <string>
#include <iostream>
#include <string>
#include "Game.h"

using namespace std;


class account{
public:

    account();

    account(string uname);  //lo uname interpellato è quello del giocatore già loggato

    void encrypt(string f_name, string uname);
    void decrypt(string f_name, string uname);

    void signup();

    void login();

    void manage_account();  //ancora da fare

    void insert_password(string f_name);
    void recover_password(string f_name);
    void change_password(string f_name);

    void change_question(string f_name);
    void change_answer(string f_name);

    void changeUsername();

    void setOtherPlayer(string uname);

    bool getLogged() const;
    string getUsername() const;

    void writeStats(bool victory, bool against, int n_hit, int n_miss, bool m);
    void getStats();    //ancora da fare

private:

    static int const key = 3197173;

    char c;

    bool logged;

    string other_player;

    string username;
    string password;
};


#endif // ACCOUNT_H_INCLUDED
