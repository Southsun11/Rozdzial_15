#include "Nagłówek.h"
#include <iostream>
#include <string>


class Demo
{
private:
    std::string word;
public:
    Demo(const char* c) {
        word = c;
        std::cout << "Obiekt demo: " << word << " utworzony\n";
    }
    ~Demo()
    {
        std::cout << "Obiekt demo: " << word << " usuniety\n";
    }
    void show() const
    {
        std::cout << "Obiekt demo: " << word << " żyje\n";
    }
};


double hmean(double a, double b);
double gmena(double a, double b);
double mean(double a, double b);
int main()
{
    double x, y, z;
    Demo dl("z bloku zagniezdzonego w funkcji main()");
    std::cout << "Podaj dwie liczby\n";
    while (std::cin >> x >> y)
    {
        try
        {
            z = mean(x, y);
            std::cout << "Srednia srednich liczb: " << x << " i " << y << " wynosi " << z << std::endl;
            std::cout << "Podaj kolejna pare liczb: ";
        }
        catch (std::exception & s)
        {
            std::cout << s.what();
            continue;
        }
        catch (badhmean & bh)
        {
            bh.what();
            std::cout << "Sprobuj ponownie\n";
            continue;
        }
        catch (badgmean & bg)
        {
            std::cout << bg.what();
            std::cout << "Uzyte wartosci: " << bg.v1 << " i " << bg.v2 << std::endl;
            std::cout << "Niestety koniec zabawy\n";
            exit(EXIT_FAILURE);
        }
        catch (...)
        {
            std::cout << "Wyjatek do wszystkiego\n";
        }
        dl.show();
    }
    std::cout << "Koniec\n";
    std::cin.get();
    std::cin.get();
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

double mean(double a, double b)
{
    double am, hm, gm;
    Demo d2("z funkcji mean()*");
    am = (a + b) / 2.0;
    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch (badhmean & bg)
    {
        bg.what();
        std::cout << "Przechwycenie w mean()\n";
        throw;
    }
    //throw 4;
    d2.show();
    return (am + hm + gm) / 3.0;
}

