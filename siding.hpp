#pragma once

#include <vector>
#include "track.hpp"

class Siding
{
    public:
        std::vector<Track*> Tracks;
        int Points;
        void print_siding();
};