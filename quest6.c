#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	int status;

	if (rc < 0) {
	 	fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("I am the child process \n");
	} else {
		/*

		Learned to use waitpid thanks to
		https://support.sas.com/documentation/onlinedoc/sasc/doc/lr2/waitpid.htm

		*/

		int waitingForPID = waitpid(rc, &status, WUNTRACED);

		printf("I am the parent process \n");
                printf("%d, %d \n", rc, waitingForPID);
	}

	return 0;
}


/************************************************************************

Abraham Moreno
Question 1: When you want to track certain statuses or have certain
	    control over certain situations. I'm guessing it's also good
	    when handling more than one child process.

************************************************************************/
