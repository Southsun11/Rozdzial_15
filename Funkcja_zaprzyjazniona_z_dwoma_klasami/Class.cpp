#include "Class.h"
void sync(Class& c, const Class1& c1)
{
	c.time = c1.time;
}
void sync(const Class& c, Class1& c1)
{
	c1.time = c.time;
}
