/*
Seria wagonów generowana w osobnym wątku (std::thread i std::ref)
*/

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <cctype>

#include "siding.hpp"
#include "track.hpp"

int main()
{
    std::cout << "Bocznica kolejowa" << std::endl;

    Siding* siding = new Siding(5); 

    while (true)
    {
        std::cout << "" << std::endl;
        char c;
        std::cin >> c;

    c = tolower(c);

    if (c == 'q')
        break;
    }

    delete siding;
}