#include "StringUtil.h"

/*
* Definition file for StringUtil.h
*/

#include <cstring>
#include <cctype>
#include <iostream>

// Raw character array constructor
String::String(const char* rawString)
{
	stringSize = strlen(rawString) + 1;

	stringBuffer = new char[stringSize];
	std::memcpy(stringBuffer, rawString, stringSize);
}

// Copy constructor
String::String(const String& otherString)
{
	if (stringBuffer != nullptr) delete[] stringBuffer;

	stringSize = otherString.stringSize;

	// Copy other string buffer to this string buffer
	stringBuffer = new char[stringSize];
	std::memcpy(stringBuffer, otherString.stringBuffer, stringSize);
}

// Deconstructor
String::~String()
{
	if (stringBuffer) delete[] stringBuffer;
	stringBuffer = nullptr;
}

// Returns the length of the string
size_t String::Length() const
{
	return strlen(stringBuffer);
}

// Returns the character at *index*
char String::CharacterAt(int index) const
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

// Compares two strings to see if they're similar
bool String::EqualTo(const String& otherString) const
{
	return (strcmp(stringBuffer, otherString.stringBuffer) == 0);
}

// Adds another string to the end of this string
void String::Append(const String& otherString)
{
	if (stringBuffer != nullptr) delete[] stringBuffer;

	stringSize += otherString.stringSize;

	// Construct new string
	stringBuffer = new char[stringSize];
	std::memcpy(stringBuffer, otherString.stringBuffer, stringSize);
	strcat_s(stringBuffer, stringSize, otherString.stringBuffer);
}

// Adds another string to the start of this string
void String::Prepend(const String& otherString)
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

// Returns the character array of this string
const char* String::CStr() const
{
	return stringBuffer;
}

// Converts all characters to lowercase
void String::ToLower()
{
	for (size_t i = 0; i < Length(); i++)
	{
		stringBuffer[i] = std::tolower(stringBuffer[i]);
	}
}

// Converts all characters to uppercase
void String::ToUpper()
{
	for (size_t i = 0; i < Length(); i++)
	{
		stringBuffer[i] = std::toupper(stringBuffer[i]);
	}
}

// Returns the index of *stringToFind*
int String::Find(const String& stringToFind)
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

// Returns the index of *stringToFind* starting at *startIndex*
int String::Find(int startIndex, const String& stringToFind)
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

// Replaces every instance of *stringToFind* with *replaceString*
void String::Replace(const String& stringToFind, const String& replaceString)
{
	char* storageString = new char[stringSize];
	std::memcpy(storageString, stringBuffer, stringSize);

	int foundLocation = Find(stringToFind);

	// Loop while there is still a stringToFind
	while (foundLocation > 0)
	{
		stringSize += replaceString.stringSize;
		char* newString = new char[stringSize];

		// Copy storageString until found location and then concatenate replaceString
		strncpy_s(newString, stringSize, storageString, foundLocation);
		strcat_s(newString, stringSize, replaceString.stringBuffer);

		// Concatenate the rest of storageString after stringToFind
		int offset = foundLocation - 1 + stringToFind.stringSize;
		strcat_s(newString, stringSize, storageString + offset);

		// Store newString in storageString
		delete[] storageString;
		storageString = new char[stringSize];
		std::memcpy(storageString, newString, stringSize);

		delete[] newString;
		newString = nullptr;

		// Find next instance with offset of stringToFind's size
		char* subString = strstr(storageString + foundLocation + stringToFind.stringSize, stringToFind.CStr());
		if (subString == nullptr)
			foundLocation = -1;
		else
			foundLocation = subString - storageString;
	}

	delete[] stringBuffer;
	stringBuffer = new char[stringSize];
	std::memcpy(stringBuffer, storageString, stringSize);

	delete[] storageString;
	storageString = nullptr;
}

// Read input from console
void String::ReadFromConsole()
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
int String::WriteToConsole() const
{
	if (std::cout << stringBuffer << std::endl)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Checks if two strings are the same
bool String::operator == (const String& rightString) const
{
	return EqualTo(rightString);
}

// Get character at *index*
char String::operator [] (int index) const
{
	return CharacterAt(index);
}

// Copy other string to this string
String& String::operator = (const String& rightString)
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

// Check if string is before *rightString* in the alphabet
bool String::operator < (const String& rightString) const
{
	int compare_result = strcmp(stringBuffer, rightString.stringBuffer);

	if (compare_result == 0 || compare_result > 0)
		return false;
	else
		return true;
}