#pragma once
#include <iostream>
#include <cmath>
#include <exception>

class badhmean:public std::exception
{
private:
    double v1;
    double v2;
public:
    badhmean(double a = 0, double b = 0) :v1(a), v2(b) {}
    virtual const char * what()const;
};

inline const char* badhmean::what()const
{
    return  "niepoprawne argumenty: a = -b\n";
}

class badgmean: public std::exception
{
public:
    double v1;
    double v2;
    badgmean(double a = 0, double b = 0) :v1(a), v2(b) {}
    virtual const char* what()const;
};

inline const char* badgmean::what() const
{
    return "Argumenty funkcji gmean() powinny byæ >=  0 \n";
}