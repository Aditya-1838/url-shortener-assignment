#include "./dealWithInput.hpp"
#include "./print.hpp"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void dealWithEOF()
{
    if (feof(stdin))
    {
        printf("\n");
        exit(EXIT_SUCCESS);
    }
}

char *readUserInput(char *input, int maxLength)
{
    printMyshell();
    fgets(input, maxLength, stdin);
    dealWithEOF();
    return input;
}

void getAllArgs(char **word, int *wordCounter, char *input, const int MAX_NUMBER_OF_WORDS)
{
    word[(*wordCounter)++] = strtok(input, " \t\n");
    while (*wordCounter < MAX_NUMBER_OF_WORDS)
    {
        word[*wordCounter] = strtok(NULL, " \t\n");
        if (word[*wordCounter] == NULL) break;
        (*wordCounter)++;
    }

    if (strtok(NULL, " \t\n"))
    {
        printErrorOverArgs(MAX_NUMBER_OF_WORDS);
        exit(EXIT_FAILURE);
    }

    // NULL-terminate the array
    word[*wordCounter] = NULL;
}
