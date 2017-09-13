#pragma once
#include<iostream>
#include<vector>
using namespace std;
struct HuffmanNode
{
	int nWeight;
	int nParent;
	int nLeft;
	int nRight;

	HuffmanNode()
	{
		nWeight = 0;
		nParent = 0;
		nLeft = 0;
		nRight = 0;
	}
};
//¹þ·òÂü±àÂë
class Huffman
{
public:
	Huffman();
	~Huffman();
	void OnInit();
	void HuffmanCoding(int *pWeight, int N, vector<vector<char> >& code);

private:
	void SelectNode(const HuffmanNode* pHuffmanTree, int n, int& s1, int &s2);
	void CalcFrequency(const char* str, int *pWeight);
	void CalcExistChar(int* pWeight, int N, vector<int>& pChar);
	void PrintCode(char c, vector<char>& code);
	void Print(vector<vector<char> >& code, vector<int>& pChar);
};

