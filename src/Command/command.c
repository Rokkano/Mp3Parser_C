#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#include "command.h"

char *executeCommand(char *command)
{
	char buf[100];
	char *str = NULL;
	char *temp = NULL;
	unsigned int size = 1;
	unsigned int strlength;

	FILE *ls;
	if (NULL == (ls = popen(command, "r"))) 
		err(1,"executeCommand : could not execute Linux command");
	while (fgets(buf, sizeof(buf), ls) != NULL) 
	{
		strlength = strlen(buf);
		temp = realloc(str, size + strlength); 
		if (temp == NULL) 
			err(1,"executeCommand : could not reallocate temp variable"); 
		else
			str = temp;
		strcpy(str + size - 1, buf);
		size += strlength; 
	}
	pclose(ls);
	return str;
}