#pragma once
//eight queen
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
class CQueen
{
private:
	int m_nQueen;
	vector<bool> m_Colomn;			//path�Ѿ�ռ�ݵ���
	vector<bool> m_MainDiagonal;	//path�Ѿ�ռ�ݵ����Խ���
	vector<bool> m_MinorDiagonal;	//path�Ѿ�ռ�ݵĴζԽ���
	vector<vector<int> >m_Answer;	//���ս�

public:
	CQueen(int N);
	~CQueen();
	void OnInit();
	void Queen();
	void CalcNQueen(int* path, int row);
	bool Canlay(int row, int col) const;
	void Print() const
	{
		cout << "���н�ĸ���:" << (int)m_Answer.size() << "\n";
		for (vector<vector<int> >::const_iterator it = m_Answer.begin(); it != m_Answer.end(); it++)
		{
			PrintOne(*it);
		}
	}

	void PrintOne(const vector<int>& v)const
	{
		for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
		{
			cout << *it << '\t';
		}
		cout << "\n";
	}
};

