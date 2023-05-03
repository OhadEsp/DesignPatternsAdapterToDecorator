#include <iostream>

#include "MovieGroup.h"

int main()
{
	MovieGroup action_movies("Action");
	MovieGroup military_action_movies("Military Action");
	MovieGroup martial_arts_movies("Martial Arts");
	action_movies.Add(military_action_movies);
	action_movies.Add(martial_arts_movies);

	MovieData movie_1("Generic racing movie #3", 120, 6);
	MovieData movie_2("Zombie movie remake", 80, 7);
	MovieData movie_3("Yet another war movie", 180, 9);
	MovieData movie_4("Dragon master 5", 90, 3);
	MovieData movie_5("Kendo kid 2", 46, 8);

	action_movies.Add(movie_1);
	action_movies.Add(movie_2);

	military_action_movies.Add(movie_3);

	martial_arts_movies.Add(movie_4);
	martial_arts_movies.Add(movie_5);

	/* Action
		|
		-> movie_1
		-> movie_2
		-> movie_3
		-> Military Action
			|
			-> movie_3
		-> Martial Arts
			|
			-> movie_4
			-> movie_5
	*/


	std::cout << "Total watching time: " << action_movies.GetTotalViewingTime() << std::endl;
	auto movie_with_highest_score = action_movies.GetMovieWithHighestScore();

	std::cout << "The movie with the highest score is: " << movie_with_highest_score->GetTitle()
		<< " score:" << movie_with_highest_score->GetScore() << std::endl;
	return 0;
}
