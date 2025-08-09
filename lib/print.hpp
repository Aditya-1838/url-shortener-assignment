#ifndef PRINT_HPP
#define PRINT_HPP

#include <string>
#include <iostream>
#include <sys/types.h>
#include <cstring>
#include <errno.h>

using namespace std;

void printMyshell();
void printError(string msg);
void printErrorOverArgs(int max);
void printMyshellMsg(string msg);

void printProcessStarted(pid_t pid);
void printProcessExited(pid_t pid);
void printProcessKilled(pid_t pid);
void printProcessStopped(pid_t pid);
void printProcessContinued(pid_t pid);
void printSystemError();

#endif
