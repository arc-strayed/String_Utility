#pragma once

/*
	A header only string utility file that will make working with character arrays easier to manage.
*/

#include <cstring>
#include <cctype>
#include <iostream>

struct String
{
	char* stringBuffer = nullptr;
	size_t stringSize = 0;

	String()
	{

	}

	String(const char* rawString)
	{
		stringSize = strlen(rawString) + 1;

		stringBuffer = new char[stringSize];
		std::memcpy(stringBuffer, rawString, stringSize);
	}

	String(const String& otherString)
	{
		if (stringBuffer != nullptr) delete[] stringBuffer;

		stringSize = otherString.stringSize;

		// Copy other string buffer to this string buffer
		stringBuffer = new char[stringSize];
		std::memcpy(stringBuffer, otherString.stringBuffer, stringSize);
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
		return (strcmp(stringBuffer, otherString.CStr()) == 0);
	}

	// Adds another string to the end of this string
	void Append(const String& otherString)
	{
		if (stringBuffer != nullptr) delete[] stringBuffer;

		stringSize += otherString.stringSize;

		// Construct new string
		stringBuffer = new char[stringSize];
		std::memcpy(stringBuffer, otherString.stringBuffer, stringSize);
		strcat_s(stringBuffer, stringSize, otherString.CStr());
	}

	// Adds another string to the start of this string
	void Prepend(const String& otherString)
	{
		stringSize += otherString.stringSize;

		// Construct new string
		char* newString = new char[stringSize];
		std::memcpy(newString, otherString.stringBuffer, stringSize);
		strcat_s(newString, stringSize, stringBuffer);

		// Swap pointer
		if (stringBuffer != nullptr) delete[] stringBuffer;
		stringBuffer = newString;

		newString = nullptr;
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
	void Replace(String& stringToFind, String& replaceString)
	{
		int foundLocation = Find(stringToFind);
		char* newString = nullptr;

		while (foundLocation > 0)
		{
			stringSize += replaceString.stringSize;
			
			delete[] newString;
			newString = new char[stringSize];

			// Copy until foundLocation in stringBuffer
			strncpy_s(newString, stringSize * sizeof(char), stringBuffer, foundLocation);

			std::cout << newString << std::endl;
			
			// Concatenate replaceString
			strcat_s(newString, stringSize * sizeof(char), replaceString.CStr());

			std::cout << newString << std::endl;

			// Concatenate the rest of stringBuffer
			strcat_s(newString, stringSize * sizeof(char), stringBuffer + foundLocation);

			std::cout << newString << std::endl;

			// Check if there is another stringToFind
			foundLocation = Find(foundLocation + 1, stringToFind);
		}

		stringBuffer = newString;
	}

	// Read output from console
	void ReadFromConsole()
	{
		if (stringBuffer != nullptr) delete[] stringBuffer;

		char inputBuffer[512] = {};
		std::cin >> inputBuffer;

		stringSize = strlen(inputBuffer) + 1;

		// Construct new string
		stringBuffer = new char[stringSize];
		std::memcpy(stringBuffer, inputBuffer, stringSize);
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
		// Safe guards
		if (stringBuffer != nullptr) delete[] stringBuffer;
		if (this == &rightString) return *this;

		stringSize = rightString.stringSize;

		// Copy other string buffer to this string buffer
		stringBuffer = new char[stringSize];
		std::memcpy(stringBuffer, rightString.stringBuffer, stringSize);

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