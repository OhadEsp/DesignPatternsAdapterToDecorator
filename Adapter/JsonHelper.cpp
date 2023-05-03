#include "JsonHelper.h"
#include "InvalidInputException.h"
#include "MovieNotFoundException.h"
#include "rapidjson/document.h"

static const rapidjson::Value& FindMovieByTitle(const std::string& title, rapidjson::GenericValue<rapidjson::UTF8<>>::Array results)
{
	size_t selectedIndex = 0;
	if (results.Size() > 1)
	{
		for (size_t i = 0; i < results.Size(); ++i)
		{
			auto movieTitle = results[i]["title"].GetString();
			if (std::strcmp(movieTitle, title.c_str()) == 0)
			{
				selectedIndex = i;
				break;
			}
		}
	}
	return results[selectedIndex];
}


