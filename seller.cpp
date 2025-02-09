#include "seller.hpp"

using namespace std;

void selling::posting(char *name)
{
    char yes_no;
    FILE *source = fopen("FILE/goods.txt", "r+");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    // object *head = NULL;
    selling();
    head = new object;
    strcpy(head->status, "onAuction");
    cout << "请输入商品名称:";
    cin.ignore();
    cin.getline(head->name_object, sizeof(head->name_object));
back:
    cout << "请输入商品价格:";
    cin.getline(head->price, sizeof(head->price));
    for (int i = 0; head->price[i] != '\0'; i++)
    {
        if (isalpha(head->price[i]))
        {
            cout << "请再输入商品金额" << endl;
            goto back;
            break;
        }
    }
    // I CHANGE THIS AT MONDAY 09/12
    cout << "请输入商品数量:";
    cin.getline(head->capacity, sizeof(head->capacity));
    cout << "请输入商品描述:";
    cin.getline(head->discription, sizeof(head->discription));
    cout << endl;
    cout << "请确认发布商品的信息无误！" << endl;
    cout << "*********************" << endl;
    cout << "商品名称:" << head->name_object << endl;
    cout << "商品价格:" << head->price << endl;
    cout << "商品数量:" << head->capacity << endl;
    cout << "商品描述:" << head->discription << endl;
    cout << "*********************" << endl;
    cout << endl;
    cout << "您确认要发布该商品吗 （y/n）";
    cin >> yes_no;
    if (yes_no == 'y')
    {
        char a[100], b[100], c[100], d[100], e[100], f[100], g[100], copy[100] = {}, string;
        int i = 0, tmp = 0, temp = 0;
        strcpy(head->id_name, name);
        while ((string = fgetc(source)) != EOF)
        {
            if (string == ',')
            {
                i = 0;
                tmp++;
            }
            else if (tmp == 0)
            {
                a[i] = string;
                i++;
                a[i] = '\0';
            }
            else if (tmp == 1)
            {
                b[i] = string;
                i++;
                b[i] = '\0';
            }
            else if (tmp == 2)
            {
                c[i] = string;
                i++;
                c[i] = '\0';
            }
            else if (tmp == 3)
            {
                d[i] = string;
                i++;
                d[i] = '\0';
            }
            else if (tmp == 4)
            {
                e[i] = string;
                i++;
                e[i] = '\0';
            }
            else if (tmp == 5)
            {
                f[i] = string;
                i++;
                f[i] = '\0';
            }
            else if (tmp == 6)
            {
                g[i] = string;
                i++;
                g[i] = '\0';
            }
            if (string == '\n')
            {
                if (strcmp(a, copy) > 0)
                {
                    memset(copy, 0, sizeof(copy));
                    strcpy(copy, a);
                }
                memset(a, 0, sizeof(a));
                memset(b, 0, sizeof(b));
                memset(c, 0, sizeof(c));
                memset(d, 0, sizeof(d));
                memset(e, 0, sizeof(e));
                memset(f, 0, sizeof(f));
                memset(g, 0, sizeof(f));
                tmp = 0;
                temp = 1;
                i = 0;
            }
        }
        int count = 0;
        if (temp == 1)
        {
            for (int i = 1; i < 6; i++)
            {
                if (copy[i] != 0)
                {
                    count = count * 10 + copy[i] - '0';
                }
            }
        }
        char month[100] = {}, day[100] = {};
        id_naming(head, count + 1);
        fputs(head->id_good, source);
        fputs(",", source);
        fputs(head->name_object, source);
        fputs(",", source);
        fputs(head->price, source);
        fputs(",", source);
        // CHANGE ON MONDAY 09/12
        fputs(head->capacity, source);

        fputs(",", source);
        fputs(head->discription, source);
        fputs(",", source);
        fputs(head->id_name, source);
        fputs(",", source);
        clock(head);
        fprintf(source, "%d", head->year);
        fputs("-", source);
        if (head->month < 10)
        {
            put_zero(head->month, month);
        }
        else
        {
            put_char(head->month, month);
        }
        if (head->day < 10)
        {
            put_zero(head->day, day);
        }
        else
        {
            put_char(head->day, day);
        }
        fputs(month, source);
        fputs("-", source);
        fputs(day, source);
        fputs(",", source);
        fputs(head->status, source);
        fputs("\n", source);
        cout << "发布成功" << endl;
    }
    else
    {
        cout << "发布失败" << endl;
    }
    delete[] head;
    fclose(source);
}
void selling::clock(object *head)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year, month, day;
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    head->year = year;
    head->month = month;
    head->day = day;
}
void selling::id_naming(object *head, int count)
{
    int i, j, k;
    int nums = count;
    for (i = 0; nums != 0; i++)
    {
        nums /= 10;
    }
    head->id_good[0] = 'M';
    for (j = 1; j < 6 - i; j++)
    {
        head->id_good[j] = '0';
    }
    for (k = j; k < 6; k++)
    {
        int temp = count % 10;
        count /= 10;
        head->id_good[k] = temp + '0';
    }
}
void selling::output(char *naming)
{

    FILE *source = fopen("FILE/goods.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    bool condition = false;
    // object *head = NULL;
    selling();
    head = new object;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->time, head->status) != EOF)
    {

        if (strcmp(head->id_name, naming) == 0)
        {
            if (condition == false)
            {
                cout << "**********************************************************************************************************" << endl;
                printf("%-15s %-18s %-18s %-18s %-18s %-15s %-15s\n", "ID", "名称", "价格", "数量", "上架时间", "卖家ID", "商品况态");
            }
            if (strcmp(head->status, "onAuction") == 0)
            {
                printf("%-15s %-16s %-15s %-15s %-15s %-15s%-15s\n", head->id_good, head->name_object, head->price, head->capacity, head->time, head->id_name, head->status);
                condition = true;
            }
        }
    }
    if (condition == false)
    {
        cout << "**************" << endl;
        cout << "没有项目出售" << endl;
        cout << "**************" << endl;
    }
    else
    {
        cout << "**********************************************************************************************************" << endl;
    }
    delete[] head;
    fclose(source);
}
void selling::change_info()
{
    int nums;
    char copy[100] = {}, name[100] = {};
    cout << "***********************************************" << endl;
    cout << "请输入修改商品ID:";
    cin >> name;
    cout << "请选择修改的的属性 （1.价格 2.描述):";
    cin >> nums;
    if (nums == 1)
    {
        cout << "请输入修改后的商品价格:";
        cin >> copy;
    }
    else if (nums == 2)
    {
        cout << "请输入修改后的商品描述:";
        cin.ignore();
        cin.getline(copy, sizeof(copy));
    }
    bool condi = false;
    insert(copy, nums, name, condi);
    cout << "***********************************************" << endl;
}
void selling::insert(char *copy, int nums, char *name, bool condi)
{
    cout << "***********************************************" << endl;
    FILE *source = fopen("FILE/goods.txt", "r+");
    FILE *curr = fopen("FILE/remove.txt", "w+");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    // object *head = NULL;
    selling();
    head = new object;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->time, head->status) != EOF)
    {
        if (strcmp(head->id_good, name) == 0 && strcmp(head->status, "onAuction") == 0)
        {
            if (checking_time() == true)
            {
                cout << "无法更改，因为已超过拍卖时间" << endl;
                return;
            }
            if (nums == 1)
            {
                strcpy(head->price, copy);
            }
            else if (nums == 2)
            {
                strcpy(head->discription, copy);
            }
            if (condi == false)
            {
                cout << "请确认修改后的商品信息！" << endl;
                cout << endl;
                cout << "***********************************************" << endl;
            }
            cout << "商品ID:" << head->id_good << endl;
            cout << "商品名称:" << head->name_object << endl;
            cout << "商品价格:" << head->price << endl;
            cout << "商品描述:" << head->discription << endl;
            condi = true;
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->time, head->status);
        }
        else
        {
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->time, head->status);
        }
    }
    delete[] head;
    fclose(source);
    fclose(curr);
    if (condi == false)
    {
        cout << "列表中没有项目" << endl;
    }
    else if (condi == true)
    {
        char string;
        cout << "确认修改?(y/n)";
        cin >> string;
        if (string == 'y' && (nums == 1 || nums == 2))
        {
            input();
            cout << "修改成功" << endl;
        }
        else
        {
            cout << "没有对应的商品属性，修改失败" << endl;
        }
    }
}
void selling::input()
{
    FILE *source = fopen("FILE/goods.txt", "w+");
    FILE *curr = fopen("FILE/remove.txt", "r+");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    // object *head = NULL;
    selling();
    head = new object;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->time, head->status) != EOF)
    {
        fprintf(source, "%s,%s,%s,%s,%s,%s,%s,%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->time, head->status);
    }
    delete[] head;
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}
void selling::deleting_things(char *name)
{
    deleting_object(name);
    if (have == false)
    {
        cout << "该商品不存在或不可以修改！删除失败！" << endl;
        cout << "******************" << endl;
    }
    else if (have == true)
    {
        char string;
        cout << "请输入(y/n)";
        cin >> string;
        if (string == 'y')
        {
            input_object();
            cout << "删除成功" << endl;
        }
        else
            cout << "删除失败" << endl;
    }
}
void selling::deleting_object(char *name)
{
    FILE *source = fopen("FILE/goods.txt", "r");
    FILE *curr = fopen("FILE/remove.txt", "w");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }

    char remove[100], str;
    int count = 0, i = 0, k = 0;
    cout << "******************" << endl;
    cout << "请输入下架商品ID：";
    cin >> remove;
    cout << endl;
    cout << "******************" << endl;
    have = false;
    // object *head = NULL;
    selling();
    head = new object;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->time, head->status) != EOF)
    {

        if ((strcmp(head->id_name, name) == 0) && (strcmp(head->id_good, remove) == 0) and (checking_time() == false))
        {
            have = true;
            char status[100] = "removed";
            cout << "商品的ID:" << head->id_good << endl;
            cout << "商品的名称:" << head->name_object << endl;
            cout << "商品的价格:" << head->price << endl;
            cout << "商品的数量:" << head->capacity << endl;
            cout << "商品的描述:" << head->discription << endl;
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->time, status);
        }
        else
        {
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->time, head->status);
        }
    }
    delete[] head;
    fclose(source);
    fclose(curr);
}
void selling::input_object()
{
    char str;
    int count = 0, i = 0;
    FILE *source = fopen("FILE/goods.txt", "w");
    FILE *curr = fopen("FILE/remove.txt", "r");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    // object *head = NULL;
    selling();
    head = new object;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->discription, head->id_name, head->time, head->status) != EOF)
    {
        fprintf(source, "%s,%s,%s,%s,%s,%s,%s\n", head->id_good, head->name_object, head->price, head->discription, head->id_name, head->time, head->status);
    }
    delete[] head;
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}
void selling::output_order(char *name)
{
    FILE *source = fopen("FILE/order.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    bool condition = false;
    // orders *temp = NULL;
    selling();
    temp = new orders;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", temp->id_order, temp->id_good, temp->price, temp->capacity, temp->timing, temp->id_seller, temp->id_buyer) != EOF)
    {
        if (strcmp(temp->id_seller, name) == 0)
        {
            if (condition == false)
            {
                cout << "********************************************************************************************" << endl;
                printf("%-16s %-16s %-20s %-18s %-18s %-15s\n", "订单ID", "商品ID", "交易单价", "数量", "交易时间", "买家ID");
            }
            printf("%-15s %-15s %-15s %-15s %-15s %-15s\n", temp->id_order, temp->id_good, temp->price, temp->capacity, temp->timing, temp->id_seller);
            condition = true;
        }
    }
    if (condition == false)
    {
        cout << "*****************" << endl;
        cout << "没有订单" << endl;
        cout << "*****************" << endl;
    }
    else
    {
        cout << "********************************************************************************************" << endl;
    }
    delete[] temp;
    fclose(source);
}
void selling::put_zero(int sum1, char *sum)
{
    sum[0] = '0';
    sum[1] = sum1 + '0';
    sum[2] = '\0';
}
void selling::put_char(int sum1, char *sum)
{
    int a = sum1, count = 0;
    while (a != 0)
    {
        a = a / 10;
        count++;
    }
    while (sum1 != 0)
    {
        sum[count - 1] = (sum1 % 10) + '0';
        sum1 = sum1 / 10;
        count--;
    }
}
bool selling::checking_time()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year, month, day;
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;

    int second_year = 0, second_month = 0, second_day = 0;
    // int size = sizeof(head->time) / sizeof(head->time[0]);
    int count = 0;
    for (int i = 0;; i++)
    {

        if (head->time[i] == '\0')
            break;
        if (head->time[i] == '-')
            count++;
        else if (count == 0)
        {
            second_year = (second_year * 10) + (head->time[i] - '0');
        }
        else if (count == 1)
        {
            second_month = (second_month * 10) + (head->time[i] - '0');
        }
        else if (count == 2)
        {
            second_day = (second_day * 10) + (head->time[i] - '0');
        }
    }
    int dif = day - second_day;
    if (year == second_year and month == second_month and dif == 0)
    {
        return false;
    }
    return true;
}