#include <string.h>
#include <err.h>
#include <stdlib.h>
#include <stdio.h>

#include "stringQuery.h"

#define NON_DIACRITRIC	"cueaaaaceeeiiiaaeaaooouuyou    faiounn2"
int 	DIACRITRIC[]= 	{-61,-121,-61,-68,-61,-87,-61,-94,-61,-92,-61,-96,-61,-91,-61,-89,-61,-86,-61,-85,-61,-88,-61,-81,-61,-82,-61,-84,-61,-124,-61,-123,-61,-119,-61,-90,-61,-122,-61,-76,-61,-74,-61,-78,-61,-69,-61,-71,-61,-65,-61,-106,-61,-100,-61,-72,-62,-93,-61,-104,-61,-105,-58,-110,-61,-95,-61,-83,-61,-77,-61,-70,-61,-79,-61,-111,-62,-86};
#define SPECIAL_CHAR	"./\\!?*%$£^¨µ;,§&\"\'(-_)=+}{[|`@]¤ "



char* stringQuery(char* string)
{
	string[strlen(string)-4]=0;
	stringNormalize(string);
	char *out = malloc(512*sizeof(char));
	if(out==NULL)
		err(1,"stringQuery : could not allocate memory");
	sprintf(out,"https://www.youtube.com/results?search_query=%s",string);
	return out;
}



void stringNormalize(char* string)
{
	for(char *point = string;*point!=0;point++)
	{
		// Upper to lower characters
		if (*point >= 65 && *point <= 90)
			(*point)+= 32;
		//If char is special character, make it blank
		else if (strchr(SPECIAL_CHAR,*point)&& *(point-1)!='+' && *(point+1)!=0)
			(*point--) = '+';
		else if (strchr(SPECIAL_CHAR,*point))
		{
			for(char *temp = point;*temp!=0;temp++)
				*temp = *(temp+1);
			point--;
		}
		//If the string contains diacritic characters, normalize them. 
		else if ((double)*point < 0)
			for(int i = 0; i <39; i++)
			{
				if ((DIACRITRIC[2*i]==(double)*point) && DIACRITRIC[2*i+1]==(double)*(point+1))
				{
					*(point--)=NON_DIACRITRIC[i];
					for(char*temp=point+1;*temp!=0;temp++)
						*temp = *(temp+1);
					return;
				}
			}
	}	
}