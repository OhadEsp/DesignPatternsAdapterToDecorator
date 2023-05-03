#pragma once
#include <string>
#include <list>

#include "MovieData.h"

class MovieGroup : public MovieInfo
{
	std::string title_;
	std::list<MovieInfo*> movie_info_;

public:
	MovieGroup(std::string title): title_(std::move(title))
	{
	}

	void Add(MovieInfo& movie_info)
	{
		movie_info_.push_back(&movie_info);
	}

	void Remove(MovieInfo& movie_info)
	{
		movie_info_.remove(&movie_info);
	}
		
	unsigned GetTotalViewingTime() const override
	{
		unsigned int total_viewing_time = 0;
		for(auto movie_info : movie_info_)
		{
			total_viewing_time += movie_info->GetTotalViewingTime();
		}

		return total_viewing_time;
	}

	const MovieData* GetMovieWithHighestScore() const override
	{
		const MovieData* current_highest = nullptr;
		for (auto movie_info : movie_info_)
		{
			const auto temp_highest = movie_info->GetMovieWithHighestScore();
			if(temp_highest != nullptr)
			{
				if(current_highest == nullptr || current_highest->GetScore() < temp_highest->GetScore())
				{
					current_highest = temp_highest;
				}
			}
		}

		return current_highest;
	}
};