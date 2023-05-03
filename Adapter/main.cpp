
#include <iostream>

#include "api_key.h"
#include "FileBasedApi.h"
#include "MovieApiAdapter.h"
#include "TheMovieDbApi.h"

using namespace std;

void print_movie(const std::shared_ptr<MovieData> movie)
{
	std::cout << "Title: " << movie->GetTitle() << std::endl;
	std::cout << "IMDB Id: " << movie->GetImdbId() << std::endl << std::endl;
	std::cout << " --------------- Plot --------------" << std::endl;
	std::cout << movie->GetPlot() << std::endl << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Length (min.) " << movie->GetLengthMin() << std::endl << std::endl;
}

int main(int argc, char* argv[])
{
	TheMovieDbApi api(MY_API_KEY);
	MovieApiAdapter adapter1(api);

	auto movie = adapter1.GetById("141052");
	print_movie(movie);

	FileBasedApi fileApi(R"(..\Adapter\Data\)");
	MovieApiAdapter adapter2(fileApi);
	movie = adapter2.GetById("141052");
	print_movie(movie);
}