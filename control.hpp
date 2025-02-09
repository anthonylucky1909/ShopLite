#include <iostream>
#include "open.hpp"
#include "seller.hpp"
#include "admin.hpp"
#include "information.hpp"
#include "transaction.hpp"
#include "refresh.hpp"
using namespace std;
class control : public buying , public selling, public refresh,public info
{
public:
    void enter();

private:
    void managed_system(char *name, int number);
    void open_customer(char *name);
    void sell(char *name);
    void entering();
    void entering_admin(int number);
    void enter_info(char *name);
    void buyer(char *name);
};
