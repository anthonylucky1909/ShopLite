#include "information.hpp"
void info::change_info(char *name)
{
    int nums;
    char copy[100] = {};
    cout << "请选择修改的的属性 （1.用户名 2.联系方式 3.地址):";
    cin >> nums;
    cin.ignore();
    if (nums == 1)
    {
    back:
        cout << "请输入修改后的用户名:";
        cin.getline(copy, sizeof(copy));
        bool have = checking(copy);
        if (have == false)
        {
            cout << "再修改名称" << endl;
            goto back;
        }
        else
        {
            insert(copy, nums, name);
            input();
        }
    }
    else if (nums == 2)
    {
        cout << "请输入修改后的联系方式:";
        cin.getline(copy, sizeof(copy));
        insert(copy, nums, name);
        input();
    }
    else
    {
        cout << "请输入修改后的地址:";
        cin.getline(copy, sizeof(copy));
        insert(copy, nums, name);
        input();
    }
}
void info::recharge(char *name, int nums)
{
    if (nums == 4)
    {
        cout << "请输入充值数目:";
    back:
        char copy[100] = {};
        cin >> copy;
        for (int i = 0; copy[i] != '\0'; i++)
        {
            if (copy[i] == '-')
            {
                cout << "请再输入充值数目:";
                goto back;
            }
        }
        cout << "**************************" << endl;
        cout << "充值成功" << endl;
        cout << "当前余额:";
        insert_money(copy, nums, name);
        input();
    }
}
void info::insert(char *copy, int nums, char *name)
{
    FILE *source = fopen("FILE/customer.txt", "r");
    FILE *curr = fopen("FILE/remove.txt", "w");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    info();
    head = new info_person;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id, head->name, head->password, head->telephone, head->address, head->money, head->status) != EOF)
    {
        if (strcmp(head->id, name) == 0)
        {
            if (nums == 1)
            {
                strcpy(head->name, copy);
            }
            else if (nums == 2)
            {
                strcpy(head->telephone, copy);
            }
            else if (nums == 3)
            {
                strcpy(head->address, copy);
            }
        }
        fprintf(curr, "%s,%s,%s,%s,%s,%s,%s\n", head->id, head->name, head->password, head->telephone, head->address, head->money, head->status);
    }
    delete[] head;
    fclose(source);
    fclose(curr);
}
void info::input()
{
    info();
    char str;
    int count = 0, i = 0;
    FILE *source = fopen("FILE/customer.txt", "w");
    FILE *curr = fopen("FILE/remove.txt", "r");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    // info_person *head = NULL;
    head = new info_person;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id, head->name, head->password, head->telephone, head->address, head->money) != EOF)
    {
        fprintf(source, "%s,%s,%s,%s,%s,%s\n", head->id, head->name, head->password, head->telephone, head->address, head->money);
    }
    delete[] head;
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}
void info::insert_money(char *copy, int nums, char *name)
{
    FILE *source = fopen("FILE/customer.txt", "r");
    FILE *curr = fopen("FILE/remove.txt", "w");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    info();
    // info_person *head = NULL;
    head = new info_person;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id, head->name, head->password, head->telephone, head->address, head->money, head->status) != EOF)
    {
        if (strcmp(head->id, name) == 0)
        {
            char *key = head->money;
            double ld = strtod((char *)key, NULL);
            char *key1 = copy;
            double ld1 = strtod((char *)key1, NULL);
            ld = ld + ld1;
            cout << ld << endl;
            fprintf(curr, "%s,%s,%s,%s,%s,%0.1lf,%s\n", head->id, head->name, head->password, head->telephone, head->address, ld, head->status);
        }
        else
        {
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s\n", head->id, head->name, head->password, head->telephone, head->address, head->money, head->status);
        }
    }
    delete[] head;
    fclose(source);
    fclose(curr);
}
void info::output_account(char *name)
{
    FILE *source = fopen("FILE/customer.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "******************************************" << endl;
    info();
    // info_person *head = NULL;
    head = new info_person;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id, head->name, head->password, head->telephone, head->address, head->money, head->status) != EOF)
    {
        if (strcmp(name, head->id) == 0)
        {
            cout << "用户名:" << head->name << endl;
            cout << "联系方式:" << head->telephone << endl;
            cout << "地址:" << head->address << endl;
            cout << "钱包余额:" << head->money << endl;
        }
    }
    cout << "******************************************" << endl;
    delete[] head;
    fclose(source);
}
bool info::checking(char *name)
{
    bool have = true;
    FILE *source = fopen("FILE/customer.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    info();
    head = new info_person;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id, head->name, head->password, head->telephone, head->address, head->money, head->status) != EOF)
    {
        if (strcmp(head->name, name) == 0)
        {
            have = false;
        }
    }
    delete[] head;
    fclose(source);
    if (have == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
