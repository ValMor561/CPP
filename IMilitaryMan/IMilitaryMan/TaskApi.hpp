#pragma once
#ifdef IMILITARYMAN_EXPORTS
#define IMILITARYMAN_API __declspec(dllexport)
#else
#define IMILITARYMAN_API __declspec(dllimport)
#endif