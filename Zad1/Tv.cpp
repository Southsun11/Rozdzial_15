#include "TV.h"
#include <iostream>

bool Tv::volup()
{
	if (volume < MAXVAL)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume > MINVAL)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	channel = (channel + 1) % maxchannel;
}

void Tv::chandown()
{
	channel = (channel - 1) % maxchannel;
}

void Tv::settings()const
{
	std::cout << "Telewizor jest: " << (state == ON ? "Wlaczony" : "Wylaczony") << std::endl;
	if (state == ON)
	{
		std::cout << "Glosnosc: " << volume << std::endl;
		std::cout << "Program: " << channel << std::endl;
		std::cout << "Tryb: " << (mode == ANTENNA ? "antena" : "kabel") << std::endl;
		std::cout << "Wejscie: " << (input == TV ? "TV" : "DVD") << std::endl;
	}
}

void Tv::change_mode2(Remote& r)
{
	if (this->mode == ON)
		r.mode2 == Remote::NORMAL ? r.mode2 = Remote::INTERACTIVE : r.mode2 = Remote::NORMAL;
	else
		std::cout << "Telewizor wylaczony nie udalo siê zmienic tryby\n";
}