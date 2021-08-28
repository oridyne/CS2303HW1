/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"



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
	bool answer = true; //so far

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

	return answer;
}
