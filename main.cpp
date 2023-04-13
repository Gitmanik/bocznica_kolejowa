/*
Seria wagonów generowana w osobnym wątku (std::thread i std::ref)
*/

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

#include "siding.hpp"
#include "track.hpp"

int main()
{
    std::cout << "Bocznica kolejowa" << std::endl;

    Siding siding;

    //TODO: Randomize
    std::string queue = "ABCCDCBA";

    for (size_t idx = 0; idx < 5; idx++)
        siding.Tracks.push_back(new Track());

    siding.Tracks.at(0)->Current = "BB";
    siding.Tracks.at(0)->Target = "AABB";

    siding.Tracks.at(1)->Current = "B";
    siding.Tracks.at(1)->Target = "ABAB";

    siding.Tracks.at(2)->Current = "D";
    siding.Tracks.at(2)->Target = "CDD";

    siding.Tracks.at(3)->Current = "";
    siding.Tracks.at(3)->Target = "ABBC";

    siding.Tracks.at(4)->Current = "DD";
    siding.Tracks.at(4)->Target = "CDD";


    while (true)
    {
        std::cout << "Wybierz akcje" << std::endl;
        char c;
        std::cin >> c;
    }
}