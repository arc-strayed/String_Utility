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

	String(const String& otherString)
	{
		stringSize = otherString.stringSize;
		stringBuffer = otherString.stringBuffer;
	}

	~String()
	{
		delete[] stringBuffer;
		stringBuffer = nullptr;
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

		stringBuffer = newString;
	}

	// Adds another string to the start of this string
	void Prepend(const String& otherString)
	{
		stringSize += otherString.stringSize;

		char* newString = new char[stringSize];

		strcpy_s(newString, sizeof(char) * stringSize, otherString.CStr());
		strcat_s(newString, sizeof(char) * stringSize, stringBuffer);

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

	// Replaces stringToFind with replaceString
	//void Replace(String& stringToFind, String& replaceString)
	//{
	//	
	//}

	// Read output from console
	void ReadFromConsole()
	{
		char inBuffer[512] = {};
		std::cin >> inBuffer;

		stringSize = strlen(inBuffer) + 1;

		char* newString = new char[stringSize];

		strcpy_s(newString, sizeof(char) * stringSize, inBuffer);

		stringBuffer = newString;
	}

	// Write from array to console
	void WriteToConsole() const
	{
		std::cout << stringBuffer << std::endl;
	}

	// Check if strings are the same
	bool operator==(const String& rightString) const
	{
		return EqualTo(rightString);
	}

	// Get character at index
	char operator[](int index) const
	{
		return CharacterAt(index);
	}

	// Copy other string to this string
	String& operator=(const String& rightString)
	{
		String newString = String(rightString);

		return *this;
	}

	// Check if string is before rightString in the alphabet
	bool operator<(const String& rightString) const
	{
		int compare_result = strcmp(stringBuffer, rightString.CStr());

		if (compare_result == 0 || compare_result < 0)
			return false;
		else
			return true;
	}
};