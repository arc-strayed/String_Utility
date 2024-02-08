#pragma once

#include <cstring>

struct String
{
	char* strArray;

	// Returns the length of the array
	int Length()
	{
		return strlen(strArray);
	}

	// Returns the character at *index*
	char CharacterAt(int index)
	{
		if (index < 0 || index > Length())
		{
			return '\0';
		}
		else
		{
			return strArray[index];
		}
	}

	// Compares another string to this string to see if they're similar
	bool EqualTo(String& otherString)
	{
		int compareValue = 0;

		compareValue = strcmp(strArray, otherString.CStr());

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
	void Append(String& otherString)
	{
		strcat(strArray, otherString.CStr());
	}

	// Adds another string to the start of this string
	void Prepend(String& otherString)
	{
		char* newString;

		strcpy(newString, otherString.CStr());
		strcat(newString, strArray);

		strcpy(strArray, newString);
	}

	// Returns the const char* array of this string
	const char* CStr()
	{
		return strArray;
	}
};