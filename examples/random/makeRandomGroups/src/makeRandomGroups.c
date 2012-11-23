/*
 ============================================================================
 Name        : makeRandomGroups.c
 Author      : Flindt
 Version     :
 Copyright   : Do what ever you like with this code :)
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main(void) {
	puts("Random groups ..."); /* prints Random numbers ... */

	// randomize(); // this is neded so different numbers will be generated every time
		/* Simple "srand()" seed: just use "time()" */
		unsigned int iseed = (unsigned int) time(NULL );
		srand(iseed);

	// Get input from user
	// For a first implementaion we cheat and just initialize the variables
	int noStudents = 14;
	int groupSize = 2;

	// Create random list
	int randomList[80];			// Array to hold the list of groups

	int loopCount = 0;			// This variable will count how many students we have put in the array
	int loopCountInner = 0;		// This variable will count the students in each group
	int thisRandomNumber;

	while (loopCount < noStudents) {
		thisRandomNumber = ((unsigned) rand() % noStudents) +1;	// Modulus % will limit the random number to our range
																	// +1 so we can count from 1 in the class
		for (loopCountInner=0; loopCountInner< loopCount; loopCountInner++){
			if (randomList[loopCountInner]==thisRandomNumber) {		// if this number has been used, do not add it twice
				break;
			}
		}
		if (loopCountInner==loopCount) {							// if the loop above has finished this is a new number
			randomList[loopCount]=thisRandomNumber;
			loopCount++;
		}
	}


	// Print output
	for (loopCount = 0; loopCount < noStudents;
			loopCount = loopCount + groupSize) {
		for (loopCountInner = 0;
				(loopCountInner < groupSize)
						&& ((loopCount + loopCountInner) < noStudents);
				loopCountInner++) {
			printf("\t%i", randomList[loopCount + loopCountInner]);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
