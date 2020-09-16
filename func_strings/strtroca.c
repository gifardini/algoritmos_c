#include <stdio.h>
#include <stdlib.h>

char* strca (char*str1, char*str2);

int main (void)
{
	char* str1 = malloc (50*sizeof(char));
	char* str2 = malloc (50*sizeof(char));
	char* str3 = malloc (100*sizeof(char));
	printf("insira a primeira frase: ");
	fgets(str1, 50, stdin);
	printf("insira a segunda frase: ");
	fgets(str2, 50, stdin);

	str3 = strca(str1, str2);
	printf("\n%s", str3);
	free(str1);
	free(str2);
	free(str3);
}
char* strca (char*str1, char*str2)
{
	char* strfunc = malloc (100*sizeof(char));
	int i = 0, j = 0;

	while (str1[i] != '\n')
	{
		strfunc[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		strfunc[i] = str2[j];
		i++;
		j++;
	}
	return strfunc;
}
