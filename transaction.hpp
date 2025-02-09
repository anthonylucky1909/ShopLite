#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <string>
using namespace std;
class buying
{
private:
    char id[100];
    struct things
    {
        char id_name[100];
        char id_good[100];
        char name_object[100];
        char price[100];
        char timing[100];
        char discription[100];
        char status[100];
        char capacity[100];
    } * head;
    struct orders
    {
        char id_order[100];
        char id_good[100];
        char price[100];
        char timing[100];
        char id_seller[100];
        char id_buyer[100];
        char capacity[100];
        char status[100];
    } * temp;
    struct info_person
    {
        char id[100];
        char name[100];
        char password[100];
        char telephone[100];
        char address[100];
        char money[100];
    } * tmp;

public:
    buying()
    {
        head = NULL;
        temp = NULL;
        tmp = NULL;
    };
    void output_things(char *name);
    void searching_things(char *name);
    bool search(char *, char *);
    void output_order(char *);
    void information();

    void make_order(char *);
    void put_zero(int sum1, char *sum);
    void put_char(int sum1, char *sum);
    void make_id(int);
    bool check_object(char *, char *, char *, char *);
    void change(char *, char *, int, int, char *, int,char *);
    void change_things(char *);
    void input_object();
    void input_person();
    void output_(char *, char *, double, double, int, int, int, char *, char *);
    bool checking_time();
};
