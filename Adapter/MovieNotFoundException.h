#pragma once

#include <exception>
#include <string>

class MovieNotFoundException : public std::exception
{
	const std::string movie_name_;

public:
	MovieNotFoundException(const std::string& movie_name) : movie_name_(movie_name) {}
	std::string GetMovieName() const { return movie_name_; }
};