#pragma once
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
class CPoint
{
public:
	CPoint();
	~CPoint();
	char cityName;
	float distance;
	static float Distance(CPoint point1, CPoint point2);

};

CPoint::CPoint()
{
}

CPoint::~CPoint()
{
}

float CPoint::Distance(CPoint point1, CPoint point2)
{
	return point1.distance * point1.distance + point2.distance * point2.distance;
}



class AStar
{
public:
	AStar();
	~AStar();
	void AStarSearch(const vector<vector<float> >& graph, int start, int end, const vector<CPoint>& p);
};

