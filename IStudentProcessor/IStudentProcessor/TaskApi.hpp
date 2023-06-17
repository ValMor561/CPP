#pragma once
#ifdef TASK_EXPORTS
#define TASK_API __declspec(dllexport)
#else
#define TASK_API __declspec(dllimport)
#endif