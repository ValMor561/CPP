#include "pch.h"
#include "IMilitaryMan.h"

int IMilitaryMan::_count = 0;

Soldier::Soldier()
	:_jobCount(0)
{
	++_count;
}

Soldier::~Soldier()
{
	_jobCount = 0;
	--_count;
}

void Soldier::Serve()
{
	++_jobCount;
}

int Soldier::GetJob() const
{
	return _jobCount;
}

Officer::Officer(IMilitaryMan ** arr, int count)
	:_data(arr),_countSoldier(count)
{ 
	++_count;
}

void Officer::Serve()
{
	for (int i = 0; i < _countSoldier; ++i)
		_data[i]->Serve();
}

Officer::~Officer()
{
	_countSoldier = 0;
	--_count;
	delete[] _data;
}

int IMilitaryMan::GetCount() const
{
	return _count;
}
