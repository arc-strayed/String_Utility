#pragma once

#include <cstring>

struct String
{
	char* strArray;

	int Length()
	{
		return strlen(strArray);
	}

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

	void Append(String& otherString)
	{
		strcat(strArray, otherString.CStr());
	}

	void Prepend(String& otherString)
	{
		char* newString;

		strcpy(newString, otherString.CStr());
		strcat(newString, strArray);

		strcpy(strArray, newString);
	}

	const char* CStr()
	{
		return strArray;
	}
};