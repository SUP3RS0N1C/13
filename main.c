#include <stdio.h>
#include <stdlib.h>
#include "keywords.h"
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int is_whitespace(char c)
{
	if (c==' ' ||
		c=='\r' ||
		c=='\n' ||
		c=='\t' ||
		c=='(')
	{
		return 1;
	}

	return 0;
}

int fget_word(FILE* fp, char* word)
{
	int cnt;
	char c;
	//무의미한 글자 건너뛰기  
	while((c=fgetc(fp)) != EOF)
	{
		if(is_whitespace(c) == 0)
			break;
	}
	if (c==EOF)
	{
		return 0;
	}
	
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	while((word[cnt] = fgetc(fp)) != EOF)
	{
		if (is_whitespace(word[cnt])==1)
		{
			word[cnt] ='\0';
			break;
		}
		cnt++;
	}

	return cnt;
}

int main(int argc, char *argv[]) 
{
	FILE *fp;
	char filepath[100];
	char word[100];

	//file open
	printf("input the file path : "); 
	scanf("%s",filepath/*파일패스는 포인터에해당*/);
	fp = fopen(filepath, "r");

	if (fp == NULL) //방어코드  
	{
		printf("file path is wrong! %s\n", filepath);
		return -1;
	}

	//word reading & analysis
	while(fget_word(fp,word) != 0)
	{
		count_word(word);
	}
	//output
	print_word();
	
	/*
	while(fget_word(fp,word) != 0)
	{
		printf("%s\n", word);
	}//검증용 임시코드  
	*/
	fclose(fp);
	
	return 0;
}
