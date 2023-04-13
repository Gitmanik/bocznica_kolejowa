#pragma once

#include <vector>
#include "track.hpp"

class Siding
{
    public:
        Siding(size_t track_count);
        ~Siding();

        std::vector<Track*> Tracks;
        int Points;
        std::string Queue;

        void print_siding();
        void generate_data();
};