#include "./execute.hpp"
#include "./print.hpp"
#include "./childRoutine.hpp"
#include "./parentRoutine.hpp"

#include <stdlib.h>
#include <string.h>

void execute(char **word)
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printError("New process creation failure");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        playChild(word);
    }
    else
    {
        playParent(pid);
    }
}

bool shouldRepeat(char *cmd)
{
    return strcmp("quit", cmd) != 0 && strcmp("exit", cmd) != 0;
}
