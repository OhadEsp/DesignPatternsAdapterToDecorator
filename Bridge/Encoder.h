﻿#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include "MovieData.h"

class Encoder
{
public:
	virtual ~Encoder() = default;
	virtual std::string Encode(const MovieData movie_data) = 0;
};

class PlainTextEncoder : public Encoder
{
public:
	std::string Encode(const MovieData movie_data) override
	{
		std::stringstream sstream;
		sstream << "Id: " << movie_data.GetImdbId() << std::endl;
		sstream << "Title: " << movie_data.GetTitle() << std::endl;
		sstream << "Length: " << movie_data.GetLengthMin() << std::endl << std::endl;

		return sstream.str();
	}
};

class JsonEncoder : public Encoder
{
public:
	std::string Encode(const MovieData movie_data) override
	{
		rapidjson::StringBuffer string_buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(string_buffer);
		writer.StartObject();
		writer.Key("Id");
		writer.String(movie_data.GetImdbId().c_str());

		writer.Key("Title");
		writer.String(movie_data.GetTitle().c_str());

		writer.Key("Length");
		writer.Uint(movie_data.GetLengthMin());

		writer.EndObject();

		return string_buffer.GetString();
	}
};
