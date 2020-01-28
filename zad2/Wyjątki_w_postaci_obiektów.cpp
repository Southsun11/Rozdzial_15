#include <iostream>
#include <cmath>
#include <stdexcept>
//#include <exception>

class badhmean: public std::logic_error
{
public:
    badhmean() : logic_error("niepoprawne argumenty: a = -b\n") {}
     void what();
};

inline void badhmean::what()
{
    std::cout  << "niepoprawne argumenty: a = -b\n";
}

class badgmean: public std::logic_error
{
public:
    badgmean() : logic_error("Argumenty funkcji gmean() powinny być >=  0 \n") {}
    
};



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
            std::cout << "\nSrednia geometryczna liczb: " << x << " i " << y << " wynosi: " << gmean(x, y);
            std::cout << "\nPodaj kolejna pare liczb\n";
        }
        catch (badhmean & bg)
        {
            bg.what();
            std::cout << "Sprobuj ponownie\n";
            continue;
        }
        catch (badgmean & hg)
        {
            std::cout << hg.what();
            //std::cout << "Uzyte wartosci: " << hg.v1 << " i " << hg.v2 << std::endl;
            std::cout << "Niestety to koniec zabawy\n";
            break;
        }
    }
    std::cout << "Koniec";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw badhmean();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw badgmean();
    return std::sqrt(a * b);
}

