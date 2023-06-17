#pragma once
#include "TaskApi.hpp"

class Student
{
public:
	TASK_API Student();
	TASK_API Student(char* name, int year, int* marks);
	TASK_API Student(const Student& other);
	TASK_API Student(Student&& other) noexcept;
	TASK_API ~Student();

	TASK_API Student& operator=(const Student& other);
	TASK_API Student& operator=(Student&& other) noexcept;

	TASK_API char* GetSecondName();
	TASK_API int GetYear();
	TASK_API int* GetMarks();

private:
	char* _secondName;
	int _year;
	int* _marks;
};

class IStudentProcessor : public Student
{
	~IStudentProcessor();
	virtual void Process(Student& student) = 0;
};

class AverageAgeProccessor : public IStudentProcessor
{
public:
	AverageAgeProccessor();
	~AverageAgeProccessor();
	void ProcessStudents(Student *group, size_t count);
	void Process(Student& student);
	double CalculateAverageAge(Student *group, size_t count);
	double GetAverageAgeStudent() const;
private:
	int _count;
	int _age;
	double _averageAge;
};

class AverageMarkProccessor : public IStudentProcessor
{
public:
	//void ProcessStudents(Student *group, size_t count, IStudentProcessor& processor);
	void Process(Student& student);
	double CalculateAverageMark(Student *group, size_t count);
	double GetAverageMarkStudent() const;
private:
	int _count;
	int _mark;
	double _averageMark;
};