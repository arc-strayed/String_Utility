#include "StringUtil.h"

int main()
{
	char testString[5] = "Real";
	String mainString = String("Real");

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Length() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	size_t length = mainString.Length();

	if (length == 4)
	{
		std::cout << "[Length() test] good" << std::endl;
	}
	else
	{
		std::cout << "[Length() test] bad" << 4 << "|" << length << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String CharacterAt() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	bool charIsNotTheSame = false;

	for (size_t i = 0; i < mainString.Length(); i++)
	{
		if (mainString[i] != testString[i])
		{
			charIsNotTheSame = true;
		}
	}

	if (!charIsNotTheSame)
	{
		std::cout << "[CharacterAt() test] good" << std::endl;
	}
	else
	{
		std::cout << "[CharacterAt() test] bad" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String EqualTo() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (mainString.EqualTo("Real") == true)
	{
		std::cout << "[EqualTo() test] good" << std::endl;
	}
	else
	{
		std::cout << "[EqualTo() test] bad" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Append() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.Append("Real");

	if (mainString.EqualTo("RealReal") == true)
	{
		std::cout << "[Append() test] good" << std::endl;
	}
	else
	{
		std::cout << "[Append() test] bad (" << mainString.CStr() << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Prepend() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.Prepend("Strong");

	if (mainString.EqualTo("StrongRealReal") == true)
	{
		std::cout << "[Prepend() test] good" << std::endl;
	}
	else
	{
		std::cout << "[Prepend() test] bad (" << mainString.CStr() << ")" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String CStr() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if ((mainString.CStr() == "StrongRealReal") == 0)
	{
		std::cout << "[CStr() test] good" << std::endl;
	}
	else
	{
		std::cout << "[CStr() test] bad (" << mainString.CStr() << ")" << std::endl;
	}
}