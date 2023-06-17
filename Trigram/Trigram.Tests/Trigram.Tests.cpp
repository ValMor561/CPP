#include "pch.h"
#include "../Trigram/Trigram.h"

TEST(TrigramStorageTests, Test1)
{
	setlocale(LC_ALL, "rus");
	std::string alphabet_English = "qwertyuiopasdfghjklzxcvbnm1234567890";
	std::string alphabet_Russian = "יצףךוםדרשחץתפûגאןנמכהז‎ÿקסלטעüב‏¸1234567890";
	TrigramsStorage eng(alphabet_English);
	TrigramsStorage rus(alphabet_Russian);
	std::vector<TrigramsStorage> storages;
	storages.push_back(eng);
	storages.push_back(rus);
	ProcessText("Text.txt", storages);
	for (int i = 0; i < storages.size(); ++i)
	{
		auto res = storages[i].GetMostPopularTrigrams(20);
		for (int j = 0; j < res.size(); ++j)
		{
			std::cout << res[j].first << " " << res[j].second << std::endl;
		}
		std::cout << '\n';
	}
}

TEST(TrigramStorageTests, Test2)
{
	setlocale(LC_ALL, "rus");
	std::string alphabet_English = "qwertyuiopasdfghjklzxcvbnm1234567890";
	std::string alphabet_Russian = "יצףךוםדרשחץתפûגאןנמכהז‎ÿקסלטעüב‏¸1234567890";
	TrigramsStorage eng(alphabet_English);
	TrigramsStorage rus(alphabet_Russian);
	std::vector<TrigramsStorage> storages;
	storages.push_back(eng);
	storages.push_back(rus);
	ProcessText("Text.txt", storages);
	for (int i = 0; i < storages.size(); ++i)
	{
		auto res = storages[i].GetTrigramsWithRatioBiggerThat(0.5);
		for (int j = 0; j < res.size(); ++j)
		{
			std::cout << setprecision(3) << res[j].first << " " << res[j].second << '%' << std::endl;
		}
		std::cout << '\n';
	}
}