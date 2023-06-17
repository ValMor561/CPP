#pragma once
#ifdef TRIGRAM_EXPORTS
#define TRIGRAM_API __declspec(dllexport)
#else
#define TRIGRAM_API __declspec(dllimport)
#endif