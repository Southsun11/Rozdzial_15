#include <iostream>
#include <cmath>
#include <stdexcept>
//#include <exception>

class Badmean : public std::logic_error
{
    double m_a;
    double m_b;
public:
    Badmean(double a, double b,const std::string & msg) :m_a(a), m_b(b),std::logic_error(msg) {}
    const double value1() { return m_a; }
    const double value2() { return m_b; }
    //const char* what() const;
};

class badhmean: public Badmean
{
public:
    badhmean(double a, double b, const std::string & msg = "niepoprawne: a = -b\nWyjatek klasy badhmean\n") :Badmean(a, b, msg) {}
    
};

class badgmean: public Badmean
{
public:
    badgmean(double a, double b, const std::string  & msg = "niepoprawne, powinny być >=  0 \nWyjatek klasy badgmean\n") :Badmean(a, b, msg) {}
    
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
        catch (Badmean & bm)
        {
            std::cout << "Argumenty: " << bm.value1() << " i " << bm.value2();
             std::cout << bm.what();
            //break;
        }
    }
    std::cout << "Koniec";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw badhmean(a,b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw badgmean(a,b);
    return std::sqrt(a * b);
}

