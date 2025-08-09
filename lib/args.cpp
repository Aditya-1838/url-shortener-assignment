#include "./args.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

void treatArgs(int argc)
{
    if (argc > 1)
    {
        printError("Params are forbidden");
        exit(EXIT_FAILURE);
    }
}

void seeArgs(char **word, int wordCounter)
{
    for (int i = 0; i < wordCounter; i++)
    {
        cout << word[i] << endl;
    }
}
