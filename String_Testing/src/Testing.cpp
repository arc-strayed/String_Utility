#include <iostream>
#include "StringUtil.h"

/*
 *	String utility testing app
 */

int main()
{
	std::cout << "~~~~~~~~~~ P = pass, X = failure ~~~~~~~~~~\n";

	String mainString = String("Real");

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Length() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	size_t length = mainString.Length();

	if (length == 4)
	{
		std::cout << "[Length() test] P" << std::endl;
	}
	else
	{
		std::cout << "[Length() test] X" << 4 << "|" << length << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String CharacterAt() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	char compare_char = mainString.CharacterAt(0);

	if ((compare_char == 'R') == true)
	{
		std::cout << "[CharacterAt() test] P" << std::endl;
	}
	else
	{
		std::cout << "[CharacterAt() test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String EqualTo() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (mainString.EqualTo("Real") == true)
	{
		std::cout << "[EqualTo() test] P" << std::endl;
	}
	else
	{
		std::cout << "[EqualTo() test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Append() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.Append("Real");

	if (mainString.EqualTo("RealReal"))
	{
		std::cout << "[Append() test] P" << std::endl;
	}
	else
	{
		std::cout << "[Append() test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Prepend() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.Prepend("Strong");

	if (mainString.EqualTo("StrongRealReal"))
	{
		std::cout << "[Prepend() test] P" << std::endl;
	}
	else
	{
		std::cout << "[Prepend() test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String CStr() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (std::cout << mainString.CStr() << std::endl)
	{
		std::cout << "[CStr() test] P" << std::endl;
	}
	else
	{
		std::cout << "[CStr() test] X" << std::endl;
	}
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String ToLower() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.ToLower();

	bool isStringLower = true;
	String& mainString_ref = mainString;
	
	// Check if every character is lowercase
	for (size_t i = 0; i < mainString.Length(); i++)
	{
		if (std::islower(mainString_ref[i]) == 0)
		{
			isStringLower = false;
			break;
		}
	}

	if (isStringLower)
	{
		std::cout << "[ToLower() test] P" << std::endl;
	}
	else
	{
		std::cout << "[ToLower() test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String ToUpper() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	mainString.ToUpper();

	bool isStringUpper = true;

	// Check if every character is uppercase
	for (size_t i = 0; i < mainString.Length(); i++)
	{
		if (std::isupper(mainString_ref[i]) == 0)
		{
			isStringUpper = false;
			break;
		}
	}

	if (isStringUpper)
	{
		std::cout << "[ToUpper() test] P" << std::endl;
	}
	else
	{
		std::cout << "[ToUpper() test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Find() test 1
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	String stringToSearch = String("Bread");
	String stringToFind = String("ead");

	if (stringToSearch.Find(stringToFind) == 2)
	{
		std::cout << "[Find() test] P" << std::endl;
	}
	else
	{
		std::cout << "[Find() test] X" << std::endl;
		std::cout << stringToSearch.Find(stringToFind) << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Find() test 2
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	String anotherStringToSearch = String("BreadBread");
	String anotherStringToFind = String("ead");

	if (anotherStringToSearch.Find(5, anotherStringToFind) == 7)
	{
		std::cout << "[Find() test 2] P" << std::endl;
	}
	else
	{
		std::cout << "[Find() test 2] X" << std::endl;
		std::cout << anotherStringToSearch.Find(5, anotherStringToFind) << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String Replace() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	String stringToReplace = String("Bad Rad Sad");

	stringToReplace.Replace("ad", "aaad");

	if (stringToReplace.EqualTo("Baaad Raaad Saaad") == true)
	{
		std::cout << "[Replace() test] P" << std::endl;
	}
	else
	{
		std::cout << "[Replace() test] X" << std::endl;
		std::cout << "Actual Value   : " << stringToReplace.CStr() << std::endl;
		std::cout << "Reference value: Baaad Raaad Saaad\n";
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String ReadFromConsole() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	String originalString = String(mainString);

	std::cout << "[Enter a string]: ";
	mainString.ReadFromConsole();

	if (mainString.EqualTo(originalString) == false)
	{
		std::cout << "[ReadFromConsole() test] P" << std::endl;
	}
	else
	{
		std::cout << "[ReadFromConsole() test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String WriteToConsole() test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (mainString.WriteToConsole())
	{
		std::cout << "[WriteToConsole() test] P" << std::endl;
	}
	else
	{
		std::cout << "[WriteToConsole() test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String operator == test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	String stringCompare_1 = String("Same");
	String stringCompare_2 = String("Same");

	if (stringCompare_1 == stringCompare_2)
	{
		std::cout << "[Operator == test] P" << std::endl;
	}
	else
	{
		std::cout << "[Operator == test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String operator [] test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	char charAtIndex = stringCompare_1[0];

	if (charAtIndex == 'S')
	{
		std::cout << "[Operator [] test] P" << std::endl;
	}
	else
	{
		std::cout << "[Operator [] test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String operator = test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	String stringToCompare = String("Real");
	String stringToSwap = String("Fake");

	stringToSwap = stringToCompare;

	if (stringToCompare == stringToSwap)
	{
		std::cout << "[Operator = test] P" << std::endl;
	}
	else
	{
		std::cout << "[Operator = test] X" << std::endl;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// String operator < test
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	String stringLessThan = String("Raal");

	if (stringLessThan < stringToCompare)
	{
		std::cout << "[Operator < test] P" << std::endl;
	}
	else
	{
		std::cout << "[Operator < test] X" << std::endl;
	}

	return 0;
}