
#include <iostream>
#include "graph.h"

void main()
{
	graph G1(pow(2,18), true);
	vector<double> rank = G1.pageRank(pow(2, 18), 100, 1 /pow(2,6));
	sort(rank.begin(), rank.end());
	for (int i = 0 ; i < G1.NODES.size();++i)
		cout << rank[i]<<" - W - ";
}