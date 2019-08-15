#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void func(int sig)
{
	printf("Get signal SIGUSER1\n");
	exit(0);
}

void func2(int sig)
{
	printf("Get signal SIGINT\n");
	while (1);
	exit(0);
}

int main()
{
	#if 1
	signal(SIGINT, func2);
	signal(SIGUSR1, func);
	#else
	struct sigaction new;
	struct sigaction old;
	sigset_t mask;

	sigaddset(&mask, SIGINT);

	new.sa_handler = &func2;
	new.sa_mask = mask;
	new.sa_flags = 0;

	sigaction(SIGINT, &new, &old);
	#endif

	while (1);

	return 0;
}


