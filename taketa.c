#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Plus(char *a, char *b, char *ans, int keta);

int main(int argc, char *argv[])
{
	int i;
	int aLen = strlen(argv[1]);

	char *a = (char*)malloc(sizeof(char)*aLen);

	for(i=0;i<aLen;i++)
	{
		a[i] = argv[1][i] - 48;
	}

	int bLen = strlen(argv[2]);

	char *b = (char*)malloc(sizeof(char)*bLen);

	for(i=0;i<bLen;i++)
	{
		b[i] = argv[2][i] - 48;
	}

	int abLen;
	
	if(aLen > bLen)
		abLen = aLen;
	else
		abLen = bLen;
	
	char *ans = (char*)malloc(sizeof(char)*abLen);
	
	for(i=0;i<abLen;i++)
	{
		ans[i] = 0;
	}
	
	for(i=abLen;i>-1;i--)
	{
		Plus(a, b, ans, i);
	}
	
	for(i=0;i<abLen;i++)
		printf("%d", ans[i]);
	
	free(a);
	free(b);
	free(ans);
	
	return 0;
}

void Plus(char *a, char *b, char *ans, int keta)
{
	int tmp = 0;

	tmp = (a[keta] + b[keta] + ans[keta]);

	if(tmp > 9)
	{
		ans[keta - 1]++;
		ans[keta] = tmp - 10;
	}
	else
		ans[keta] = tmp;
}

