#pragma once
#ifdef TASK10_EXPORTS
#define TASK10_API __declspec(dllexport)
#else
#define TASK10_API __declspec(dllimport)
#endif