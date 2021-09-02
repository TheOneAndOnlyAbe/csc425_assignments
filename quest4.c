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
		printf("I am the child process and x is %d \n", x);

		char const *envp[] = {NULL};
	        char *args[] = {"/bin/ls", NULL};

		// execl("/bin/ls", "ls", NULL);
        	// execle("/bin/ls", "ls", NULL, *envp);
        	// execlp("/bin/ls", "ls", NULL);
        	// execv(args[0], args);
        	// execvp(args[0], args);
        	// execvpe("/bin/ls", args, envp); It says that this one does not exist...

	} else {
		printf("I am the parent process and x is %d \n", x);
	}

	return 0;
}


/************************************************************************

Abraham Moreno

Question 1: Maybe there are many variations so as to be able to execute
	 the exact same thing in different situations or enviornments
	 without having problems.

************************************************************************/
