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
		close(STDOUT_FILENO);

		printf("I am the child process \n");
		printf("Testing 1... 2... 3...");
	} else {
		printf("I am the parent process \n");
	}

	return 0;
}


/************************************************************************

Abraham Moreno
Question 1: The child process can't print anymore.

************************************************************************/
