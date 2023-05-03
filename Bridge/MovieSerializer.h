#pragma once

#include "MovieData.h"
#include "Encoder.h"
#include <fstream>
#include <utility>

class MovieSerializer
{
	Encoder& encoder_;

protected:
	virtual void SaveDetails(const MovieData& movie_data, const std::string& data) = 0;

public:
	explicit MovieSerializer(Encoder& encoder)
		: encoder_(encoder)
	{
	}

	virtual ~MovieSerializer() = default;
	
	void WriteMovieDetails(const MovieData& movie_data)
	{
		const auto encoded_string = encoder_.Encode(movie_data);

		SaveDetails(movie_data, encoded_string);
	};
};

class ConsoleMovieSerializer : public MovieSerializer
{
public:
	ConsoleMovieSerializer(Encoder& encoder)
		: MovieSerializer(encoder)
	{
	}

protected:
	void SaveDetails(const MovieData& movie_data, const std::string& data) override
	{
		std::cout << data << std::endl;
	}
};

class FileMovieSerializer : public MovieSerializer
{
	std::string root_dir_;

public:
	FileMovieSerializer(Encoder& encoder, std::string root_dir)
		: MovieSerializer(encoder),
		  root_dir_(std::move(root_dir))
	{
	}

protected:
	void SaveDetails(const MovieData& movie_data, const std::string& data) override
	{
		std::ofstream output(root_dir_ + "movie_" + movie_data.GetImdbId() + ".txt");

		output << data;
	}
};
