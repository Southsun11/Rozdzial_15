#include <iostream>
double hmean(double a, double b);
int main()
{
    double x, y, z;
    std::cout << "Podaj dwie liczby: ";
    while (std::cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
        }
        catch (const char* s)
        {
            std::cout << s << std::endl;
            std::cout << "Podja kolejną parę liczb: ";
            continue;
        }
        std::cout << "Srednia harmoniczna liczb: " << x << " i " << y << " wynosi " << z << std::endl;
        std::cout << "Podaj kolejną pare liczb <w. aby wyjsc: ";

    }
    std::cout << "koniec";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw "Niepoprawne argumenty funckcji hmean(): a = -b nie jest dowolone";
    return 2.0 * a * b / (a + b);
}
