#include "StringUtil.h"

int main()
{
    String* string_to_output = new String("Hello, world!");

    string_to_output->WriteToConsole();

    delete string_to_output;
    string_to_output = nullptr;

    return 0;
}