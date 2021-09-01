#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	// int rc = fork();

	// testFileForExecuting

	// execl("/bin/ls", "ls", NULL);
	execle("/bin/ls", "ls", NULL);

	/*
	if (rc < 0) {
	 	fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("I am the child process and x is %d \n", x);
	} else {
		printf("I am the parent process and x is %d \n", x);
	}
	*/

	return 0;
}


/************************************************************************

Abraham Moreno

STUCK

************************************************************************/
