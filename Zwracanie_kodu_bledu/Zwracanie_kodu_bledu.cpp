#include <iostream>
#include <cstdlib>

double hmean(double x, double y,double * ans);
int main()
{
    double x, y,z;
    
    std::cout << "Podaj dwie liczby: ";
    while (std::cin >> x >> y)
    {
        if (hmean(x, y, &z))
            std::cout << "srednia harmoniczna liczb  " << x << " i " << y << " wynosi: " << z << std::endl;
        else
            std::cout << "Suma liczba nie moze wynosic 0, sprobuj jeszcze raz\n";

        std::cout << "Podaj kolejna pare liczb <w, aby wyjsc>: ";
    }
    std::cout << "\nkonice";
    return 0;
}

double hmean(double x, double y,double * ans)
{
    if (x == -y)
    {
        *ans = DBL_MAX;
        return false;
    }
    else 
    *ans = 2.0 * x * y / (x + y);
    return true;
}
