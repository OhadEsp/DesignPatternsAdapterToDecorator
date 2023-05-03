#pragma once
#include <memory>
#include <string>

#include "MovieData.h"
#include "MovieDbRepository.h"
#include "TheMovieDbApi.h"

class MovieApiAdapter : public MovieRepository
{
	MovieApi& api_;

public:
	explicit MovieApiAdapter(MovieApi& api)
		: api_(api)
	{
	}

private:
	std::string GetMatchingTitleIdFromMovieList(const std::string& title, const std::string& json_string) const;

public:
	std::shared_ptr<MovieData> GetById(const std::string& movie_id) override;
};
