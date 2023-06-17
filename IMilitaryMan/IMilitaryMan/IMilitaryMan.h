#pragma once
#include "TaskApi.hpp"
#include <iostream>
class IMilitaryMan
{
public:
	virtual ~IMilitaryMan() {};
	virtual void Serve() = 0;
	IMILITARYMAN_API int GetCount() const;
	IMILITARYMAN_API static int _count;
};


class Soldier :public IMilitaryMan
{
public:
	IMILITARYMAN_API Soldier();
	IMILITARYMAN_API virtual ~Soldier();
	IMILITARYMAN_API void Serve();
	IMILITARYMAN_API int GetJob() const;

private:
	int _jobCount;
};

class Officer :public IMilitaryMan
{
public:
	IMILITARYMAN_API Officer(IMilitaryMan **arr, int count);
	IMILITARYMAN_API void Serve();
	IMILITARYMAN_API virtual ~Officer();
private:
	IMilitaryMan** _data;
	int _countSoldier;
};