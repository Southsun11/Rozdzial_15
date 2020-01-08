#include "Class.h"
#include <iostream>

int main()
{
    Class c(4);
    Class1 c1;
    c.show();
    c1.show();
    sync((const Class &)c, c1);
    c.show();
    c1.show();
    c1.set(42);
    sync(c, (const Class1)c1);
    c.show();
    c1.show();


    
}
