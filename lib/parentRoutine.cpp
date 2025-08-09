#include "./parentRoutine.hpp"
#include "./print.hpp"

void playParent(pid_t child_pid)
{
    printProcessStarted(child_pid);
    int status;
    pid_t wpid;

    wpid = waitpid(child_pid, &status, WUNTRACED | WCONTINUED);
    if (wpid == -1)
    {
        printError("waitpid failure");
        exit(EXIT_FAILURE);
    }

    if (WIFEXITED(status))
    {
        printProcessExited(child_pid);
    }
    else if (WIFSIGNALED(status))
    {
        printProcessKilled(child_pid);
    }
    else if (WIFSTOPPED(status))
    {
        printProcessStopped(child_pid);
    }
    else if (WIFCONTINUED(status))
    {
        printProcessContinued(child_pid);
    }
}
