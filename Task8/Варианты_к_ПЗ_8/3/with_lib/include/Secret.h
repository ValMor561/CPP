#pragma once
#include "SecretDllApi.hpp"

#include <string>

class Secret
{
public:
	SECRETDLL_API std::string GetSecret(int key) const;
};
