#pragma once
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
//��ǰ��������ӡ������
class TraverseBinarytree
{
public:
	TraverseBinarytree();
	~TraverseBinarytree();
	void OnInit();
	void InPreToPost(const char* pInOrder, const char* pPreOrder, int nLength, char* pPostOrder, int& nIndex);
};

