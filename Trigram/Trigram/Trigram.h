#pragma once
#include "TaskApi.hpp"
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ToLower
{
public:
	TRIGRAM_API ToLower();
	TRIGRAM_API char operator()(char ch);
private:
	char _table[256];
};

class TrigramsStorage
{
public:
	TRIGRAM_API TrigramsStorage() = default;
	TRIGRAM_API TrigramsStorage(string& alphabet);
	TRIGRAM_API void AddTrigramIfSuit(string& trigram);
	TRIGRAM_API vector<pair<string, int>> GetMostPopularTrigrams(int count);
	TRIGRAM_API vector<pair<string, double>> GetTrigramsWithRatioBiggerThat(double count);
private:
	string _alphabet;
	int _countTrigrams;
	map<string, int> _storage;
	ToLower lower;
};


TRIGRAM_API void ProcessText(const string& text, vector<TrigramsStorage>& storages);

// В тестах, соответственно, создаете 1 или больше хранилищ и с ними вызываете метод ProcessText
// Для получения статистики вызываете методы GetMostPopularTrigrams/GetTrigramsWithRatioBiggerThat