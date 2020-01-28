#include <iostream>
void change(int* i, int k);
int main()
{
    int p = 10;
    const int d = 100;
    double e = 2.4324;
    int c = e;
    std::cout << d << "   " << d << std::endl;
    change(&p, 299);
    change(const_cast<int*>(&d), 299);
    std::cout << p << "   " << d << std::endl;

}

void change(int* i, int k)
{
    *i += k;
}
