#include "siding.hpp"
#include <iostream>

Siding::Siding(size_t track_count)
{
    for (size_t idx = 0; idx < track_count; idx++)
        Tracks.push_back(new Track());

    // TODO: Multi-thread
    generate_data();
}

Siding::~Siding()
{
    for (auto track : Tracks)
    {
        delete track;
    }
}

void Siding::generate_data()
{
    // TODO: Randomize
    Queue = "ABCCDCBA";

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

void Siding::print_siding()
{
    int big_padding = 40;
    int small_padding = 9;

    int pad_counter = 0;

    std::cout << Queue << " " << std::string(small_padding, '=');
    for (auto track_iter = Tracks.begin(); track_iter < Tracks.end(); track_iter++)
    {
        size_t track_index = track_iter - Tracks.begin();
        Track track_current = **track_iter;
            
        if (track_index != 0)
        {
            std::cout << std::string(Queue.length() + small_padding + pad_counter++, ' ') << "\\\\" << " (" << track_index+1 << ")" << std::endl;
            std::cout << std::string(Queue.length() + small_padding + pad_counter++, ' ') << "\\\\";
        }

        std::cout << std::string(big_padding - track_current.Current.length() - pad_counter, '=');
        std::cout << track_current.Current << " " << "Tor " << track_index + 1<< ": " << "[" << track_current.Target << "]" << std::endl;
    }
}