#include "admin.hpp"
void administration::output_things()
{
    FILE *source = fopen("FILE/goods.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    bool temp = false;
    things *head = NULL;
    head = new things;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {
        if (temp == false)
        {
            cout << "*******************************************************************************************************************" << endl;
            printf("%-15s %-15s %-18s %-21s %-18s %-15s %-15s\n", "ID", "名称", "价格", "数量", "上架时间", "卖家ID", "商品况态");
            temp = true;
        }
        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", head->id_good, head->name_object, head->price, head->capacity, head->timing, head->id_name, head->status);
    }
    if (temp == false)
    {
        cout << "******************" << endl;
        cout << "没有什么东西" << endl;
        cout << "******************" << endl;
    }
    else
    {
        cout << "*******************************************************************************************************************" << endl;
    }
    fclose(source);
}
void administration::searching_things()
{
    FILE *source = fopen("FILE/goods.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    char tmp[100] = {};
    cout << "请输入商品名称:";
    cin >> tmp;
    bool temp = false;
    things *head = NULL;
    head = new things;
    cout << "********************************************************************************************************" << endl;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {
        if (search(tmp, head->name_object) and strcmp(head->status, "Banned") != 0)
        {
            if (temp == false)
            {
                printf("%-15s %-15s %-17s %-17s %-18s %-18s %-15s\n", "ID", "名称", "价格", "数量", "上架时间", "卖家ID", "商品况态");
            }
            printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", head->id_good, head->name_object, head->price, head->capacity, head->timing, head->id_name, head->status);
            temp = true;
        }
    }
    if (temp == false)
    {
        cout << "没有找到您想搜索的商品！即将返回初始界面" << endl;
    }
    cout << "********************************************************************************************************" << endl;
    fclose(source);
}
bool administration::search(char *str, char *string)
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
void administration::output_order()
{
    FILE *source = fopen("FILE/order.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    bool tmp = false;
    orders *head = NULL;
    head = new orders;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_order, head->id_good, head->price, head->capacity, head->timing, head->id_seller, head->id_buyer) != EOF)
    {
        if (tmp == false)
        {
            cout << "**************************************************************************************************************" << endl;
            printf("%-15s %-16s %-21s %-21s %-15s %-18s %-15s\n", "订单ID", "商品ID", "交易金额", "数量", "交易时间", "买家ID", "卖家ID");
        }
        tmp = true;
        printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", head->id_order, head->id_good, head->price, head->capacity, head->timing, head->id_seller, head->id_buyer);
    }
    if (tmp == false)
    {
        cout << "*************" << endl;
        cout << "没有订单" << endl;
        cout << "*************" << endl;
    }
    else
    {
        cout << "**************************************************************************************************************" << endl;
    }
    fclose(source);
}
void administration::output_account()
{
    FILE *source = fopen("FILE/customer.txt", "r");
    if (source == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    bool temp = false;
    people *head = NULL;
    head = new people;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_person, head->name_person, head->password, head->telephone, head->address, head->price, head->status) != EOF)
    {
        if (temp == false)
        {
            cout << "*************************************************************************************************" << endl;
            printf("%-15s %-15s %-19s %-18s %-18s %-15s\n", "用户ID", "用户名", "联系方式", "地址", "钱包余额", "状态");
            temp = true;
        }
        printf("%-12s %-15s %-15s %-15s %-15s %-15s \n", head->id_person, head->name_person, head->telephone, head->address, head->price, head->status);
    }
    if (temp == false)
    {
        cout << "**********" << endl;
        cout << "没有用户" << endl;
        cout << "**********" << endl;
    }
    else
    {
        cout << "*************************************************************************************************" << endl;
    }
    fclose(source);
}
void administration::deleting_accout()
{
    char remove[100];
    cout << "请输入要删除的用户ID：";
    cin >> remove;
    cout << endl;
    cout << "******************" << endl;
    insert(remove);
    if (have == false)
    {
        cout << "没有用户的ID" << endl;
        cout << "******************" << endl;
    }
    else
    {

        char string;
        cout << "请输入(y/n)";
        cin >> string;
        if (string == 'y')
        {
            input();
            delete_auction_file(remove);
            deleting_things_for_admin(remove);
            input_object_for_admin();
            cout << "删除成功" << endl;
        }
        else
            cout << "删除失败" << endl;
    }
}
void administration::insert(char *remove)
{
    FILE *source = fopen("FILE/customer.txt", "r+");
    FILE *curr = fopen("FILE/remove.txt", "w+");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    people *head = NULL;
    head = new people;
    have = false;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_person, head->name_person, head->password, head->telephone, head->address, head->price) != EOF)
    {
        if (strcmp(head->id_person, remove) != 0)
        {
            fprintf(curr, "%s,%s,%s,%s,%s,%s\n", head->id_person, head->name_person, head->password, head->telephone, head->address, head->price);
        }
        else if (strcmp(head->id_person, remove) == 0)
        {
            have = true;
            cout << "确认要删除该用户吗：" << endl;
            cout << "用户ID：" << head->id_person << endl;
            cout << "用户名：" << head->name_person << endl;
            cout << "联系方式：" << head->telephone << endl;
            cout << "******************" << endl;
        }
    }
    fclose(source);
    fclose(curr);
}
void administration::input()
{
    FILE *source = fopen("FILE/customer.txt", "w");
    FILE *curr = fopen("FILE/remove.txt", "r");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    people *head = NULL;
    head = new people;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_person, head->name_person, head->password, head->telephone, head->address, head->price) != EOF)
    {
        fprintf(source, "%s,%s,%s,%s,%s,%s\n", head->id_person, head->name_person, head->password, head->telephone, head->address, head->price);
    }
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}
void administration::deleting_things()
{
    deleting_object();
    if (have == false)
    {
        cout << "该商品不存在！删除失败！" << endl;
        cout << "**************************" << endl;
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
void administration::deleting_object()
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
    cout << "**************************" << endl;
    cout << "请输入下架商品ID：";
    cin >> remove;
    cout << endl;
    cout << "**************************" << endl;
    have = false;
    things *head = NULL;
    head = new things;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {

        if ((strcmp(head->id_good, remove) == 0))
        {
            have = true;
            char status[100] = "Banned";
            cout << "商品的ID:" << head->id_good << endl;
            cout << "商品的名称:" << head->name_object << endl;
            cout << "商品的金额:" << head->price << endl;
            cout << "商品的描述:" << head->discription << endl;
            strcpy(head->status, status);
        }

        fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status);
    }
    fclose(source);
    fclose(curr);
}
void administration::input_object()
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
    things *head = NULL;
    head = new things;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {
        fprintf(source, "%s,%s,%s,%s,%s,%s,%s,%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status);
    }
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}
void administration::deleting_things_for_admin(char *sums)
{
    FILE *source = fopen("FILE/goods.txt", "r");
    FILE *curr = fopen("FILE/remove.txt", "w");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    things *head = NULL;
    head = new things;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {
        if ((strcmp(head->id_name, sums) != 0))
        {
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status);
        }
    }
    fclose(source);
    fclose(curr);
}
void administration::input_object_for_admin()
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
    things *head = NULL;
    head = new things;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status) != EOF)
    {
        fprintf(source, "%s,%s,%s,%s,%s,%s,%s,%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->timing, head->status);
    }
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}
void administration::delete_auction_file(char *sums)
{
    FILE *source = fopen("FILE/auction.txt", "r");
    FILE *curr = fopen("FILE/remove.txt", "w");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    temp = new auction;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", temp->id_order, temp->id_good, temp->price, temp->capacity, temp->status, temp->timing, temp->id_seller, temp->id_buyer) != EOF)
    {
        if ((strcmp(temp->id_buyer, sums) != 0) and (strcmp(temp->id_seller, sums) != 0))
        {
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", temp->id_order, temp->id_good, temp->price, temp->capacity, temp->status, temp->timing, temp->id_seller, temp->id_buyer);
        }
    }
    fclose(source);
    fclose(curr);
    input_auction_file();
}
void administration::input_auction_file()
{
    FILE *source = fopen("FILE/auction.txt", "w");
    FILE *curr = fopen("FILE/remove.txt", "r");
    if (source == NULL || curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    auction *tmp = NULL;
    tmp = new auction;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", tmp->id_order, tmp->id_good, tmp->price, tmp->capacity, tmp->status, tmp->timing, tmp->id_seller, tmp->id_buyer) != EOF)
    {
        fprintf(source, "%s,%s,%s,%s,%s,%s,%s,%s\n", tmp->id_order, tmp->id_good, tmp->price, tmp->capacity, tmp->status, tmp->timing, tmp->id_seller, tmp->id_buyer);
    }
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}