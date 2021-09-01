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
		//close(STDOUT_FILENO);
		//open("./quest8.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

		printf("I am the child process \n");

		char *myArgs[2];
		myArgs[0] = strdup("testFileForExecuting");
		myArgs[1] = NULL;

		execvp(myArgs[0], myArgs);
	} else {
		int rc_wait = wait(NULL);
		printf("I am the parent process \n");
	}

	return 0;
}


/************************************************************************

Abraham Moreno
STUCK

************************************************************************/
