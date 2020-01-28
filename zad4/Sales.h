#pragma once
#include <string>
#include <stdexcept>
class Sales
{
public:
	enum { MONTHS = 12 };
	class Bad_Index : public std::logic_error
	{
	private:
		int m_bi;
	public:
		explicit Bad_Index(int bi,const std::string& s = "Niepoprawny index w obiekcie klasy Sales\n");
		int bi_val() { return m_bi; }
		virtual ~Bad_Index() noexcept {}
	};
	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales() {};
	int year() { return m_year; }
	virtual double operator[](int n)const;
	virtual double& operator[](int n);
private:
	double m_gross[MONTHS];
	int m_year;
};

class Label_Sales : public Sales
{
public:
	class Nbad_Index : public Sales::Bad_Index
	{
	private:
		std::string m_lbl;
	public:
		Nbad_Index(const std::string& lb, int ix, const std::string& s = "Niepoprawny index w obiekcie klasy LabelSales\n");
		const std::string& label_val() { return m_lbl; }
		virtual ~Nbad_Index() noexcept {}
	};   
public:
	explicit Label_Sales(const std::string& lb = "Brak", int yy = 0);
	Label_Sales(const std::string& lb, int yy,const double* gr, int n);
	virtual ~Label_Sales() {};
	const std::string& label() const { return m_label; }
	virtual double operator[](int n)const;
	virtual double& operator[](int n);
private:
	std::string m_label;
};



