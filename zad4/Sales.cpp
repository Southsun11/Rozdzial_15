#include "Sales.h"
Sales::Bad_Index::Bad_Index(int ix, const std::string& s):std::logic_error(s),m_bi(ix)
{
}

Sales::Sales(int yy)
{
	m_year = yy;
	for (int i = 0; i < MONTHS; i++)
		m_gross[i] = 0;
}

Sales::Sales(int yy, const double* gr, int n)
{
	m_year = yy;
	for (int i = 0; i < n; i++)
		m_gross[i] = gr[i];
	for (n; n < MONTHS; n++)
		m_gross[n] = 0;
}

double Sales::operator[](int n)const
{
	if (n < 0 || n >= MONTHS)
		throw Bad_Index(n);
	return m_gross[n];
}

double& Sales::operator[](int n)
{
	if (n < 0 || n >= MONTHS)
		throw Bad_Index(n);
	return m_gross[n];
}

Label_Sales::Nbad_Index::Nbad_Index(const std::string& lb, int ix, const std::string& s) : Sales::Bad_Index(ix, s)
{
	m_lbl = lb;
}

Label_Sales::Label_Sales(const std::string& lb, int yy)
{
	m_label = lb;
}

Label_Sales::Label_Sales(const std::string& lb, int yy, const double* gr, int n) :Sales(yy, gr, n)
{
	m_label = lb;
}

double Label_Sales::operator[](int n)const
{
	if (n <0 || n >= MONTHS)
		throw Nbad_Index(m_label,n);
	return Sales::operator[](n);
}

double& Label_Sales::operator[](int n)
{
	if (n < 0 || n >= MONTHS)
	   throw Nbad_Index(m_label, n);
	return Sales::operator[](n);
}