#include "StringUtil.h"

int main()
{
	char testString[5] = "Real";
	String mainString = String("Real");

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Length() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	size_t length = mainString.Length();

	std::cout << 4 << " | " << length << std::endl;
	if (length != 4)
	{
		std::cout << "Length is not correct!" << std::endl;
	}
	else
	{
		std::cout << "Length is correct!" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String CharacterAt() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	for (size_t i = 0; i < mainString.Length(); i++)
	{
		if (mainString[i] != testString[i])
		{
			std::cout << "Character at index " << i << " is wrong!" << std::endl;
		}
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String EqualTo() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (mainString.EqualTo("Real"))
	{
		std::cout << "Should be true" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Append() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.Append("Real");

	std::cout << mainString.CStr() << std::endl;

	if (mainString.EqualTo("RealReal"))
	{
		
	}
}