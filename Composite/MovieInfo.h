#pragma once

class MovieData;

class MovieInfo
{
public:
	virtual ~MovieInfo() = default;

	virtual unsigned GetTotalViewingTime() const = 0;
	virtual const MovieData* GetMovieWithHighestScore() const = 0;
};
