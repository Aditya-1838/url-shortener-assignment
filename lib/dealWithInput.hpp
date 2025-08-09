#ifndef __DEALWITHINPUT__
#define __DEALWITHINPUT__

char *readUserInput(char *input, int maxLengh);
void getMyshellOperation(char **word, char *input);
void getAllArgs(char **word, int *wordCounter, char *input, int const MAX_NUMBER_OF_WORDS);

#endif
