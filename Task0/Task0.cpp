#include <iostream>
#include "fstream"
using namespace std;

int main(int argc, char* argv[])
{
	char c = 'f';
	int k = (int)c ^ 5;
	cout << (char)k;
}