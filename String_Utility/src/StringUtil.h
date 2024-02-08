#pragma once

#include <cstring>
#include <cctype>
#include <iostream>

struct String
{
	//char stringBuffer[32] = {};
	char* stringBuffer;
	int stringSize = 0;

	String(const char* rawString)
	{
		stringSize = strlen(rawString) + 1;

		stringBuffer = new char[stringSize];

		strcpy_s(stringBuffer, sizeof(char) * stringSize, rawString);
	}

	~String()
	{
		if (stringBuffer != nullptr)
		{
			delete[] stringBuffer;
		}
	}

	// Returns the length of the array
	size_t Length() const
	{
		return strlen(stringBuffer);
	}

	// Returns the character at *index*
	char CharacterAt(int index) const
	{
		if (index < 0 || index > Length())
		{
			return '\0';
		}
		else
		{
			return stringBuffer[index];
		}
	}

	// Compares another string to this string to see if they're similar
	bool EqualTo(const String& otherString) const
	{
		int compareValue = 0;

		compareValue = strcmp(stringBuffer, otherString.CStr());

		if (compareValue != 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// Adds another string to the end of this string
	void Append(const String& otherString)
	{
		stringSize += otherString.stringSize;

		char* newString = new char[stringSize];
		newString[0] = '\0';

		strcpy_s(newString, sizeof(char) * stringSize, stringBuffer);

		strcat_s(newString, sizeof(char) * stringSize, otherString.CStr());

		stringBuffer = newString;
	}

	// Adds another string to the start of this string
	void Prepend(const String& otherString)
	{
		stringSize += otherString.stringSize;

		char* newString = new char[stringSize];
		newString[0] = '\0';

		strcpy_s(newString, sizeof(char) * stringSize, otherString.CStr());

		strcat_s(newString, sizeof(char) * stringSize, stringBuffer);

		stringBuffer = newString;
	}

	// Returns the const char* array of this string
	const char* CStr() const
	{
		return stringBuffer;
	}

	// Converts all characters to lowercase
	void ToLower()
	{
		for (size_t i = 0; i < Length(); i++)
		{
			stringBuffer[i] = std::tolower(stringBuffer[i]);
		}
	}

	// Converts all characters to uppercase
	void ToUpper()
	{
		for (size_t i = 0; i < Length(); i++)
		{
			stringBuffer[i] = std::toupper(stringBuffer[i]);
		}
	}

	// Finds the location of stringToFind
	//int Find(String& stringToFind)
	//{
	//	char* subString = strstr(stringBuffer, stringToFind.CStr());

	//	if (subString == nullptr)
	//	{
	//		return -1;
	//	}
	//	else
	//	{
	//		return Length() - stringToFind.Length();
	//	}
	//}

	//int Find(int startIndex, String& stringToFind)
	//{

	//}

	//void Replace(String& stringToFind, String& replaceString)
	//{
	//	
	//}

	void ReadFromConsole()
	{
		std::cin >> stringBuffer;
	}

	void WriteToConsole() const
	{
		std::cout << stringBuffer << std::endl;
	}

	bool operator==(const String& rightString) const
	{
		return EqualTo(rightString);
	}

	char operator[](int index) const
	{
		return CharacterAt(index);
	}

	void operator=(const String& rightString)
	{
		//strcpy_s(stringBuffer, sizeof(char) * stringSize, rightString.CStr());
		strcpy_s(stringBuffer, sizeof(stringBuffer), rightString.CStr());
	}

	bool operator<(const String& rightString) const
	{
		return strcmp(stringBuffer, rightString.CStr());
	}
};