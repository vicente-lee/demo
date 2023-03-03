#include "control.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	for (int i;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}
	return 0;
}
