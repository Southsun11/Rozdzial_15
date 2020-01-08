#include<iostream>

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
	const char * mesg();
};

inline const char* mesg()
{
	return "Argumenty funkcji gmean() powinny byæ >=  0 \n";
}