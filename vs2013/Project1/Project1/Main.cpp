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
#include "WordLadder.h"
#include "Queen.h"

Main::Main()
{
}


Main::~Main()
{
}

void Main::Start()
{
	/*HalfFind *halfFind = new HalfFind();
	halfFind->OnInit();*/
	//*/

	/*Huffman *huffman = new Huffman();
	huffman->OnInit();*/

	//±éÀú¶þ²æÊ÷
	/*TraverseBinarytree *tree = new TraverseBinarytree();
	tree->OnInit()*/;

	/*StringRotate *stringRotate = new StringRotate();
	stringRotate->Init();*/

	/*StringPermutation *permutation = new StringPermutation();
	permutation->Init();*/

	/*Manacher *manacher = new Manacher();
	manacher->Init();*/

	//KMPMatch *kmpMatch = new KMPMatch();
	//kmpMatch->Init();

	/*BruteForceSearch * forceSearch = new BruteForceSearch();
	forceSearch->Init();*/

	//HeapSort *heapSort = new HeapSort();
	//heapSort->OnInit();

	QuickSort *quickSort = new QuickSort();
	quickSort->OnInit();

	/*WordLadder *wordLade = new WordLadder();
	wordLade->OnInit();*/

	/*CQueen *cQueen = new CQueen(8);
	cQueen->OnInit();*/
}


