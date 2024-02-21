#pragma once

/*
	A header only string utility file that will make working with character arrays easier to manage.
*/

class String
{
public:
	String(const char* rawString);     // Raw character array constructor
	String(const String& otherString); // Copy constructor
	~String();                         // Deconstructor

	// Returns the length of the string
	size_t Length() const;

	// Returns the character at *index*
	char CharacterAt(int index) const;

	// Compares two strings to see if they're similar
	bool EqualTo(const String& otherString) const;

	// Adds another string to the end of this string
	void Append(const String& otherString);

	// Adds another string to the start of this string
	void Prepend(const String& otherString);

	// Returns the const char* of this string
	const char* CStr() const;

	// Converts all characters to lowercase
	void ToLower();

	// Converts all characters to uppercase
	void ToUpper();

	// Returns the index of stringToFind
	int Find(const String& stringToFind);

	// Returns the index of stringToFind starting at *startIndex*
	int Find(int startIndex, const String& stringToFind);

	// Replaces every instance of *stringToFind* with *replaceString*
	void Replace(const String& stringToFind, const String& replaceString);

	// Read input from console
	void ReadFromConsole();

	// Write from array to console
	int WriteToConsole() const;

	// Checks if two strings are the same
	bool operator == (const String& rightString) const;

	// Get character at *index*
	char operator [] (int index) const;

	// Copy other string to this string
	String& operator = (const String& rightString);

	// Check if string is before *rightString* in the alphabet
	bool operator < (const String& rightString) const;

private:
	char* stringBuffer = nullptr;
	size_t stringSize = 0;
};