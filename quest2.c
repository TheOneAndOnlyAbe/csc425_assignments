#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	/*
	Learned what the return value of open() is thanks to
	https://pubs.opengroup.org/onlinepubs/007904875/functions/open.html#:~:text=The%20open()%20function%20shall%20return%20a%20file%20descriptor%20for,other%20process%20in%20the%20system. 

	Also learned how to write to files thanks to
	https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/

	*/

	printf("If the file opened correctly. openOrNot should be a non-negative integer. \n");

	int openOrNot = open("./testFileForOpeningAndWriting.txt", O_WRONLY);
	int rc = fork();

	if (rc < 0) {
	 	fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("I am the child process and openOrNot is  %d \n", openOrNot);

		write(openOrNot, "Hola from child \n", strlen("Hola from child \n"));
	} else {
		printf("I am the parent process and openOrNot is  %d \n", openOrNot);

		write(openOrNot, "Hola from parent \n", strlen("Hola from parent \n"));
	}

	return 0;
}

/********************************************************
Abraham Moreno
Question 1: Yes, both can access the file desciptor.
Question 2: Both will do it but it has to be in an order.
	    It seems that the parent always goes first
  	    based on the txt file.
********************************************************/
