#include <iostream>
#include <exception>
struct Big
{
    double tab[20000];
};


int main()
{
    Big* pb;
    /*
    try {
        std::cout << "Proba przydzialu duzego bloku pamieci\n";
        pb = new Big[8000];
        std::cout << "Udalo sie przebrnac przez alokacje\n";
    }
    catch (std::bad_alloc & b)
    {
        std::cout << "Przechwycilem wyjatek\n";
        std::cout << b.what() << std::endl;
        exit(EXIT_FAILURE);
    }*/

    pb = new (std::nothrow) Big[10000];
    if (pb == 0)
    {
        std::cout << "nie udalo sie przydzielic pamieci";
        exit(EXIT_FAILURE);
    }
        
    std::cout << "Udalo sie przydzielic pamiec\n";
    pb[0].tab[0] = 5;
    std::cout << pb[0].tab[0] << std::endl;
    std::cin.get();
    delete[] pb;
    return 0;
    
    

}
