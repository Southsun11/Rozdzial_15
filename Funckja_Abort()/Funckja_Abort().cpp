#include <iostream>
#include <cstdlib>

double hmean(double x, double y);
int main()
{
    double x, y, z;
    std::cout << "Podaj dwie liczby: ";
    while (std::cin >> x >> y)
    {
        z = hmean(x, y);
        std::cout << "srednia harmoniczna liczb  " << x << " i " << y << " wynosi: " << z << std::endl;
        std::cout << "Podaj kolejna pare liczb <w, aby wyjsc>: ";
    }
    std::cout << "\nkonice";
    return 0;
}

double hmean(double x, double y)
{
    if (x == -y)
    {
        std::cout << "Niepoprawne argumenty fuckcji hmean()\n";
        std::abort();
    }
    return 2.0 * x * y / (x + y);
}
