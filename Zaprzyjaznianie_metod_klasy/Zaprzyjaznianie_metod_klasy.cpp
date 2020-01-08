#include "TV.h"
#include <iostream>

int main()
{
    Tv s42;
    std::cout << "Poczatkowe ustawienia telewizora\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    std::cout << "Nowe ustawienia telewizora\n";
    s42.settings();
    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    std::cout << "Ustawienia telwizora po uzyciu pilota\n";
    s42.settings();
    Tv s58(Tv::ON);
    s58.set_mode();
    grey.set_chan(s58, 28);
    std::cout << "\nustawienia telewizora 58\n";
    s58.settings();
    return 0;
}
