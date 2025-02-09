#include "control.hpp"
void control::enter()
{
    refresh_all();
    string nums;
    cout << "=============================================" << endl;
    cout << "1.管理员登入 2.用户注册 3.用户登入 4.退出程序" << endl;
    cout << "=============================================" << endl;
    cout << "输入操作：";
    cin >> nums;
    open head;
    if (nums == "3")
    {
        char a[100];
        bool result = head.sign_customer(a);
        if (result == true)
        {
            cout << "******登入成功******" << endl;
            managed_system(a, 1);
        }
        else
        {
            cout << "******登入失败,即将返回主菜单******" << endl;
            enter();
        }
    }
    else if (nums == "2")
    {
        bool condition = head.sign_up();
        if (condition == false)
        {
            cout << "注册失败" << endl;
        }
        enter();
    }
    else if (nums == "1")
    {
        char admin_id[100];
        bool result = head.sign_admin(admin_id);
        if (result == true)
        {
            cout << "******登入成功******" << endl;
            managed_system(admin_id, 2);
        }
        else
        {
            cout << "******登入失败,即将返回主菜单******" << endl;
            enter();
        }
    }
    else if (nums == "4")
    {
        return;
    }
    else
    {
        system("clear");
        enter();
    }
}
void control::managed_system(char *name, int number)
{
    switch (number)
    {
    case 1:
    {
        open_customer(name);
        break;
    }
    case 2:
    {
        entering();
        break;
    }
    default:
        break;
    }
}
void control::open_customer(char *name)
{
    refresh_all();
    // cout << "hello" << endl;
    refresh_goods();
    string nums;
    cout << "=================================================" << endl;
    cout << "1.我是买家 2.我是卖家 3.人信息管理 4.注销登录" << endl;
    cout << "=================================================" << endl;
    cout << "请输入操作:";
    cin >> nums;

    if (nums == "1")
    {
        buyer(name);
    }
    else if (nums == "2")
    {
        sell(name);
    }
    else if (nums == "3")
    {
        enter_info(name);
    }
    else if (nums == "4")
    {
        system("clear");
        enter();
    }
    else
    {
        system("clear");
        open_customer(name);
    }
}
void control::sell(char *name)
{
    refresh_all();
    string nums;
    cout << "==================================================================================" << endl;
    cout << "1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户主界面" << endl;
    cout << "==================================================================================" << endl;
    cout << "输入操作：";
    cin >> nums;
    // int number1 = strtod(string, NULL);
    // if (number1 < 0 || number1 > 6)
    // {
    //     sell(name);
    // }
    selling head;

    if (nums == "1")
    {
        head.posting(name);
        sell(name);
    }
    else if (nums == "2")
    {
        head.output(name);
        sell(name);
    }
    else if (nums == "3")
    {
        head.change_info();
        sell(name);
    }
    else if (nums == "4")
    {
        head.deleting_things(name);
        sell(name);
    }
    else if (nums == "5")
    {
        head.output_order(name);
        sell(name);
    }
    else if (nums == "6")
    {
        system("clear");
        open_customer(name);
    }
    else
    {
        system("clear");
        sell(name);
    }
}
void control::entering()
{
    refresh_all();
    string number;
    cout << "====================================================================================" << endl;
    cout << "1.查看所有商品 2.搜索商品 3.下架商品 4查看所有订单 5.查看所有用户 6.封禁用户 7.注销" << endl;
    cout << "====================================================================================" << endl;
    cout << "请输入操作：";
    cin >> number;
    if (number == "1" or number == "2" or number == "3" or number == "4" or number == "5" or number == "6" or number == "7")
    {
        int number1 = stoi(number);
        entering_admin(number1);
    }
    else
    {
        system("clear");
        entering();
    }
}
void control::entering_admin(int number)
{
    administration head;

    switch (number)
    {
    case 1:
    {
        head.output_things();
        entering();
        break;
    }
    case 2:
    {
        head.searching_things();
        entering();
        break;
    }
    case 3:
    {
        head.deleting_things();
        entering();
        break;
    }
    case 4:
    {
        head.output_order();
        entering();
        break;
    }
    case 5:
    {
        head.output_account();
        entering();
        break;
    }
    case 6:
    {
        head.deleting_accout();
        entering();
        break;
    }
    case 7:
    {
        open temp;
        system("clear");
        enter();
        break;
    }
    default:
        break;
    }
}
void control::enter_info(char *name)
{

    refresh_all();
    string number;
    cout << "==========================================" << endl;
    cout << "1.查看信息 2.修改信息 3.充值 4.返回用户主界面" << endl;
    cout << "==========================================" << endl;
    cout << "请输入操作:";
    cin >> number;

    info head;

    if (number == "1")
    {
        head.output_account(name);
        enter_info(name);
    }
    else if (number == "2")
    {
        head.change_info(name);
        enter_info(name);
    }
    else if (number == "3")
    {
        head.recharge(name, 4);
        enter_info(name);
    }
    else if (number == "4")
    {
        system("clear");
        open_customer(name);
    }
    else
    {
        system("clear");
        enter_info(name);
    }
}
void control::buyer(char *name)
{
    refresh_all();
    string number;
    cout << "===========================================================================================" << endl;
    cout << "1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面" << endl;
    cout << "===========================================================================================" << endl;
    cout << "输入操作：";
    cin >> number;
    
    buying temp;
  
    if(number=="1")
    {
        temp.output_things(name);
        buyer(name);
        
    }
    else if(number=="2")
    {
        temp.make_order(name);
        buyer(name);
    }
    else if(number=="3")
    {
        temp.searching_things(name);
        buyer(name);
    }
    else if(number== "4")
    {
        temp.output_order(name);
        buyer(name);
    }
    else if(number== "5")
    {
        temp.information();
        buyer(name);
    }
    else if(number== "6")
    {
        system("clear");
        open_customer(name);
    }
    else
    {
        system("clear");
        buyer(name);
    }
}