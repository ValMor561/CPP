#include <iostream>
#include "../../Libs/include/Secret.h"

int main()
{
    setlocale(LC_ALL, ".OCP");
    Secret a;
    for (int i = 0;; ++i)
    {
        std::string code = a.GetSecret(i);
        if (code.rfind("секретное") != -1)
        {
            std::cout << i << '\n';
        }
    }
    return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Secret a;
	std::string code = a.GetSecret(125465809);
	if (code.rfind("секретное") != -1)
		std::cout << code;
	
	return 0;
}
int main()
{
	return 0;
}