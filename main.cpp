/*
Seria wagonów generowana w osobnym wątku (std::thread i std::ref)
*/

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    std::cout << "Bocznica kolejowa" << std::endl;

    while(true)
    {
        std::cout << "Wybierz akcje" << std::endl;
        char c;
        std::cin >> c;
    }
}