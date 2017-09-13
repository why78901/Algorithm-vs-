#pragma once
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
//用前序和中序打印出后续
class TraverseBinarytree
{
public:
	TraverseBinarytree();
	~TraverseBinarytree();
	void OnInit();
	void InPreToPost(const char* pInOrder, const char* pPreOrder, int nLength, char* pPostOrder, int& nIndex);
};

