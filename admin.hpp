#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
using namespace std;
class administration
{
public:
    void output_things();
    void searching_things();
    bool search(char *, char *);
    void output_order();
    void output_account();
    void deleting_accout();
    void insert(char *);
    void input();
    void deleting_things();
    void deleting_object();
    void input_object();
    void deleting_things_for_admin(char *);
    void input_object_for_admin();

private:
    void delete_auction_file(char *sums);
    void input_auction_file();
    bool have;
    struct orders
    {
        char id_order[100];
        char id_good[100];
        char price[100];
        char timing[100];
        char id_seller[100];
        char id_buyer[100];
        char capacity[100];
    };
    struct auction
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
    struct people
    {
        char id_person[100];
        char name_person[100];
        char password[100];
        char telephone[100];
        char address[100];
        char price[100];
        char status[100];
    };
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
    };
};
