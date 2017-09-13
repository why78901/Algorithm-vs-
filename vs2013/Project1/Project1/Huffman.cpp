#include "Huffman.h"



Huffman::Huffman()
{
}


Huffman::~Huffman() 
{
}

void Huffman::OnInit()
{
	const int N = 256;
	char str[] = "when I was young Id listen to the radio\waiting for my foavorite songs\when they play Id sing along\it make me smile.";
	int pWeight[N] = { 0 };
	CalcFrequency(str, pWeight);

	//cout << "\n";
	//for (int i = 0; i < N; i++)
	//{
	//	cout << pWeight[i] << " ";
	//}

	pWeight['\t'] = 0;
	vector<int> pChar;
	CalcExistChar(pWeight, N, pChar);
	cout << "\n";
	int N2 = (int)pChar.size();
	vector<vector<char> > code(N2);
	HuffmanCoding(pWeight, N2, code);
	Print(code, pChar);
}


void Huffman::CalcFrequency(const char* str, int *pWeight)
{
	while (*str)
	{
		cout << pWeight[*str]++ << " ";
		str++;
	}
}

void Huffman::CalcExistChar(int* pWeight, int N, vector<int>& pChar)
{
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		if (pWeight[i] != 0)
		{
			pChar.push_back(i);
			if (j != i)
			{
				pWeight[j] = pWeight[i];
			}
			j++;
		}
		//cout << pWeight[i] << " ";
	}
}

void Huffman::SelectNode(const HuffmanNode* pHuffmanTree, int n, int& s1, int &s2)
{
	s1 = -1;
	s2 = -1;
	int nMin1 = -1;
	int nMin2 = -1;
	for (int i = 0; i < n; i++)
	{
		if ((pHuffmanTree[i].nParent == 0) && (pHuffmanTree[i].nWeight > 0))
		{
			if ((s1 < 0) || (nMin1 > pHuffmanTree[i].nWeight))
			{
				s2 = s1;
				nMin2 = nMin1;
				s1 = i;
				nMin1 = pHuffmanTree[s1].nWeight;
			}
			else if ((s2 < 0) || (nMin2 > pHuffmanTree[i].nWeight))
			{
				s2 = i;
				nMin2 = pHuffmanTree[s2].nWeight;
			}
		}
	}
}

void Huffman::HuffmanCoding(int *pWeight, int N, vector<vector<char> >& code)
{
	if (N <= 0)
		return;

	int m = 2 * N - 1;
	HuffmanNode* pHuffmanTree = new HuffmanNode[m];
	int s1, s2;

	int i;
	for (i = 0; i < N; i++)
		pHuffmanTree[i].nWeight = pWeight[i];

	//每次选择权值最小的两个结点,建树
	for (i = N; i < m; i++)
	{
		SelectNode(pHuffmanTree, i, s1, s2);
		pHuffmanTree[s1].nParent = pHuffmanTree[s2].nParent = i;
		pHuffmanTree[i].nLeft = s1;
		pHuffmanTree[i].nRight = s2;
		pHuffmanTree[i].nWeight = pHuffmanTree[s1].nWeight + pHuffmanTree[s2].nWeight;
	}

	//根据建好的Huffman树从叶子到根计算每个叶节点的编码
	int node, nParent;
	for (i = 0; i < N; i++)
	{
		vector<char>& cur = code[i];
		node = i;
		nParent = pHuffmanTree[node].nParent;
		while (nParent != 0)
		{
			if (pHuffmanTree[nParent].nLeft == node)
			{
				cur.push_back('0');
			}
			else
			{
				cur.push_back('1');
			}

			node = nParent;
			nParent = pHuffmanTree[node].nParent;
		}
		reverse(cur.begin(), cur.end());
	}
}

void Huffman::PrintCode(char c, vector<char>& code)
{
	cout << (int)c << "   " << c << ":   ";
	for (vector<char>::iterator it = code.begin(); it != code.end(); it++)
	{
		cout << *it;
	}
	cout << '\n';
}

void Huffman::Print(vector<vector<char> >& code, vector<int>& pChar)
{
	int size = (int)code.size();
	for (int i = 0; i < size; i++)
	{
		PrintCode(pChar[i], code[i]);
	}
}