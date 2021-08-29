/*
 * production.c
 *
 *  Created on: Feb 6, 2021
 *      Author: theresesmith
 */

#include "production.h"
#include <stdio.h>

bool production(int argc, char* argv[])
{
	bool answer = true;
	char string4Search[MAXSTRINGLENGTH+1];
	bzero(string4Search, MAXSTRINGLENGTH+1);
	int foundStringLength = -1; //initialize to obviously wrong value

		if(argc <= 1) //no interesting information
		{
			puts("Didn't find any arguments.");
			fflush(stdout);
			answer = false;
		}
		else //there is interesting information
		{
			printf("Found %d arguments.\n", argc);
			fflush(stdout);

			for(int i = 1; i < argc; i++) //don't want to read argv[0]
			{	//argv[i] is a string
				//in this program our arguments are a filename followed by the max of rooms, followed by max of treasur3
				switch(i)
				{
				case 1:
					foundStringLength = lengthDetermination(argv[i]);
					if(foundStringLength > 0) {
						strcpy(string4Search,argv[i]);
					} else {
						return false;	
					} 				
					break;
				default:
					puts("Unexpected argument count."); fflush(stdout);
					answer = false;
					break;
				} //end of switch
			} //end of for loop on argument count
			puts("after reading arguments"); fflush(stdout);
		} //end of command line arguments

		//now that we have our input,
		//what is to be done:

		int resultsArr[foundStringLength-1];
		for(int i = 0; i < foundStringLength-1; i++) 
		{
			resultsArr[i] = 0;
		}

		substringExtraction(string4Search, resultsArr);

	    //print output
		printout(foundStringLength, resultsArr);		

		return answer;
}

bool getYesNo(char* query) {
   bool answer = true; //so far
   char said = 'x';
   while((said != 'y') && (said != 'n')) {
       printf("%s (y/n):",query);
       fflush(stdout);
       scanf("%s",&said);
   }
   if(said == 'n') {
	   answer = false;
   } else if(said == 'y') {
       answer = true;
   } 
   // answer flips for some reason. buffer issue or could be the scanf im not sure
   // extra check for y is put as a temporary fix although it does function correctly
   /* if(answer == false) { */
   /*     printf("answer is false\n"); */
   /* } */
   return answer;
}

void substringExtraction(char* whole, int* results)
{
	int theLength = strlen(whole);
	char target[theLength+1];
	bzero(target, theLength+1);
	char query[100];
	bzero(query, 100);
	for(int size = 1; size<=theLength-1; size++)
	{
		int howMany = theLength-size+1;
		printf("There are %d substrings of length %d.\n", howMany, size);
		for(int startS = 0; startS < theLength-size+1; startS++)
		{
		    //The substrings should be extracted.
			strncpy(target, whole+startS, size);
		    //then ask the user whether those substrings are words
			sprintf(query, "Is |%s| a word?\n", target);
			if(getYesNo(query)) //if the user says yes, increment the appropriate location in the results array
			{
				//the user said yes
				//TODO: add to the results
                results[size-1]++;
			}
		}
	}
}

int lengthDetermination(char* inputString)
{
	int	stringLength = strlen(inputString);

	//this is the string to be searched
	if (stringLength > MAXSTRINGLENGTH)
	{
		puts("Input string has length greater than max length");
		fflush(stdout);
		stringLength = -1;
	} else if (stringLength <= 0) {
		puts("Input string has length less than one");
		fflush(stdout);
		stringLength = -1;
	} else {
		printf("Length of input string is %d\n",stringLength);
		fflush(stdout);
	}
	return stringLength;
}

void printout(int stringLength, int *results) {
	puts("\nResults:");
	for(int i = 0; i < stringLength-1; i++) {
		printf("%d words of length %d\n", results[i], i+1);
	}
}

