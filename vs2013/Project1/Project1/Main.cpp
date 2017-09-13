#include "Main.h"
#include "StringRotate.h"
#include "KMPMatch.h"
#include "StringPermutation.h"
#include "Manacher.h"
#include "BruteForceSearch.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "HalfFind.h"
#include "Huffman.h"
#include "TraverseBinarytree.h"


Main::Main()
{
}


Main::~Main()
{
}

void Main::Start()
{
	//*Find 
	/*HalfFind *halfFind = new HalfFind();
	halfFind->OnInit();*/
	//*/

	//huffman
	/*Huffman *huffman = new Huffman();
	huffman->OnInit();*/

	//±éÀú¶þ²æÊ÷
	TraverseBinarytree *tree = new TraverseBinarytree();
	tree->OnInit();

	//StringRotate
	/*StringRotate *stringRotate = new StringRotate();
	stringRotate->Init();*/

	//StringPermutation
	/*StringPermutation *permutation = new StringPermutation();
	permutation->Init();*/

	//manacher
	/*Manacher *manacher = new Manacher();
	manacher->Init();*/

	////KMPMatch
	//KMPMatch *kmpMatch = new KMPMatch();
	//kmpMatch->Init();

	//bruteForceSearch
	/*BruteForceSearch * forceSearch = new BruteForceSearch();
	forceSearch->Init();*/

	//HeapSort
	//HeapSort *heapSort = new HeapSort();
	//heapSort->OnInit();

	//QuickSort
	/*QuickSort *quickSort = new QuickSort();
	quickSort->OnInit();*/
}


