#pragma once

#include <cstring>
#include <cctype>
#include <iostream>

struct String
{
	char* stringBuffer = 0;
	size_t stringSize = 0;

	String()
	{

	}

	String(const char* rawString)
	{
		stringSize = strlen(rawString) + 1;

		stringBuffer = new char[stringSize];

		strcpy_s(stringBuffer, sizeof(char) * stringSize, rawString);
	}

	String(String& otherString)
	{
		stringSize = otherString.stringSize;
		stringBuffer = otherString.stringBuffer;
	}

	~String()
	{
		delete[] stringBuffer;
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

		strcpy_s(newString, sizeof(char) * stringSize, stringBuffer);
		strcat_s(newString, sizeof(char) * stringSize, otherString.CStr());

		delete[] stringBuffer;
		stringBuffer = nullptr;

		stringBuffer = newString;
	}

	// Adds another string to the start of this string
	void Prepend(const String& otherString)
	{
		stringSize += otherString.stringSize;

		char* newString = new char[stringSize];

		strcpy_s(newString, sizeof(char) * stringSize, otherString.CStr());
		strcat_s(newString, sizeof(char) * stringSize, stringBuffer);

		delete[] stringBuffer;
		stringBuffer = nullptr;

		stringBuffer = newString;
	}

	// Returns the const char* of this string
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

	// Returns the index of stringToFind
	int Find(String& stringToFind)
	{
		char* subString = strstr(stringBuffer, stringToFind.CStr());

		if (subString == nullptr)
		{
			return -1;
		}
		else
		{
			return subString - stringBuffer; // Pointer arithmatic to find index of subString
		}
	}

	// Returns the index of stringToFind starting at startIndex
	int Find(int startIndex, String& stringToFind)
	{
		if (startIndex < 0 || startIndex > Length())
		{
			std::cout << "Index is out of range" << std::endl;
			return -2;
		}

		char* subString = strstr(stringBuffer + startIndex, stringToFind.CStr());

		if (subString == nullptr)
		{
			return -1;
		}
		else
		{
			return subString - stringBuffer;
		}
	}

	//void Replace(String& stringToFind, String& replaceString)
	//{
	//	
	//}

	void ReadFromConsole()
	{
		char inBuffer[512] = {};
		std::cin >> inBuffer;

		stringSize = strlen(inBuffer) + 1;

		char* newString = new char[stringSize];

		strcpy_s(newString, sizeof(char) * stringSize, inBuffer);

		stringBuffer = newString;
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

	String& operator=(const String& rightString)
	{
		stringSize = rightString.stringSize;
		stringBuffer = rightString.stringBuffer;

		return *this;
	}

	bool operator<(const String& rightString) const
	{
		return strcmp(stringBuffer, rightString.CStr());
	}
};