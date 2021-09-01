#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc = fork();

	if (rc < 0) {
	 	fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("I am the child process \n");
	} else {
		int waitingForPID = wait(NULL);

		printf("I am the parent process \n");
                printf("%d, %d \n", rc, waitingForPID);
	}

	return 0;
}


/************************************************************************

Abraham Moreno
Question 1: wait() returns the PID of the child process its waiting on to
	    finish.
Question 2: I think it acts normally except that it doesn't wiat. rc
	    becomes 0 and waitingForPID becomes -1, so I'm guessing this
	    is because a process can't really wait on itself.

************************************************************************/
