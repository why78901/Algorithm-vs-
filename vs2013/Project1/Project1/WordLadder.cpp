#include "WordLadder.h"

WordLadder::WordLadder()
{
}


WordLadder::~WordLadder()
{
}

void WordLadder::OnInit()
{
	set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	string start = "hit";
	string end = "cog";
	cout << CalcLadderLength(start, end, dict);
}

int WordLadder::CalcLadderLength(const string& start, const string& end, const set<string>& dict)
{
	queue<string> q;
	q.push(start);
	vector<string> children;	//从当前结点可扩展得到的新节点集合(A new set of nodes that can be extended from the current node)
	set<string> visit;
	int step = 0;
	string cur;
	int curNumber = 1;		//cur layer lave node number
	int nextNumber = 0;		//next layer child node number
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		curNumber--;
		Extend(cur, children, dict, end, visit);
		nextNumber += (int)children.size();
		if (curNumber == 0)		//cur layer foreach finshed,foreach next layer, so step+1
		{
			step++;
			curNumber = nextNumber;
			nextNumber = 0;
		}

		for (vector<string>::const_iterator it = children.begin(); it != children.end(); it++)
		{
			if (*it == end)
				return step;
			q.push(*it);
		}
	}
	return 0;
}

void WordLadder::Extend(const string& cur, vector<string>& children, const set<string>& dict, const string& end, set<string>& visit)
{
	string child = cur;
	children.clear();
	int i;
	char c, t;
	for ( i = 0; i < (int)cur.size(); i++)
	{
		t = child[i];
		for ( c = 'a'; c != 'z'; c++)
		{
			if (c == t)
			{
				continue;
			}
			child[i] = c;
			
			if (((child == end) || (dict.find(child) != dict.end())) && (visit.find(child) == visit.end()))
			{
				children.push_back(child);
				visit.insert(child);
			}
		}
		child[i] = t;
	}
}
