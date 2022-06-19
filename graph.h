#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
typedef unsigned long int ID;
using namespace std;
class graph
{
public:
 	class node
	{
	public:
		vector<ID> neighbours;
	};
	//end of class nested node
	//attr
	vector<node> NODES;
	

	//ctors
	graph(unsigned long int numOfnodes, unsigned long int prob) : NODES(numOfnodes)
	{
		srand(time(NULL));
		for (unsigned long int curnode = 0; curnode < numOfnodes; ++curnode)
		{
			for (unsigned long int curneighbor = 0; curneighbor < numOfnodes; ++curneighbor)
			{
				if (float(rand()) / (RAND_MAX) <= prob)
				{
					NODES[curnode].neighbours.push_back(curneighbor);
				}
			}
		}
	}
	graph(unsigned long int numOfnodes, bool firstGraph) : NODES(numOfnodes)
	{
		vector<float> probs(numOfnodes);
		for (unsigned long int i = 0; i < numOfnodes; ++i) 
		{
			if (firstGraph)
			{
				probs[i]=float(1 / (i + 1));
			}
			else
			{
				probs[i] = float(1 / sqrt(i + 1));
			}
		}

		for (unsigned long int curnode = 0; curnode < numOfnodes; ++curnode) // i
		{
			for (unsigned long int curneighbor = 0; curneighbor < numOfnodes; ++curneighbor) // j
			{
				if (float(rand()) / (RAND_MAX) <= probs[curneighbor])
				{
					NODES[curnode].neighbours.push_back(curneighbor);
				}
			}
		}
	}

	//func
	vector<double> pageRank(unsigned long long WalkLength/*N*/, unsigned long long numOfIterations/*t*/, float probToRandomNode/*p*/)
	{
		unsigned int size = NODES.size();
		vector<double> rankingVector(size,0);//default set to zero?
		for (unsigned long long i = 0; i < numOfIterations; ++i)
		{
			++rankingVector[randomWalk(WalkLength,probToRandomNode)];
		}
		transform(rankingVector.begin(), rankingVector.end(), rankingVector.begin(), [size](double& ver) { return ver / size; });

		return rankingVector;
	}
	unsigned int randomWalk(unsigned long long WalkLength/*N*/, float probToRandomNode/*p*/)
	{
		unsigned int curnode = 0,numofnodes =  NODES.size();

		for (unsigned long long curstep = 0; curstep < WalkLength; ++curstep)
		{
			if (float(rand()) / (RAND_MAX) <= probToRandomNode ) // P
			{
				curnode = rand() % numofnodes;
			}
			else
			{

			}
			{
				if (NODES[curnode].neighbours.size() == 0)
				{
					if (float(rand()) / (RAND_MAX) <= probToRandomNode)
					{
						curnode = rand() % numofnodes;
					}
				}
				else
				{
					curnode = NODES[curnode].neighbours[rand() % NODES[curnode].neighbours.size()];
				}
				
			}
		}
		return curnode;
	}
	
};

