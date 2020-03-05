#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <err.h>

#include "main.h" 
#include "../Query/string/stringQuery.h"
#include "../Command/command.h"
#include "../../lib/fopen.h"

int main(int argc, char *argv[])
{
	//printf("%s\n","\u00e9");
	DIR *d;
	struct dirent *dir;
	d = opendir(argv[1]);
	int filecount=0;
	if(d==NULL)
		err(1,"main : could not open directory");	
	while ((dir = readdir(d)) != NULL) 
	{
		if (dir->d_name[0]=='.' || (dir->d_name[0]=='A' && dir->d_name[1]=='u'))
			continue;
		char *url = stringQuery(dir->d_name);
		printf("%s\n",url);
		fetchSourceCode(url,"data/temp/output.html");
		
		//Execute the grep command to search for the first image in the html output file
		
		// char *output = executeCommand("grep \"https://i.ytimg.com/vi/\" -m1 data/temp/output.html");
		// char *point = output;
		// char buff[512];
		// printf("%s\n",output);
		// for(;*point!='h'||*(point+1)!='t'||*(point+2)!='t'||*(point+3)!='p';point++);
		// for(int i = 0;*(point+i)!='\"';i++)
			// buff[i]=*(point+i);
		
		
		// printf("%s\n",buff);
		
		filecount++;
		// free(output);
		free(url);
	}
}



// int main2(int argc, char *argv[])
// {	
	// DIR *d;
	// struct dirent *dir;
	// d = opendir(argv[1]);
	// int count=0;
	// if(d==NULL)
		// err(1,"main : could not open directory");	
	// while ((dir = readdir(d)) != NULL) 
	// {
		// if (dir->d_name[0]=='.' || (dir->d_name[0]=='A' && dir->d_name[1]=='u'))
			// continue;
		// stringToQuery(dir->d_name);
		
		
		// printf("Wrote : %s\n",dir->d_name);
		// printf("1\n");
		// char *path="output.html";
		// char *url = malloc(1024*sizeof(char));
		// sprintf(url,"https://www.youtube.com/results?search_query=%s",dir->d_name);
		// printf("2\n");
		// fetchSourceCode(url,path);
		// char *output = executeCommand("grep \"height=\\\"138\\\"\" -m1 output.html");
		// char *point = output;
		// for(;*point!=0&&((*point)!='\"'||*(point-1)!='='||*(point-2)!='c'||*(point-3)!='r'||*(point-4)!='s');point++);
		// point++;
		// printf("3\n");
		// char *temppoint = point;
		// for(;*temppoint!='\"';temppoint++);
		// *temppoint=0;
		
		// printf("%s\n",point);
		// char buff[512];
		// sprintf(buff,"curl -o temp/%s.jpg  %s",dir->d_name,point);
		// executeCommand(buff);
		// printf("\n\n");
		
		
		// count++;
		// free(output);
		// free(url);
	// }
	// closedir(d);
	// return 0;
// }






