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
		printf("Hello \n");
	} else {
		/*
		Learned how to make a program sleep thanks to
		https://www.poftut.com/what-is-sleep-function-and-how-to-use-it-in-c-program/
		*/

		sleep(2);
		printf("Goodbye \n");
	}

	return 0;
}


/************************************************************************

Abraham Moreno
Question 1: By making the parent process sleep, you can ensure that the
	    child process will finish first.
************************************************************************/
