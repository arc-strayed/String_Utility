#pragma once

#include <cstring>

struct StrUtil
{
	const char* strArray;

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

	bool EqualTo(const char* otherStr)
	{
		int compareValue = 0;

		compareValue = strcmp(strArray, otherStr);

		if (compareValue != 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};