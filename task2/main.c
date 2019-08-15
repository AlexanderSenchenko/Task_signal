#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int sig;
	sigset_t mask;
	sigfillset(&mask);
	sigprocmask(SIG_BLOCK, &mask, NULL);

	while (1) {
		sigwait(&mask, &sig);
		printf("Get signal\n");
	}

	return 0;
}


