#include "siding.hpp"

Siding::Siding(size_t track_count)
{
    for (size_t idx = 0; idx < track_count; idx++)
        Tracks.push_back(new Track());

    //TODO: Multi-thread
    generate_data();
}

Siding::~Siding()
{
    for (auto track = Tracks.begin(); track < Tracks.end(); track++)
    {
        delete *track;
    }
}

void Siding::generate_data()
{
    //TODO: Randomize
    std::string queue = "ABCCDCBA";

    Tracks.at(0)->Current = "BB";
    Tracks.at(0)->Target = "AABB";

    Tracks.at(1)->Current = "B";
    Tracks.at(1)->Target = "ABAB";

    Tracks.at(2)->Current = "D";
    Tracks.at(2)->Target = "CDD";

    Tracks.at(3)->Current = "";
    Tracks.at(3)->Target = "ABBC";

    Tracks.at(4)->Current = "DD";
    Tracks.at(4)->Target = "CDD";
}