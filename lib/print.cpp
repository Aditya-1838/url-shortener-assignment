#include "./print.hpp"

void printMyshell()
{
    cout << "myshell> ";
}

void printError(string msg)
{
    printMyshell();
    cout << "[ERROR] " << msg << endl;
}

void printErrorOverArgs(int max)
{
    printError("Forbidden to enter, more than " + to_string(max) + " arguments");
}

void printMyshellMsg(string msg)
{
    printMyshell();
    cout << msg << endl;
}

void printProcessStarted(pid_t pid)
{
    printMyshellMsg("process id " + to_string(pid) + " started");
}

void printProcessExited(pid_t pid)
{
    printMyshellMsg("process id " + to_string(pid) + " exited");
}

void printProcessKilled(pid_t pid)
{
    printMyshellMsg("process id " + to_string(pid) + " killed");
}

void printProcessStopped(pid_t pid)
{
    printMyshellMsg("process id " + to_string(pid) + " stopped");
}

void printProcessContinued(pid_t pid)
{
    printMyshellMsg("process id " + to_string(pid) + " continued");
}

void printSystemError()
{
    printError("(" + to_string(errno) + ") " + strerror(errno));
}
