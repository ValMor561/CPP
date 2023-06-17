#pragma once

#ifdef SECRETDLL_EXPORTS
	#define SECRETDLL_API __declspec(dllexport)
#else
	#define SECRETDLL_API __declspec(dllimport)
#endif
