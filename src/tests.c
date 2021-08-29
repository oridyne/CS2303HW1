/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include <stdbool.h>



bool tests()
{
	bool allOK = true; //so far, so good

	//test the functions that get used
	//order the tests from simplest first -- this produces building blocks for use in more complex tests
	//check how functions are used in production code, this gives clues about how to provide the arguments for the invocation
	bool ok1 = testLengthDetermination();
	bool ok2 = testSubstringExtraction();
	bool ok3 = testPrintout();
	allOK = ok1 && ok2 && ok3;
	return allOK;
}

bool testLengthDetermination()
{
	bool test1 = true; //so far
	bool test2 = true;

	char* inputTest1 = "";
	if(lengthDetermination(inputTest1) != -1 ) {
		test1 = false;
	}
	char inputTest2[MAXSTRINGLENGTH+1];
	for(int i = 0; i < MAXSTRINGLENGTH; i++) {
		inputTest2[i] = 'a';
	}
	if(lengthDetermination(inputTest2) != -1) {
		test2 = false;
	}
	
	bool answer = test1 && test2;
	
	if(answer) {
		puts("testLengthDetermination passed");
	} else {
		puts("testLengthDetermination failed");
	}
	
	return answer;
}

bool testSubstringExtraction()
{
	bool answer = true; //so far

	char* whole = "Gita";
	int itsLength = strlen(whole)-1;
	int resultsArray[itsLength]; //remembers how many words of that length are found
	for(int i = 0; i<itsLength; i++)
	{
		resultsArray[i]=0;
	}
	//what is the right answer?
	//contained words are (though we depend upon the human to tell us):
	//it
	//a

	puts("we should see:");
	puts("4 trials of length 1");
	puts("3 trials of length 2");
	puts("2 trials of length 3");

	//what answer does the function get?
	substringExtraction(whole, resultsArray);

	if(getYesNo("Did the program get the right answer?"))
	{
		puts("testSubstringExtraction passed.");
	}
	else
	{
		puts("testSubstringExtraction failed.");
		answer = false;
	}

	return answer;
}

bool testPrintout()
{
	bool answer = true; //so far
	// 5 letter word
	puts("We should see:");
	puts("4 words of length 1");
	puts("2 words of length 2");
	puts("1 words of length 3");
	puts("2 words of length 4");
	int resultsArray[4] = {4, 2, 1, 2};

	printout(5, resultsArray);

	if(getYesNo("Is this printout correct?")) {
		puts("testPrintout passed");
	} else {
		puts("testPrintout failed");
		answer = false;
	}
	return answer;
}
