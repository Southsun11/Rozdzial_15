#include <iostream>


class High
{
public:
    int i;
    High(int ii) :i(ii) {}
};

class Low:public High
{
public:
    Low(int ii) :High(ii) {}
};
class Temp
{
public:
    Temp() {}
};
int main()
{
    High h(100);
    Low l(20);
    Temp t;
    int a;
    High* h2 = static_cast<High*>(&l);
    Low* l2 = static_cast<Low*>(&h);
    //Low* t2 = static_cast<Low*>(&t);
    char c = (char)&a;
    std::cout << c;

    char data[] = "somedata";
    int* dataInt = reinterpret_cast<int*>(data);
    std::cout << "Data " << dataInt[0] << std::endl;
    dataInt[1] = 90;
    std::cout << "Data " << dataInt[1] << std::endl;

    std::cout << data;

}
