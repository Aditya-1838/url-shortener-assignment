#include "./childRoutine.hpp"
#include "./print.hpp"
#include <errno.h>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

void playChild(char **word)
{
    if (strcmp("pingme", word[0]) == 0)
    {
        char path[50] = "";
        strcat(path, BIN_FEATURE);  // If you have a custom binary path
        strcat(path, "pingme");
        execvp(path, word);
        printSystemError();
        exit(EXIT_FAILURE);
    }
    else if (strcmp("start", word[0]) == 0)
    {
        execvp(word[1], &word[1]);
        printSystemError();
        exit(EXIT_FAILURE);
    }
    else if (strcmp("quit", word[0]) == 0 || strcmp("exit", word[0]) == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        // ✅ Default case: run any system command like ls, pwd, etc.
        execvp(word[0], word);
        printError("Unknown operation");
        exit(EXIT_FAILURE);
    }
}
