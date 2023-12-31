#include "pch.h"
#include "IStudentProccessor.h"


Student::Student()
	:_secondName(nullptr),_year(0),_marks(nullptr)
{
}

Student::Student(char * name, int year, int * marks)
{
	_secondName = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name) + 1; ++i)
	{
		_secondName[i] = name[i];
	}
	_year = year;
	_marks = new int[5];
	for (int i = 0; i < 5; ++i)
		_marks[i] = marks[i];
}

Student::Student(const Student & other)
	: _secondName(nullptr), _year(0), _marks(nullptr)
{
	_secondName = new char[strlen(other._secondName) + 1];
	for (int i = 0; i < strlen(other._secondName); ++i)
	{
		_secondName[i] = other._secondName[i];
	}
	_year = other._year;
	_marks = new int[5];
	for (int i = 0; i < 5; ++i)
		_marks[i] = other._marks[i];
}

Student::Student(Student && other) noexcept
	: _secondName(other._secondName), _year(other._year), _marks(other._marks)
{
	other._secondName = nullptr;
	other._year = 0;
	other._marks = nullptr;
}

Student::~Student()
{
	delete[] _secondName;
	delete[] _marks;
}

Student& Student::operator=(const Student & other)
{
	if (this == &other)
		return *this;
	delete[] _secondName;

	_secondName = new char[strlen(other._secondName) + 1];
	for (int i = 0; i < strlen(other._secondName) + 1; ++i)
	{
		_secondName[i] = other._secondName[i];
	}
	_year = other._year;
	_marks = new int[5];
	for (int i = 0; i < 5; ++i)
		_marks[i] = other._marks[i];

	return *this;
}

Student & Student::operator=(Student && other) noexcept
{
	if (this == &other)
		return *this;
	delete[] _secondName;

	_secondName = other._secondName;
	
	_year = other._year;
	_marks = other._marks;
	other._secondName = nullptr;
	other._year = 0;
	other._marks = nullptr;
	return *this;
}

char * Student::GetSecondName()
{
	return _secondName;
}

int Student::GetYear()
{
	return _year;
}

int * Student::GetMarks()
{
	return _marks;
}

IStudentProcessor::~IStudentProcessor()
{
}


AverageAgeProccessor::AverageAgeProccessor()
	:_age(0),_count(0),_averageAge(0)
{
}

AverageAgeProccessor::~AverageAgeProccessor()
{
}

void AverageAgeProccessor::ProcessStudents(Student* group, size_t count)
{
	for (int i = 0; i < count; ++i)
	{
		this->Process(group[i]);
	}
}

void AverageAgeProccessor::Process(Student& student)
{
	_age += 2020 - student.GetYear();
	_count += 1;
}

double AverageAgeProccessor::CalculateAverageAge(Student * group, size_t count)
{
	for (int i = 0; i < count; ++i)
	{
		Process(group[i]);
	}
	_averageAge = _age / _count;
	return _averageAge;
}

double AverageAgeProccessor::GetAverageAgeStudent() const
{
	return _averageAge;
}

void AverageMarkProccessor::Process(Student & student)
{
	int mark = 0;
	for (int i = 0; i < 5; ++i)
	{
		mark += student.GetMarks()[i];
	}
	_mark += mark;
	_count += 1;
}

double AverageMarkProccessor::CalculateAverageMark(Student* group, size_t count)
{
	for (int i = 0; i < count; ++i)
	{
		Process(group[i]);
	}
	_averageMark = _mark / _count;
	return _averageMark;
}

double AverageMarkProccessor::GetAverageMarkStudent() const
{
	return _averageMark;
}
