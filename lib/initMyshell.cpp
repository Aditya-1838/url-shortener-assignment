#include "./initMyshell.hpp"
#include "./dealWithInput.hpp"
#include "./args.hpp"
#include "./execute.hpp"

#include <stdlib.h>

#define MAX_STRING_LENGTH 4096
#define MAX_NUMBER_OF_WORDS 100

void initMyshell()
{
    int wordCounter;
    char input[MAX_STRING_LENGTH];
    char *word[MAX_NUMBER_OF_WORDS];

    do
    {
        wordCounter = 0;
        readUserInput(input, MAX_STRING_LENGTH); // Prompt + input

        getAllArgs(word, &wordCounter, input, MAX_NUMBER_OF_WORDS);

        if (wordCounter == 0) continue; // Skip empty

        // Uncomment for debugging
        // seeArgs(word, wordCounter);

        execute(word);

    } while (shouldRepeat(word[0]));

    exit(EXIT_SUCCESS);
}
