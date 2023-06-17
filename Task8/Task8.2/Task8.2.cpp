#include <iostream>
#include <windows.h>
#include <climits>

typedef std::string(*UgLNMtnmxNEEType)(int);

int main()
{
	setlocale(LC_ALL, "ru");
	//setlocale(0, "");
	HMODULE hMoreSecretDLLLib = LoadLibrary(L"MoreSecretDLL.dll");

	UgLNMtnmxNEEType UgLNMtnmxNEE = reinterpret_cast<UgLNMtnmxNEEType>(GetProcAddress(hMoreSecretDLLLib, "UgLNMtnmxNEE"));

	for (int i = 0; i <= INT_MAX; ++i)
	{
		std::string res = UgLNMtnmxNEE(i);
		if (res.find("секретное") != -1)
		{
			std::cout << res << '\t' << i;
			system("pause");
		}
	}
}