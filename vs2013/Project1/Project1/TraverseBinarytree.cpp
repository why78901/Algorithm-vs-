#include "TraverseBinarytree.h"



TraverseBinarytree::TraverseBinarytree()
{
}


TraverseBinarytree::~TraverseBinarytree()
{
}

void TraverseBinarytree::OnInit()
{
	char pPreOrder[] = "GDAFEMHZ";
	char pInOrder[] = "ADEFGHMZ";
	int size = sizeof(pInOrder) / sizeof(char);
	char* pPostOrder = new char[size];
	int nIndex = 0;
	InPreToPost(pInOrder, pPreOrder, size - 1, pPostOrder, nIndex);
	pPostOrder[size - 1] = 0;
	cout << pPostOrder;
}


void TraverseBinarytree::InPreToPost(const char* pInOrder, const char* pPreOrder, int nLength, char* pPostOrder, int& nIndex)
{
	if (nLength <= 0)
	{
		return;
	}

	if (nLength == 1)
	{
		pPostOrder[nIndex] = *pPreOrder;
		nIndex++;
		return;
	}

	char root = *pPreOrder;
	int nRoot = 0;
	for (; nRoot < nLength; nRoot++)
	{
		if (pInOrder[nRoot] == root)
		{
			break;
		}
	}
	InPreToPost(pInOrder, pPreOrder + 1, nRoot, pPostOrder, nIndex);
	InPreToPost(pInOrder + nRoot + 1, pPreOrder + nRoot + 1, nLength - (nRoot + 1), pPostOrder, nIndex);
	pPostOrder[nIndex] = root;
	nIndex++;
}