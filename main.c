#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int pp[2];
	pipe(pp);
	int d = dup2(pp[0], 0);
	printf("%d\n", d);
}