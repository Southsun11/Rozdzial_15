#include "queue.h"
#include <string>
#include <iostream>

int main()
{
	QueueTP<std::string> cs(5);
	std::string temp;
	while (!cs.isfull())
	{
		std::cout << "Wpisz swoje imie i nazwisko.Zaostaniesz obsluzony/a\n"
			<< "Wedlug kolejnosci przycia.\n"
			<< "Imie i Nazisko: ";
		getline(std::cin, temp);
		cs.enqueue(temp);
	}
	std::cout << "Kolejka jest pelna, rozpoczynamy przetwarzanie\n";
	while (!cs.isempty())
	{
		cs.dequeue(temp);
		std::cout << "Teraz obslugujemy: " << temp << std::endl;
	}
	return 0;
}