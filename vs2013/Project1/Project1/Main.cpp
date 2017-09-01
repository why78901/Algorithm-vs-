#include "Main.h"
#include "StringRotate.h"
#include "KMPMatch.h"
#include "StringPermutation.h"
#include "Manacher.h"
#include "BruteForceSearch.h"

Main::Main()
{
}


Main::~Main()
{
}

void Main::Start()
{
	//StringRotate
	/*StringRotate *stringRotate = new StringRotate();
	stringRotate->Init();*/

	//StringPermutation
	/*StringPermutation *permutation = new StringPermutation();
	permutation->Init();*/

	//manacher
	/*Manacher *manacher = new Manacher();
	manacher->Init();*/

	//KMPMatch
	KMPMatch *kmpMatch = new KMPMatch();
	kmpMatch->Init();

	//bruteForceSearch
	/*BruteForceSearch * forceSearch = new BruteForceSearch();
	forceSearch->Init();*/
}

