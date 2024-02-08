#include <iostream>
#include <cstring>

int main()
{
	char* buffer = new char[32];

	strcpy_s(buffer, 32 * sizeof(char), "Breal");

	char* charPtr = strstr(buffer, "real");

	if (charPtr == nullptr)
	{
		std::cout << "String is nullptr" << std::endl;
	}
	else
	{
		std::cout << charPtr << std::endl;
	}

	delete[] buffer;
}