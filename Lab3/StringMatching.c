#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcount;

int match(char text[], char word[])
{
	opcount = 0;
	int flag;
	int n = strlen(text);
	int m = strlen(word);
	for(int i = 0; i < n-m; i++)
	{
		flag = 1;
		for(int j = 0; j < m; j++)
		{
			opcount++; //comparison is opcount
			if(text[i] != word[j]) //letter does not match, move to next j so word keeps moving forward
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1) break;
	}
	printf("\nComparison Count: %d",opcount);
	return !flag;
}

int main()
{
	printf("Enter the text:\n");
	char text[50]; scanf("%[^\n]s",text);
	printf("Enter the word to be matched:\n");
	char word[20]; scanf("%s",word);
	int mat = match(text,word);
	if(mat == 1)
	{
		printf("\nString found\n");
	}
	else
	{
		printf("\nString not found\n");
	}
}