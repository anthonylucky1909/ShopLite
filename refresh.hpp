#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <string>
using namespace std;

class refresh
{
private:
    struct info_person
    {
        char id[100];
        char name[100];
        char password[100];
        char telephone[100];
        char address[100];
        char money[100];
        char status[100];
    } ;
    struct object
    {
        char id_name[100];
        char id_good[100];
        char name_object[100];
        char price[100];
        char time[100];
        char discription[100];
        char status[100];
        int year;
        int month;
        int day;
        int jam;
        int minutes;
        char capacity[100];
    } * head;
    struct orders
    {
        char id_order[100];
        char id_good[100];
        char price[100];
        char time[100];
        char id_seller[100];
        char id_buyer[100];
        char capacity[100];
        char status[100];
        orders *next;
    } array[100];
    int index;
    bool checking_time(char *);
    void make_order();
    void change_customer(int , int);
    void input_customer();
    void change_goods();
    void input_gooods();
    void input_ordering();
    void change_ordering();
    void input_to_order(int);
    void refresh_goods_input();
public:
    void refresh_all();
    void refresh_goods();
};
