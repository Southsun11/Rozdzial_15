#pragma once
#include <iostream>
class Class1;
class Class
{
private:
	int time;
public:
	Class(int t = 0) :time(t) {}
	friend void sync(Class& c, const Class1& c1);
	friend void sync(const Class& c, Class1& c1);
	void show() const { std::cout << time << std::endl; }
};

class Class1
{
private:
	int time;
public:
	Class1(int t = 10) :time(t) {}
	friend void sync(Class& c, const Class1& c1);
	friend void sync(const Class& c, Class1& c1);
	void show() const { std::cout << time << std::endl; }
	void set(int t) { time = t; }
};


