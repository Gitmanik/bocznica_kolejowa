/*
Seria wagonów generowana w osobnym w¹tku (std::thread i std::ref)
*/

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <cctype>
#include <conio.h>

#include "siding.hpp"
#include "track.hpp"

void draw_screen(Siding* siding)
{
	system("cls");
	std::cout << "Bocznica kolejowa - Techniki Programowania - Pawel Reich, Mateusz Wizner" << std::endl;
	siding->print_siding();
}

int main()
{
	Siding* siding = new Siding(5);

	while (true)
	{
		draw_screen(siding);
		char c = tolower(_getch());

		if (c == 'q')
			break;

		bool continue_game = siding->parse_input(c);
		if (continue_game)
		{
			draw_screen(siding);
			std::cout << "Koniec gry! Wcisnij dowolny przycisk aby rozpoczac nowa rozgrywke.";
			_getch();
			delete siding;
			siding = new Siding(5);
		}
	}

	delete siding;
}