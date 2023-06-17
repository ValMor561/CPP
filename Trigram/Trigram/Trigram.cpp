#include "pch.h"
#include "Trigram.h"
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

ToLower::ToLower()
{
	for (int i = 0; i < 256; ++i)
	{
		_table[unsigned char(i)] = tolower(i, locale("Russian"));
	}
}

char ToLower::operator()(char ch)
{
	return _table[(unsigned char)ch];
}

string FileToStr(const string filename)
{
	ifstream fs(filename, ios::binary);
	if (!fs)
		throw runtime_error("no such file");
	fs.seekg(0, fs.end);
	long size = fs.tellg();
	fs.seekg(0, fs.beg);
	char* buffer = new char[size + 1];
	fs.read(buffer, size);
	fs.close();
	string str;
	str = buffer;
	return str;
}

void TransformDelim(string& str, string& delim)
{
	for (int i = 0; i < str.size();)
	{

		if (delim.find(str[i]) == delim.npos)
			++i;
		else
		{
			str[i] = ' ';
			++i;
			while (delim.find(str[i]) != delim.npos)
			{
				str.erase(i, 1);
			}
		}
	}
}

TrigramsStorage::TrigramsStorage(string& alphabet)
	:_alphabet(alphabet), _storage(),_countTrigrams(0)
{

}

void TrigramsStorage::AddTrigramIfSuit(string& trigram)
{
	bool isItInAlphabet = true;
	for (int i = 0; i < trigram.size(); ++i)
	{
		trigram[i] = lower(trigram[i]);
		if (_alphabet.find(trigram[i]) != _alphabet.npos)
		{
			isItInAlphabet = false;
			break;
		}
	}
	if (isItInAlphabet)
	{
		++_storage[trigram];
		++_countTrigrams;
	}
}

vector<pair<string, int>> TrigramsStorage::GetMostPopularTrigrams(int count)
{
	vector<std::pair<string, int>> sortStorage;
	copy(_storage.begin(), _storage.end(), back_inserter(sortStorage));
	sort(sortStorage.begin(), sortStorage.end(), [=](pair<string, int>& a, pair<string, int>& b) { return a.second > b.second; });
	if (count == 0)
		return sortStorage;
	sortStorage.erase(sortStorage.cbegin() + count, sortStorage.cend());
	return sortStorage;
}

vector<pair<string, double>> TrigramsStorage::GetTrigramsWithRatioBiggerThat(double limit)
{
	vector<pair<string, double>> sortStorage;
	for (auto iter = _storage.begin(); iter != _storage.end(); ++iter)
	{
		pair<string, double> trigram = *iter;
		trigram.second = (trigram.second / _countTrigrams) * 100;
		if (trigram.second > limit)
			sortStorage.push_back(trigram);
	}
	sort(sortStorage.begin(), sortStorage.end(), [=](pair<string, double>& a, pair<string, double>& b) { return a.second > b.second; });
	return sortStorage;
}

void ProcessText(const string& text, vector<TrigramsStorage>& storages)
{
	string str = FileToStr(text);
	string delim = " -_.,~`|!?@#$№%^°є&*()+=?/\{}[]\n><\t\r';:";
	TransformDelim(str, delim);
	string sub;
	for (int i = 0; i + 2 < str.size(); ++i)
	{
		sub = str.substr(i, 3);
		for (int j = 0; j < storages.size(); ++j)
		{
			storages[j].AddTrigramIfSuit(sub);
		}
	}
}
