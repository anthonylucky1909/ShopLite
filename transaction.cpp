#include "transaction.hpp"
void buying::output_things(char *name)
{
    buying();
    FILE *source = fopen("FILE/goods.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    bool temp = false;
    // things *head = NULL;
    head = new things;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {
        if (strcmp(head->status, "onAuction") == 0 and strcmp(head->id_name, name) != 0)
        {
            if (temp == false)
            {
                cout << "************************************************************************************************" << endl;
                printf("%-15s %-15s %-18s %-18s %-19s %-18s\n", "ID", "名称", "价格", "数量", "上架时间", "卖家ID");
                temp = true;
            }
            printf("%-15s %-15s %-15s %-15s %-15s %-15s\n", head->id_good, head->name_object, head->price, head->capacity, head->timing, head->id_name);
        }
    }
    if (temp == false)
    {
        cout << "没有东西" << endl;
    }
    else
    {
        cout << "************************************************************************************************" << endl;
    }
    delete[] head;
    fclose(source);
}
void buying::searching_things(char *name)
{
    FILE *source = fopen("FILE/goods.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    char tmp[100] = {};
    cout << "请输入商品名称:";
    cin.ignore();
    cin.getline(tmp, sizeof(tmp));
    bool condition = false;
    buying();
    head = new things;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {
        if (search(tmp, head->name_object) && strcmp(head->status, "onAuction") == 0)
        {
            if (condition == false)
            {
                cout << "***************************************" << endl;
                printf("%-15s %-16s %-18s\n", "ID", "名称", "价格");
                condition = true;
            }
            printf("%-15s %-15s %-10s \n", head->id_good, head->name_object, head->price);
        }
    }
    if (condition == false)
    {
        cout << "***************************************" << endl;
        cout << "没有找到您想搜索的商品！即将返回初始界面" << endl;
    }
    cout << "***************************************" << endl;
    delete[] head;
    fclose(source);
}
bool buying::search(char *str, char *string)
{
    int len = 0;
    if (strcmp(str, string) == 0)
        return true;
    else
    {
        int j = 0;
        for (int i = 0; string[i] != '\0'; i++)
        {
            if (str[j] == string[i])
            {
                len++;
                j++;
                for (int k = i + 1; string[k] != '\0'; k++)
                {
                    if (str[j] == string[k])
                    {
                        len++;
                        j++;
                    }
                }
            }
            if (len == strlen(str))
                break;
        }
        if (len == strlen(str))
            return true;
        else
            return false;
    }
}
void buying::output_order(char *name)
{
    FILE *source = fopen("FILE/order.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    bool order = false;
    // orders *temp = NULL;
    buying();
    temp = new orders;

    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", temp->id_order, temp->id_good, temp->price, temp->capacity, temp->timing, temp->id_seller, temp->id_buyer) != EOF)
    {
        if (strcmp(name, temp->id_buyer) == 0)
        {
            if (order == false)
            {
                cout << "***********************************************************************************************************" << endl;
                printf("%-16s %-16s %-21s %-18s %-18s %-18s %-15s\n", "订单ID", "商品ID", "交易金额", "数量", "交易时间", "买家ID", "卖家ID");
                order = true;
            }
            printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", temp->id_order, temp->id_good, temp->price, temp->capacity, temp->timing, temp->id_seller, temp->id_buyer);
        }
    }
    if (order == false)
    {
        cout << "***********" << endl;
        cout << "没有订单" << endl;
        cout << "***********" << endl;
    }
    else
    {
        cout << "***********************************************************************************************************" << endl;
    }
    delete[] temp;
    fclose(source);
}
void buying::information()
{
    char name[100] = {};
    FILE *source = fopen("FILE/goods.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    bool info = false;
    cout << "请输入您想查看商品ID:";
    cin >> name;
    // things *head = NULL;
    buying();
    head = new things;
    cout << "*****************************" << endl;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {
        if (strcmp(head->id_good, name) == 0)
        {
            cout << "商品ID    :" << head->id_good << endl;
            cout << "商品名称  :" << head->name_object << endl;
            cout << "商品价格  :" << head->price << endl;
            cout << "上架时间  :" << head->timing << endl;
            cout << "商品描述  :" << head->discription << endl;
            cout << "商品卖家  :" << head->id_name << endl;
            cout << "状态      :" << head->status << endl;
            info = true;
        }
    }
    if (info == false)
    {
        cout << "清单上没有这样的项目" << endl;
        cout << "*****************************" << endl;
    }
    else
    {
        cout << "*****************************" << endl;
    }
    delete[] head;
    fclose(source);
}
void buying::put_zero(int sum1, char *sum)
{
    sum[0] = '0';
    sum[1] = sum1 + '0';
    sum[2] = '\0';
}
void buying::put_char(int sum1, char *sum)
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
void buying::make_id(int count)
{
    int i, j, k;
    int nums = count;
    for (i = 0; nums != 0; i++)
    {
        nums /= 10;
    }
    id[0] = 'T';
    for (j = 1; j < 6 - i; j++)
    {
        id[j] = '0';
    }
    for (k = j; k < 6; k++)
    {
        int temp = count % 10;
        count /= 10;
        id[k] = temp + '0';
    }
    id[k] = '\0';
}
void buying::make_order(char *name)
{
    char id_g[100], capacity[100], money[100];
    cout << "输入商品ID:";
    cin.ignore();
    cin.getline(id_g, sizeof(id_g));

    cout << "输入拍卖金额:";
    cin.getline(money, sizeof(money));

    cout << "输入数量:";
    cin.getline(capacity, sizeof(capacity));

    cout << endl;
    cout << "****************" << endl;
    cout << "拍卖提醒" << endl;
    // time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year, month, day;
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    cout << "拍卖时间: " << year << "-" << month << "-" << day << endl;
    bool cond = check_object(id_g, name, capacity, money);
    if (cond == true)
    {
        change(id_g, name, year, month, capacity, day, money);
        // input_person();
        // change_things(id_g);
        // input_object();
        cout << "拍卖状态: "
             << "交易成功" << endl;
    }
    else
    {
        cout << "拍卖状态: "
             << "交易失败" << endl;
    }
}
bool buying::check_object(char *thing, char *name, char *capacity, char *money)
{
    FILE *source = fopen("FILE/goods.txt", "r");
    FILE *source1 = fopen("FILE/customer.txt", "r");
    if (source == NULL || source1 == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    char price[100] = {};
    // things *head = NULL;
    buying();
    head = new things;
    bool cond = false, cond1 = true, cond2 = false;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {
        if (strcmp(head->id_good, thing) == 0 && strcmp(head->status, "removed") != 0 and atoi(head->price) <= atoi(money) and atoi(head->capacity) >= atoi(capacity))
        {
            if (checking_time() == true)
            {
                cout << "Error : 拍卖结束了" << endl;
                return false;
            }
            cout << "拍卖金额:" << money << endl;
            // strcpy(price, head->price);
            cond = true;
        }

        cond2 = true;
    }
    if (cond == false)
    {
        cout << "拍卖金额和数量有错误" << endl;
    }
    // info_person *temp = NULL;
    tmp = new info_person;

    while (true)
    {
        if (fscanf(source1, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", tmp->id, tmp->name, tmp->password, tmp->telephone, tmp->address, tmp->money) == EOF)
        {
            break;
        }
        else if (strcmp(tmp->id, name) == 0)
        {
            double price1 = strtod(tmp->money, NULL);
            double price2 = strtod(money, NULL);
            if (price1 < price2)
            {
                cout << "钱不够" << endl;
                cond1 = false;
            }
        }
    }
    delete[] head;
    delete[] tmp;
    fclose(source);
    fclose(source1);
    // cout << cond << " " << cond1 << " " << cond2 << endl;
    if (cond == true && cond1 == true && cond2 == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void buying::change(char *id_g, char *name, int year, int month, char *capacity, int day, char *money)
{
    buying();
    char id_order[100] = {}, id_sell[100] = {}, price[100] = {}, share_time[100] = {};
    FILE *source = fopen("FILE/goods.txt", "r");
    FILE *source1 = fopen("FILE/customer.txt", "r");
    FILE *curr = fopen("FILE/remove.txt", "w");
    if (source == NULL || source1 == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    head = new things;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {
        if (strcmp(head->id_good, id_g) == 0)
        {
            strcpy(id_sell, head->id_name);
            strcpy(price, head->price);
            strcpy(share_time, head->timing);
        }
    }
    double size = strtod(capacity, NULL);
    double price1 = strtod(price, NULL);
    tmp = new info_person;
    while (fscanf(source1, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", tmp->id, tmp->name, tmp->password, tmp->telephone, tmp->address, tmp->money) != EOF)
    {
        if (strcmp(tmp->id, name) == 0)
        {
            double value1 = strtod(tmp->money, NULL);
            value1 = value1 - price1;
            fprintf(curr, "%s,%s,%s,%s,%s,%.1f\n", tmp->id, tmp->name, tmp->password, tmp->telephone, tmp->address, value1);
        }
        else if (strcmp(id_sell, tmp->id) == 0)
        {
            double value = strtod(tmp->money, NULL);
            value = value + price1;
            fprintf(curr, "%s,%s,%s,%s,%s,%.1f\n", tmp->id, tmp->name, tmp->password, tmp->telephone, tmp->address, value);
        }
        else
        {
            fprintf(curr, "%s,%s,%s,%s,%s,%s\n", tmp->id, tmp->name, tmp->password, tmp->telephone, tmp->address, tmp->money);
        }
    }
    output_(id_g, name, atoi(money), size, year, month, day, id_sell, share_time);
    delete[] head;
    delete[] tmp;
    fclose(source1);
    fclose(source);
    fclose(curr);
}
void buying::output_(char *id_g, char *name, double price, double capacity, int year, int month, int day, char *id_seller, char *share_time)
{
    char copy[100] = {}, days[100] = {}, months[100] = {};
    if (day < 10)
    {
        put_zero(day, days);
    }
    else
    {
        put_char(day, days);
    }
    if (month < 10)
    {
        put_zero(month, months);
    }
    else
    {
        put_char(month, months);
    }
    int count = 0;
    bool condition = false;
    FILE *order = fopen("FILE/auction.txt", "r+");
    if (order == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    buying();
    temp = new orders;
    while (fscanf(order, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", temp->id_order, temp->id_good, temp->price, temp->capacity, temp->status, temp->timing, temp->id_seller, temp->id_buyer) != EOF)
    {
        if (strcmp(temp->id_order, copy) > 0)
        {
            condition = true;
            memset(copy, 0, sizeof(copy));
            strcpy(copy, temp->id_order);
        }
    }
    if (condition != false)
    {
        for (int i = 1; i < 6; i++)
        {
            if (copy[i] != 0)
            {
                count = count * 10 + copy[i] - '0';
            }
        }
    }
    make_id(count + 1);
    fprintf(order, "%s,%s,%.1lf,%.1lf,%s,%d-%s-%s,%s,%s\n", id, id_g, price, capacity, "onAuction", year, months, days, id_seller, name);
    delete[] temp;
    fclose(order);
}
bool buying::checking_time()
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

        if (head->timing[i] == '\0')
            break;
        if (head->timing[i] == '-')
            count++;
        else if (count == 0)
        {
            second_year = (second_year * 10) + (head->timing[i] - '0');
        }
        else if (count == 1)
        {
            second_month = (second_month * 10) + (head->timing[i] - '0');
        }
        else if (count == 2)
        {
            second_day = (second_day * 10) + (head->timing[i] - '0');
        }
    }
    int diff = day - second_day;
    if (year == second_year and month == second_month and diff == 0)
    {
        return false;
    }
    return true;
}