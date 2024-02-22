#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include "StringUtil.h"

/*
 *	String utility testing app that logs its results to a file.
 */

static void LogTest(std::ofstream& stream, bool success, const char* testName)
{
	if (success)
	{
		stream << testName << "\tPass" << std::endl;
	}
	else
	{
		stream << testName << "\tFail" << std::endl;
	}
}

int main()
{
	std::ofstream resultLogFile("results.txt", std::ofstream::app);

	if (resultLogFile.is_open())
	{
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// [Start of tests]
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		// Get current time
		auto currentTime = std::chrono::system_clock::now();
		std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);

		String mainString = String("Real");

		const int MAX_TESTS = 17;

		bool testsCompleted[MAX_TESTS] = {};
		for (int i = 0; i < MAX_TESTS; i++)
			testsCompleted[i] = false;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Length() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		size_t length = mainString.Length();

		if (length == 4)
			testsCompleted[0] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String CharacterAt() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		char compare_char = mainString.CharacterAt(0);

		if ((compare_char == 'R') == true)
			testsCompleted[1] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String EqualTo() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if (mainString.EqualTo("Real"))
			testsCompleted[2] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Append() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		mainString.Append("Real");

		if (mainString.EqualTo("RealReal"))
			testsCompleted[3] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Prepend() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		mainString.Prepend("Strong");

		if (mainString.EqualTo("StrongRealReal"))
			testsCompleted[4] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String CStr() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if (std::cout << mainString.CStr() << std::endl)
			testsCompleted[5] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String ToLower() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		mainString.ToLower();

		bool isStringLower = true;

		// Check if every character is lowercase
		for (size_t i = 0; i < mainString.Length(); i++)
		{
			if (std::islower(mainString[i]) == 0)
			{
				isStringLower = false;
				break;
			}
		}

		if (isStringLower)
			testsCompleted[6] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String ToUpper() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		mainString.ToUpper();

		bool isStringUpper = true;

		// Check if every character is uppercase
		for (size_t i = 0; i < mainString.Length(); i++)
		{
			if (std::isupper(mainString[i]) == 0)
			{
				isStringUpper = false;
				break;
			}
		}

		if (isStringUpper)
			testsCompleted[7] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Find() test 1
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String stringToSearch = String("Bread");
		String stringToFind = String("ead");

		if (stringToSearch.Find(stringToFind) == 2)
			testsCompleted[8] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Find() test 2
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String anotherStringToSearch = String("BreadBread");
		String anotherStringToFind = String("ead");

		if (anotherStringToSearch.Find(5, anotherStringToFind) == 7)
			testsCompleted[9] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String Replace() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String stringToReplace = String("Bad Rad Sad");

		stringToReplace.Replace("ad", "aaad");

		if (stringToReplace.EqualTo("Baaad Raaad Saaad") == true)
			testsCompleted[10] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String ReadFromConsole() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String originalString = String(mainString);

		std::cout << "Enter \"Test Test\": ";
		mainString.ReadFromConsole();

		if (mainString.EqualTo("Test Test"))
			testsCompleted[11] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// String WriteToConsole() test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if (mainString.WriteToConsole())
			testsCompleted[12] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// Operator == test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String stringCompare_1 = String("String");
		String stringCompare_2 = String("String");

		if (stringCompare_1 == stringCompare_2)
			testsCompleted[13] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// Operator [] test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		char characterAtIndex = stringCompare_1[0];

		if (characterAtIndex == 'S')
			testsCompleted[14] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// Operator = test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String stringAssign_1 = String("Real");
		String stringAssign_2 = String("Fake");

		stringAssign_2 = stringAssign_1;

		if (stringAssign_2 == stringAssign_1)
			testsCompleted[15] = true;

		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// Operator < test
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		String stringToCompare = String("Zebra");
		String stringLessThan  = String("Animal");

		if ((stringToCompare < stringLessThan) == false)
			testsCompleted[16] = true;
		
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// Writing test results to file
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		char timeBuffer[26] = {};
		ctime_s(timeBuffer, 26, &currentTimeT);
		resultLogFile << "Time\t" << timeBuffer;

		// Write test completion rate to file
		int totalTestsCompleted = 0;
		for (int i = 0; i < MAX_TESTS; i++)
		{
			if (testsCompleted[i] == true)
				totalTestsCompleted++;
		}

		float passRate = ((float)totalTestsCompleted / (float)MAX_TESTS) * 100.0f;
		resultLogFile << "Success rate\t" << passRate << "%" << std::endl;

		LogTest(resultLogFile, testsCompleted[0], "Length() test");
		LogTest(resultLogFile, testsCompleted[1], "CharacterAt() test");
		LogTest(resultLogFile, testsCompleted[2], "EqualTo() test");
		LogTest(resultLogFile, testsCompleted[3], "Append() test");
		LogTest(resultLogFile, testsCompleted[4], "Prepend() test");
		LogTest(resultLogFile, testsCompleted[5], "CStr() test");
		LogTest(resultLogFile, testsCompleted[6], "ToLower() test");
		LogTest(resultLogFile, testsCompleted[7], "ToUpper() test");
		LogTest(resultLogFile, testsCompleted[8], "Find() test");
		LogTest(resultLogFile, testsCompleted[9], "Find() test 2");
		LogTest(resultLogFile, testsCompleted[10], "Replace() test");
		LogTest(resultLogFile, testsCompleted[11], "ReadFromConsole() test");
		LogTest(resultLogFile, testsCompleted[12], "WriteToConsole() test");
		LogTest(resultLogFile, testsCompleted[13], "Operator == test");
		LogTest(resultLogFile, testsCompleted[14], "Operator [] test");
		LogTest(resultLogFile, testsCompleted[15], "Operator = test");
		LogTest(resultLogFile, testsCompleted[16], "Operator < test");

		resultLogFile.close();
	}

	return 0;
}