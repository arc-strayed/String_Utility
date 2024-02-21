#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include "StringUtil.h"

/*
 *	String utility testing app
 */

int main()
{
	std::ofstream resultLogFile("results.txt", std::ofstream::app);

	if (resultLogFile.is_open())
	{
		// Get current time and append to file
		auto currentTime = std::chrono::system_clock::now();
		std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);

		char timeBuffer[26] = {};
		ctime_s(timeBuffer, 26, &currentTimeT);

		resultLogFile << "Time\t" << timeBuffer;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// [Start of tests]
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String* mainString = new String("Real");

		int testCompleted = 0;
		const int MAX_TESTS = 17;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Length() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		size_t length = mainString->Length();

		if (length == 4)
		{
			resultLogFile << "[Length() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[Length() test]\tPass" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String CharacterAt() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		char compare_char = mainString->CharacterAt(0);

		if ((compare_char == 'R') == true)
		{
			resultLogFile << "[CharacterAt() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[CharacterAt() test]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String EqualTo() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if (mainString->EqualTo("Real") == true)
		{
			resultLogFile << "[EqualTo() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[EqualTo() test]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Append() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		mainString->Append("Real");

		if (mainString->EqualTo("RealReal"))
		{
			resultLogFile << "[Append() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[Append() test]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Prepend() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		mainString->Prepend("Strong");

		if (mainString->EqualTo("StrongRealReal"))
		{
			resultLogFile << "[Prepend() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[Prepend() test]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String CStr() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if (std::cout << mainString->CStr() << std::endl)
		{
			resultLogFile << "[CStr() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[CStr() test]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String ToLower() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		mainString->ToLower();

		bool isStringLower = true;
		String& mainString_ref = *mainString;

		// Check if every character is lowercase
		for (size_t i = 0; i < mainString->Length(); i++)
		{
			if (std::islower(mainString_ref[i]) == 0)
			{
				isStringLower = false;
				break;
			}
		}

		if (isStringLower)
		{
			resultLogFile << "[ToLower() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[ToLower() test]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String ToUpper() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		mainString->ToUpper();

		bool isStringUpper = true;

		// Check if every character is uppercase
		for (size_t i = 0; i < mainString->Length(); i++)
		{
			if (std::isupper(mainString_ref[i]) == 0)
			{
				isStringUpper = false;
				break;
			}
		}

		if (isStringUpper)
		{
			resultLogFile << "[ToUpper() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[ToUpper() test]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Find() test 1
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String* stringToSearch = new String("Bread");
		String* stringToFind = new String("ead");

		if (stringToSearch->Find(*stringToFind) == 2)
		{
			resultLogFile << "[Find() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[Find() test]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Find() test 2
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String* anotherStringToSearch = new String("BreadBread");
		String* anotherStringToFind = new String("ead");

		if (anotherStringToSearch->Find(5, *anotherStringToFind) == 7)
		{
			resultLogFile << "[Find() test 2]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[Find() test 2]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Replace() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String* stringToReplace = new String("Bad Rad Sad");

		stringToReplace->Replace("ad", "aaad");

		if (stringToReplace->EqualTo("Baaad Raaad Saaad") == true)
		{
			resultLogFile << "[Replace() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[Replace() test]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String ReadFromConsole() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String* originalString = new String(*mainString);

		std::cout << "Enter a string: ";
		mainString->ReadFromConsole();

		if (mainString->EqualTo(*originalString) == false)
		{
			resultLogFile << "[ReadFromConsole() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[ReadFromConsole() test]\tFail" << std::endl;
		}

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String WriteToConsole() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if (mainString->WriteToConsole())
		{
			resultLogFile << "[WriteToConsole() test]\tPass" << std::endl;
			testCompleted++;
		}
		else
		{
			resultLogFile << "[WriteToConsole() test]\tFail" << std::endl;
		}

		
		// Write test completion rate to file
		float completionRate = ((float)testCompleted / (float)MAX_TESTS) * 100.0f;
		resultLogFile << "Completion rate\t" << completionRate << "%" << std::endl;

		delete mainString;
		delete stringToSearch;
		delete stringToFind;
		delete anotherStringToSearch;
		delete anotherStringToFind;
		delete originalString;
		delete stringToReplace;

		mainString = nullptr;
		stringToSearch = nullptr;
		stringToFind = nullptr;
		anotherStringToSearch = nullptr;
		anotherStringToFind = nullptr;
		originalString = nullptr;
		stringToReplace = nullptr;

		resultLogFile.close();
	}

	return 0;
}