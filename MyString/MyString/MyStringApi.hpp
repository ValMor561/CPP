#pragma once

#ifdef MYSTRING_EXPORTS
	#define MYSTRING_API _declspec(dllexport)
#else
	#define MYSTRING_API _declspec(dllimport)
#endif // MYSTING_EXPORTS
