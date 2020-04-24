#pragma once
#include "Sorting.h"

using namespace std;

class Ascending
{
public:
	bool operator()(const int& p, const int& q) const
	{
		return p < q;
	}
	bool operator()(const string& p, const string& q) const
	{
		int p1 = stoi(p);
		int q1 = stoi(q);
		return p1 < q1;
	}
};