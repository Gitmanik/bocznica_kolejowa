#include "siding.hpp"
#include <iostream>
#include <thread>
#include <ctime>
#include <algorithm>
#include <random>
#include <functional>
#include <utility>

Siding::Siding(size_t track_count)
{
	for (size_t idx = 0; idx < track_count; idx++)
	{
		Tracks.push_back(new Track());
		if (idx != 0)
			Crossings.push_back(true);
	}

	std::thread tracks_thread(&Siding::generate_track_data, this);
	tracks_thread.join();

	Points = 0;
	QueueStartLength = Queue.length();
}

Siding::~Siding()
{
	for (auto track : Tracks)
	{
		delete track;
	}
}

char Siding::rand_letter() {
	char letters[] = { 'A', 'B', 'C', 'D' };

	int id = std::rand() % 4;
	char rand_letter = letters[id];
	return rand_letter;
}

void Siding::generate_track_data()
{
	std::srand(std::time(nullptr));

	Queue = "";
	for (int i = 0; i < Tracks.size(); i++) {
		int num = std::rand() % 2 + 3;

		for (int j = 0; j < num; j++) {
			char random = rand_letter();
			Tracks.at(i)->Target.push_back(random);
			Queue.push_back(random);
		}
	}
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(Queue.begin(), Queue.end(), g);
}

void Siding::print_siding()
{
	int big_padding = 40;
	int small_padding = 9;

	int pad_counter = 0;

	std::cout << "Punkty: " << Points << std::endl;

	std::cout << Queue << std::string(QueueStartLength - Queue.length() + 1, ' ') << std::string(small_padding, '=');
	for (auto track_iter = Tracks.begin(); track_iter < Tracks.end(); track_iter++)
	{
		size_t track_index = track_iter - Tracks.begin();
		Track track_current = **track_iter;

		if (track_index != 0)
		{
			std::cout << std::string(QueueStartLength + small_padding + pad_counter++, ' ');
			std::cout << (Crossings.at(track_index - 1) ? "\\\\" : "  ");
			std::cout << " (" << track_index + 1 << ")" << std::endl;

			std::cout << std::string(QueueStartLength + small_padding + pad_counter++, ' ') << "\\\\";
		}

		std::cout << std::string(big_padding - track_current.Current.length() - pad_counter, '=');
		std::cout << track_current.Current << " " << "Tor " << track_index + 1 << ": " << "[" << track_current.Target << "]" << std::endl;
	}
}

bool Siding::parse_input(char input)
{
	switch (input)
	{
	case '2':
		Crossings.at(0) = !Crossings.at(0);
		break;

	case '3':
		Crossings.at(1) = !Crossings.at(1);
		break;

	case '4':
		Crossings.at(2) = !Crossings.at(2);
		break;

	case '5':
		Crossings.at(3) = !Crossings.at(3);
		break;

	case 'w':
		release_wagon();
		break;

	default:
		break;
	}
	return !should_continue_game();
}

bool Siding::should_continue_game()
{
	return !(Points == 50 || Points < 0 || Queue.length() == 0);
}

void Siding::release_wagon()
{
	char wagon = Queue.at(Queue.length() - 1);
	Queue.pop_back();

	unsigned int target_track = 0;
	for (target_track; target_track < Crossings.size(); target_track++)
	{
		if (!Crossings.at(target_track))
			break;
	}

	std::cout << target_track << std::endl;
	Tracks.at(target_track)->Current.insert(0, std::string(1, wagon));

	assign_points(target_track);
}

void Siding::assign_points(unsigned int target_track)
{
	Track track = *Tracks.at(target_track);

	if (track.Current == track.Target)
	{
		Points += 10;
		return;
	}
	int max = std::min(track.Target.length(), track.Current.length());
	for (int idx = 0; idx < max; idx++)
	{
		if (track.Target.at(track.Target.length() - idx - 1) != track.Current.at(track.Current.length() - idx - 1))
		{
			Points -= 10;
			break;
		}
	}
}