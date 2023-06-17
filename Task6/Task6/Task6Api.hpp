#pragma once
#ifdef TASK6_EXPORTS
#define TASK6_API __declspec(dllexport)
#else 
#define TASK6_API __declspec(dllimport)
#endif