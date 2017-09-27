#include "Queen.h"



CQueen::CQueen(int N)
	:m_nQueen(N)
{
	m_Colomn.resize(N, false);
	m_MainDiagonal.resize(2 * N - 1, false);
	m_MinorDiagonal.resize(2 * N - 1, false);
}


CQueen::~CQueen()
{
}

void CQueen::OnInit()
{
	Queen();
	Print();
}

void CQueen::Queen()
{
	int *path = new int[m_nQueen];		//一个可行解
	CalcNQueen(path, 0);
	delete[] path;
}

void CQueen::CalcNQueen(int* path, int row)
{
	if (row == m_nQueen)
	{
		//直接把一维和二维都赋值
		m_Answer.push_back(vector<int>(path, path + m_nQueen));
		return;
	}
	for (int col = 0; col < m_nQueen; col++)
	{
		if (Canlay(row, col))
		{
			path[row] = col;
			m_Colomn[col] = true;
			m_MinorDiagonal[row + col] = true;
			m_MainDiagonal[m_nQueen - 1 + row - col] = true;
			CalcNQueen(path, row + 1);

			//回溯
			m_Colomn[col] = false;
			m_MinorDiagonal[row + col] = false;
			m_MainDiagonal[m_nQueen - 1 + row - col] = false;
		}
	}
}

bool CQueen::Canlay(int row, int col) const
{
	return !m_Colomn[col] && !m_MinorDiagonal[row + col] && !m_MainDiagonal[m_nQueen - 1 + row - col];
}