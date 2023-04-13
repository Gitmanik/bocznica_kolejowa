/*
Seria wagonów generowana w osobnym wątku (std::thread i std::ref)
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

//TODO: Move to track.cpp/track.hpp
class Track
{
    public:
        std::string Current;
        std::string Target;
};

//TODO: Move to siding.cpp/siding.hpp
class Siding
{
    public:
        std::vector<Track> Tracks;
        int Points;
        void print_siding();
};

int main()
{
    std::cout << "Bocznica kolejowa" << std::endl;

    Siding siding;


    //TODO: Randomize
    std::string queue = "ABCCDCBA";

    siding.Tracks.at(0).Current = "BB";
    siding.Tracks.at(0).Target = "AABB";

    siding.Tracks.at(1).Current = "B";
    siding.Tracks.at(1).Target = "ABAB";

    siding.Tracks.at(2).Current = "D";
    siding.Tracks.at(2).Target = "CDD";

    siding.Tracks.at(3).Current = "";
    siding.Tracks.at(3).Target = "ABBC";

    siding.Tracks.at(4).Current = "DD";
    siding.Tracks.at(4).Target = "CDD";


    while (true)
    {
        std::cout << "Wybierz akcje" << std::endl;
        char c;
        std::cin >> c;
    }
}