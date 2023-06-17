#pragma once
#ifdef TASK13_EXPORTS
#define TASK13_API __declspec(dllexport)
#else 
#define TASK13_API __declspec(dllimport)
#endif