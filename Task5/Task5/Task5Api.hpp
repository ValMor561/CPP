#pragma once
#include "pch.h"
#ifdef TASK5_EXPORTS
#define TASK5_API __declspec(dllexport)
#else
#define TASK5_API __declspec(dllimport)
#endif