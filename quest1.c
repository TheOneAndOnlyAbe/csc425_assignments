#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int x = 100;
	int rc = fork();

	if (rc < 0) {
	 	fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("I am the child process and x is %d \n", x);
		x = 200;
		printf("I am the child process and x is now changed to %d \n", x);
	} else {
		printf("I am the parent process and x is %d \n", x);
		x = 500;
		printf("I am the parent process and x is now changed to  %d \n", x);
	}

	return 0;
}


/************************************************************************

Abraham Moreno
Question 1: Right after forking, for both the parent and child processes,
	    x is 100.
Question 2: When x is changed in the child and parent processes, x is
            what was assigned in the parent process and the child
            process. If after forking, I make x = 300 in the parent
            process and x = 600 in the child process, x will be 300 in
            the parent process and 600 in the child process.

************************************************************************/
