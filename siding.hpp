#pragma once

#include <vector>
#include "track.hpp"

class Siding
{
public:
	Siding(size_t track_count);
	~Siding();

	void print_siding();
	bool should_continue_game();
	bool parse_input(char input);

private:
	void generate_track_data();
	void release_wagon();
	char rand_letter();
	void assign_points(unsigned int target_track);
	int Points;
	size_t QueueStartLength;
	std::string Queue;
	std::vector<Track*> Tracks;
	std::vector<bool> Crossings;
};