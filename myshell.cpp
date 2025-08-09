#include <iostream>    // cout
#include <sys/types.h> // fork, wait
#include <sys/wait.h>  // wait
#include <unistd.h>    // fork
#include <stdlib.h>    // exit
#include "./lib/args.hpp"
#include "./lib/initMyshell.hpp"
#include "./lib/print.hpp"

using namespace std;

int main(int argc, char **argv)
{
    pid_t pidMyshell;

    treatArgs(argc);

    pidMyshell = fork();
    if (pidMyshell < 0)
    {
        printError("New process creation failure");
        exit(EXIT_FAILURE);
    }
    else if (pidMyshell == 0)
    {
        initMyshell();
    }
    else
    {
        wait(0);
    }

    exit(EXIT_SUCCESS);
}