#pragma once
#include "MovieSerializer.h"

class FileMovieSerializer : public MovieSerializer
{
	std::string root_dir_;
public:
	FileMovieSerializer(std::string root_dir) : root_dir_(std::move(root_dir)){}
	void WriteMovieDetails(const MovieData& movie_data) override;
};

