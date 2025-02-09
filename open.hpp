#include <stdio.h>
#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include <string>

using namespace std;

class open
{
private:
    struct info
    {
        char str[100];
        char pass[100];
    }head;
    char id[100],name[100], pass[100],telephone[100],address[100], str[100];
    bool system;
    char result_a[100];
public:
    bool sign_admin(char admin_id[100]);
    bool sign_customer(char a[100]);
    bool sign_up();
    void make_id(int);
    
};
