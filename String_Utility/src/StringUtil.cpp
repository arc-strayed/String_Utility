#include "StringUtil.h"


#include <cstring>
#include <cctype>
#include <iostream>

String::String(const char* rawString)
{
	stringSize = strlen(rawString) + 1;

	stringBuffer = new char[stringSize];
	std::memcpy(stringBuffer, rawString, stringSize);
}

String::String(const String& otherString)
{
	if (stringBuffer != nullptr) delete[] stringBuffer;

	stringSize = otherString.stringSize;

	// Copy other string buffer to this string buffer
	stringBuffer = new char[stringSize];
	std::memcpy(stringBuffer, otherString.stringBuffer, stringSize);
}

String::~String()
{
	delete[] stringBuffer;
	stringBuffer = nullptr;
}

size_t String::Length() const
{
	return strlen(stringBuffer);
}

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

bool String::EqualTo(const String& otherString) const
{
	return (strcmp(stringBuffer, otherString.stringBuffer) == 0);
}

void String::Append(const String& otherString)
{
	if (stringBuffer != nullptr) delete[] stringBuffer;

	stringSize += otherString.stringSize;

	// Construct new string
	stringBuffer = new char[stringSize];
	std::memcpy(stringBuffer, otherString.stringBuffer, stringSize);
	strcat_s(stringBuffer, stringSize, otherString.stringBuffer);
}

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

const char* String::CStr() const
{
	return stringBuffer;
}

void String::ToLower()
{
	for (size_t i = 0; i < Length(); i++)
	{
		stringBuffer[i] = std::tolower(stringBuffer[i]);
	}
}

void String::ToUpper()
{
	for (size_t i = 0; i < Length(); i++)
	{
		stringBuffer[i] = std::toupper(stringBuffer[i]);
	}
}

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

bool String::operator == (const String& rightString) const
{
	return EqualTo(rightString);
}

char String::operator [] (int index) const
{
	return CharacterAt(index);
}

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

bool String::operator < (const String& rightString) const
{
	int compare_result = strcmp(stringBuffer, rightString.stringBuffer);

	if (compare_result == 0 || compare_result < 0)
		return false;
	else
		return true;
}