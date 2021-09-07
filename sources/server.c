#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	while (true)
	{
		printf("Test %d\n", getpid());
		sleep(2);
	}
}
