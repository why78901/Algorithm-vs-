#pragma once
//单词变换问题
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
class WordLadder
{
public:
	WordLadder();
	~WordLadder();
	void OnInit();

private:
	int CalcLadderLength(const string& start, const string& end, const set<string>& dict);
	
	//search cur child node ,save in childern 
	void Extend(const string& cur, vector<string>& children, const set<string>& dict, const string& end, set<string>& visit);
};

