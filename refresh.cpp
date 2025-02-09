#include "refresh.hpp"

void refresh::refresh_all()
{
    // cout << "masuk" << endl;
    FILE *auction = fopen("FILE/auction.txt", "r");
    orders *Node = new orders;
    index = 0;
    string id_good_important;
    bool mutex = false;
    bool another_process = false;
    char id_order[100], id_good[100], price[100], capacity[100], status[100], time[100], id_seller[100], id_buyer[100];
    while (fscanf(auction, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", id_order, id_good, price, capacity, status, time, id_seller, id_buyer) != EOF)
    {
        string id_barang = id_good;
        if (checking_time(time) == true and mutex == false)
        {
            id_good_important = string(id_good);
            mutex = true;
        }
        else if (checking_time(time) == true and another_process == false and id_good_important != id_barang)
        {
            another_process = true;
        }
        if (id_barang == id_good_important)
        {
            strcpy(array[index].id_order, id_order);
            strcpy(array[index].id_good, id_good);
            strcpy(array[index].price, price);
            strcpy(array[index].capacity, capacity);
            strcpy(array[index].status, status);
            strcpy(array[index].time, time);
            strcpy(array[index].id_seller, id_seller);
            strcpy(array[index].id_buyer, id_buyer);
            index++;
        }
    }
    // cout << "mutex" << mutex << " another_proses" << another_process << endl;
    if (mutex == false and another_process == false)
        return;
    for (int i = 0; i < index; i++)
    {
        for (int j = i + 1; j < index; j++)
        {
            if (array[i].price > array[j].price)
            {
                strcpy(id_order, array[i].id_order);
                strcpy(id_good, array[i].id_good);
                strcpy(price, array[i].price);
                strcpy(capacity, array[i].capacity);
                strcpy(status, array[i].status);
                strcpy(time, array[i].time);
                strcpy(id_seller, array[i].id_seller);
                strcpy(id_buyer, array[i].id_buyer);

                strcpy(array[i].id_order, array[j].id_order);
                strcpy(array[i].id_good, array[j].id_good);
                strcpy(array[i].price, array[j].price);
                strcpy(array[i].capacity, array[j].capacity);
                strcpy(array[i].status, array[j].status);
                strcpy(array[i].time, array[j].time);
                strcpy(array[i].id_seller, array[j].id_seller);
                strcpy(array[i].id_buyer, array[j].id_buyer);

                strcpy(array[j].id_order, id_order);
                strcpy(array[j].id_good, id_good);
                strcpy(array[j].price, price);
                strcpy(array[j].capacity, capacity);
                strcpy(array[j].status, status);
                strcpy(array[j].time, time);
                strcpy(array[j].id_seller, id_seller);
                strcpy(array[j].id_buyer, id_buyer);
            }
        }
    }
    // for (int i = 0; i < index; i++)
    // {
    //     cout << array[i].id_buyer << " " << array[i].id_order << " " << array[i].price << " " << array[i].capacity << endl;
    // }
    fclose(auction);
    make_order();
    if (another_process == true)
        refresh_all();
    return;
}

bool refresh::checking_time(char *timing)
{
    // cout << timing << endl;
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
        if (timing[i] == '\0')
            break;
        if (timing[i] == '-')
            count++;
        else if (count == 0)
        {
            second_year = (second_year * 10) + (timing[i] - '0');
        }
        else if (count == 1)
        {
            second_month = (second_month * 10) + (timing[i] - '0');
        }
        else if (count == 2)
        {
            second_day = (second_day * 10) + (timing[i] - '0');
        }
    }
    // cout << year << " " << second_year << " " << month << " " << second_month << " " << day << " " << second_day << endl;
    if (year == second_year and month == second_month and day == second_day)
        return false;
    return true;
}

void refresh::make_order()
{
    // cout << "make order" << endl;
    FILE *goods = fopen("FILE/goods.txt", "r");
    int capacity;
    head = new object;
    while (fscanf(goods, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", head->id_good, head->name_object, head->price, head->capacity, head->discription, head->id_name, head->time, head->status) != EOF)
    {
        if (strcmp(array[0].id_good, head->id_good) == 0)
        {
            if (strcmp(head->status, "removed") == 0)
            {
                change_ordering();
                return;
            }
            capacity = atoi(head->capacity);
            break;
        }
    }
    int i;
    int total = 0;
    for (i = 0; i < index; i++)
    {
        int prev_capacity = capacity;
        capacity = capacity - atoi(array[i].capacity);
        if (capacity < 0)
        {
            string tmp = to_string(prev_capacity);
            total = total + (atoi(array[i].price) * prev_capacity);
            strcpy(array[i].capacity, tmp.c_str());
            // cout << atoi(array[i].price) << " ordere bro " << atoi(array[i].capacity) << endl;
            break;
        }
        else
        {
            total = total + (atoi(array[i].price) * atoi(array[i].capacity));
        }
        if (capacity == 0)
        {
            // cout << atoi(array[i].price) << " ordere bro " << atoi(array[i].capacity) << endl;
            break;
        }
        // cout << atoi(array[i].price) << " ordere bro " << atoi(array[i].capacity) << endl;
    }
    fclose(goods);
    // change customer
    input_to_order(i);
    change_customer(i, total);

    // change  good;
    change_goods();

    // change auction
    change_ordering();
}
void refresh::change_customer(int i, int total)
{
    // cout << "change_customer" << endl;
    FILE *source = fopen("FILE/customer.txt", "r");
    FILE *curr = fopen("FILE/remove.txt", "w");
    if (source == NULL or curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    info_person *h = new info_person;
    int count = 0;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", h->id, h->name, h->password, h->telephone, h->address, h->money, h->status) != EOF)
    {
        if (count <= i and strcmp(h->id, array[count].id_buyer) == 0)
        {
            int money = atoi(h->money) - (atoi(array[count].price) * atoi(array[count].capacity));
            string tmp = to_string(money);
            strcpy(h->money, tmp.c_str());
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s\n", h->id, h->name, h->password, h->telephone, h->address, h->money, h->status);
            count++;
        }
        else if (strcmp(h->id, array[count].id_seller) == 0)
        {
            int money = atoi(h->money) + total;
            string tmp = to_string(money);
            strcpy(h->money, tmp.c_str());
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s\n", h->id, h->name, h->password, h->telephone, h->address, h->money, h->status);
        }
        else
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s\n", h->id, h->name, h->password, h->telephone, h->address, h->money, h->status);
    }
    fclose(source);
    fclose(curr);
    input_customer();
}
void refresh::input_customer()
{
    // cout << "input_customer" << endl;
    FILE *source = fopen("FILE/customer.txt", "w");
    FILE *curr = fopen("FILE/remove.txt", "r");
    if (source == NULL or curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    info_person *h = new info_person;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", h->id, h->name, h->password, h->telephone, h->address, h->money, h->status) != EOF)
    {
        fprintf(source, "%s,%s,%s,%s,%s,%s,%s\n", h->id, h->name, h->password, h->telephone, h->address, h->money, h->status);
    }
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}
void refresh::change_goods()
{
    // cout << "change_goods" << endl;
    FILE *source = fopen("FILE/goods.txt", "r");
    FILE *curr = fopen("FILE/remove.txt", "w");
    if (source == NULL or curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    object *heading = new object;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", heading->id_good, heading->name_object, heading->price, heading->capacity, heading->discription, heading->id_name, heading->time, heading->status) != EOF)
    {
        if (strcmp(array[0].id_good, heading->id_good) == 0)
        {
            string tmp = "removed";
            strcpy(heading->status, tmp.c_str());
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", heading->id_good, heading->name_object, heading->price, heading->capacity, heading->discription, heading->id_name, heading->time, heading->status);
        }
        else
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", heading->id_good, heading->name_object, heading->price, heading->capacity, heading->discription, heading->id_name, heading->time, heading->status);
    }
    fclose(source);
    fclose(curr);
    input_gooods();
}
void refresh::input_gooods()
{
    // cout << "input_goods" << endl;
    FILE *source = fopen("FILE/goods.txt", "w");
    FILE *curr = fopen("FILE/remove.txt", "r");
    if (source == NULL or curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    object *heading = new object;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", heading->id_good, heading->name_object, heading->price, heading->capacity, heading->discription, heading->id_name, heading->time, heading->status) != EOF)
    {
        fprintf(source, "%s,%s,%s,%s,%s,%s,%s,%s\n", heading->id_good, heading->name_object, heading->price, heading->capacity, heading->discription, heading->id_name, heading->time, heading->status);
    }
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}
void refresh::input_to_order(int i)
{
    FILE *source = fopen("FILE/auction.txt", "r");
    FILE *order = fopen("FILE/order.txt", "r+");
    if (source == NULL or order == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    int count = 0;
    orders *heading = new orders;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", heading->id_order, heading->id_good, heading->price, heading->capacity, heading->status, heading->time, heading->id_seller, heading->id_buyer) != EOF)
    {
        if (strcmp(heading->id_good, array[count].id_good) == 0 and count <= i)
        {
            fprintf(order, "%s,%s,%s,%s,%s,%s,%s\n", array[count].id_order, array[count].id_good, array[count].price, array[count].capacity, array[count].time, array[count].id_seller, array[count].id_buyer);
            count++;
        }
    }
    fclose(order);
    fclose(source);
}
void refresh::change_ordering()
{
    // cout << "change_ordering" << endl;
    FILE *source = fopen("FILE/auction.txt", "r");
    FILE *curr = fopen("FILE/remove.txt", "w");
    if (source == NULL or curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    orders *heading = new orders;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", heading->id_order, heading->id_good, heading->price, heading->capacity, heading->status, heading->time, heading->id_seller, heading->id_buyer) != EOF)
    {
        if (strcmp(heading->id_good, array[0].id_good) != 0)
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", heading->id_order, heading->id_good, heading->price, heading->capacity, heading->status, heading->time, heading->id_seller, heading->id_buyer);
    }
    fclose(source);
    fclose(curr);
    input_ordering();
}
void refresh::input_ordering()
{
    // cout << "change_ordering111" << endl;
    FILE *source = fopen("FILE/auction.txt", "w");
    FILE *curr = fopen("FILE/remove.txt", "r");
    if (source == NULL or curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    orders *heading = new orders;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", heading->id_order, heading->id_good, heading->price, heading->capacity, heading->status, heading->time, heading->id_seller, heading->id_buyer) != EOF)
    {
        fprintf(source, "%s,%s,%s,%s,%s,%s,%s,%s\n", heading->id_order, heading->id_good, heading->price, heading->capacity, heading->status, heading->time, heading->id_seller, heading->id_buyer);
    }
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}
void refresh::refresh_goods()
{
    // cout << "refressh goods" << endl;
    FILE *source = fopen("FIle/goods.txt", "r");
    FILE *curr = fopen("FILE/remove.txt", "w");
    if (source == NULL or curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    object *heading = new object;
    while (fscanf(source, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", heading->id_good, heading->name_object, heading->price, heading->capacity, heading->discription, heading->id_name, heading->time, heading->status) != EOF)
    {
        if (checking_time(heading->time) == false)
        {
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", heading->id_good, heading->name_object, heading->price, heading->capacity, heading->discription, heading->id_name, heading->time, heading->status);
        }
        else
        {
            string temp = "removed";
            strcpy(heading->status, temp.c_str());
            fprintf(curr, "%s,%s,%s,%s,%s,%s,%s,%s\n", heading->id_good, heading->name_object, heading->price, heading->capacity, heading->discription, heading->id_name, heading->time, heading->status);
        }
    }
    fclose(source);
    fclose(curr);
    refresh_goods_input();
}
void refresh::refresh_goods_input()
{
    FILE *source = fopen("FIle/goods.txt", "w");
    FILE *curr = fopen("FILE/remove.txt", "r");
    if (source == NULL or curr == NULL)
    {
        cout << "error" << endl;
        exit(EXIT_FAILURE);
    }
    object *heading = new object;
    while (fscanf(curr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", heading->id_good, heading->name_object, heading->price, heading->capacity, heading->discription, heading->id_name, heading->time, heading->status) != EOF)
    {

        fprintf(source, "%s,%s,%s,%s,%s,%s,%s,%s\n", heading->id_good, heading->name_object, heading->price, heading->capacity, heading->discription, heading->id_name, heading->time, heading->status);
    }
    fclose(source);
    fclose(fopen("FILE/remove.txt", "w"));
}
