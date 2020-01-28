#include <iostream>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
class Grand
{
private:
    int hold;
public:
    Grand(int h = 0) :hold(h) {}
    virtual void speak()const { std::cout << "Jestem klasa Grand!"; }
    virtual int value()const { return hold; }
};

class SuperB :public Grand
{
public:
    SuperB(int h = 0) :Grand(h) {}
    virtual void speak() const { std::cout << "Jestem klasa SuperB"; }
    virtual void say()const { std::cout << "Przechowuje wartosc klasy SuperB ktora wynosi: " << Grand::value() << std::endl; }
};
class Magnificent :public SuperB
{
private:
    char ch;
public:
    Magnificent(int h, char c) :SuperB(h), ch(c) {}
    virtual void speak() const { std::cout << "Jestem klasa Magnificent"; }
    virtual void say()const { std::cout << "Przechowuje znak: " << ch << " i liczbe: " << Grand::value() << std::endl; }
};

Grand* getOne();
Grand& getOne2();
int main()
{
    std::srand(std::time(0));
    Grand* pg;
    SuperB* ps;


    for (int i = 0; i < 5; i++)
    {
        
        std::cout << std::endl;
        pg = getOne();
        std::cout << "Teraz przetwarzam obiekt typu: " << typeid(*pg).name() << std::endl;
        pg->speak();
        std::cout << std::endl;
        if (ps = dynamic_cast<SuperB*>(pg))
            ps->say();
        if (typeid(pg) == typeid(Magnificent))
            std::cout << "Tak jestes wspaniala\n";
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << std::endl;
        Grand& pg2 = getOne2();
        pg2.speak();
        std::cout << std::endl;
        try
        {
            SuperB& ps2 = dynamic_cast<SuperB&>(pg2);
            ps2.say();
        }
        catch (std::bad_cast&)
        {
            std::cout << "wyjatek bad cast\n";
        }
        if (typeid(pg2) == typeid(Magnificent))
            std::cout << "Tak jestes wspaniala\n";
    }
    return 0;
}

Grand* getOne()
{
    Grand* p;
    switch (std::rand() % 3)
    {
    case 0:
        p = new Grand(std::rand() % 1000);
        break;
    case 1:
        p = new SuperB(std::rand() % 1000);
        break;
    case 2:
        p = new Magnificent(std::rand() % 1000, 'A' + std::rand() % 26);
        break;
    default:
        p = new Grand(std::rand() % 1000);
        break;
    }
    return p;
}

Grand& getOne2()
{
    Grand* p;
    switch (std::rand() % 3)
    {
    case 0:
        p = new Grand(std::rand() % 1000);
        break;
    case 1:
        p = new SuperB(std::rand() % 1000);
        break;
    case 2:
        p = new Magnificent(std::rand() % 1000, 'A' + std::rand() % 26);
        break;
    default:
        p = new Grand(std::rand() % 1000);
        break;
    }
    return *p;
}