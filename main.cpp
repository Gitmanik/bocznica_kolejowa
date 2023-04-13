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

    // TODO: Remove this.
    siding->print_siding();
    return 0;

    while (true)
    {
        char c;
        std::cin >> c;

    c = tolower(c);

    //TODO: Remove this
    if (c == 'p')
        siding->print_siding();

    if (c == 'q')
        break;
    }

    delete siding;
}