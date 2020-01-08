#include <iostream>
#include <cmath>

class badhmean
{
private:
    double v1;
    double v2;
public:
    badhmean(double a = 0, double b = 0) :v1(a), v2(b) {}
    void mesg();
};

inline void badhmean::mesg()
{
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
        << "niepoprawne argumenty: a = -b\n";
}

class badgmean
{
public:
    double v1;
    double v2;
    badgmean(double a = 0, double b = 0) :v1(a), v2(b) {}
    const char* mesg();
};

inline const char * badgmean::mesg()
{
    return "Argumenty funkcji gmean() powinny być >=  0 \n";
}

double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    double x, y, z;
    std::cout << "Podaj dwie liczby: \n";
    while (std::cin >> x >> y)
    {
        try {
            z = hmean(x, y);
            std::cout << "Srednia harmoniczna liczb: " << x << " i " << y << " wynosi: " << z;
            std::cout << "Srednia geometryczna liczb: " << x << " i " << y << " wynosi: " << gmean(x, y);
            std::cout << "Podaj kolejna pare liczb\n";
        }
        catch (badhmean & bg)
        {
            bg.mesg();
            std::cout << "Sprobuj ponownie\n";
            continue;
        }
        catch (badgmean & hg)
        {
            std::cout << hg.mesg();
            std::cout << "Uzyte wartosci: " << hg.v1 << " i " << hg.v2 << std::endl;
            std::cout << "Niestety to koniec zabawy\n";
        }
    }
    std::cout << "Koniec";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw badhmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw badgmean(a, b);
    return std::sqrt(a * b);
}

