#include "StringUtil.h"

int main()
{
	char testString[5] = "Real";
	String mainString("Real");

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Length() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	size_t length = mainString.Length();

	if (length == 4)
	{
		std::cout << "[Length() test] success" << std::endl;
	}
	else
	{
		std::cout << "[Length() test] failure" << 4 << "|" << length << std::endl;
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
		std::cout << "[CharacterAt() test] success" << std::endl;
	}
	else
	{
		std::cout << "[CharacterAt() test] failure" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String EqualTo() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (mainString.EqualTo("Real") == true)
	{
		std::cout << "[EqualTo() test] success" << std::endl;
	}
	else
	{
		std::cout << "[EqualTo() test] failure" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Append() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.Append("Real");

	if (mainString.EqualTo("RealReal") == true)
	{
		std::cout << "[Append() test] success" << std::endl;
	}
	else
	{
		std::cout << "[Append() test] failure" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Prepend() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.Prepend("Strong");

	if (mainString.EqualTo("StrongRealReal") == true)
	{
		std::cout << "[Prepend() test] success" << std::endl;
	}
	else
	{
		std::cout << "[Prepend() test] failure" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String CStr() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if ((mainString == mainString.CStr()) == true)
	{
		std::cout << "[CStr() test] success" << std::endl;
	}
	else
	{
		std::cout << "[CStr() test] failure" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String ToLower() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.ToLower();

	if ((mainString == "strongrealreal") == true)
	{
		std::cout << "[ToLower() test] success" << std::endl;
	}
	else
	{
		std::cout << "[ToLower() test] failure" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String ToUpper() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.ToUpper();

	if ((mainString == "STRONGREALREAL") == true)
	{
		std::cout << "[ToUpper() test] success" << std::endl;
	}
	else
	{
		std::cout << "[ToUpper() test] failure" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Find() test 1
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Find() test 2
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Replace() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String ReadFromConsole() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	String originalString = mainString;

	std::cout << "[Enter a string]: ";
	mainString.ReadFromConsole();

	if (mainString.EqualTo(originalString) == true)
	{
		std::cout << "[ReadFromConsole() test] failure" << std::endl;
	}
	else
	{
		std::cout << "[ReadFromConsole() test] success" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String WriteToConsole() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.WriteToConsole();

	std::cout << "[WriteToConsole() test] success" << std::endl;
}