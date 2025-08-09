// Header for executing shell commands using fork and exec

#ifndef __EXECUTE__
#define __EXECUTE__

#include <unistd.h>

void execute(char **word);
bool shouldRepeat(char *cmd);
void playParent(pid_t child_pid);
void playChild(char **word);

#endif
