#include <bits/stdc++.h>

using namespace std;

struct Graph
{
	using vlist_t = std::list<int>;
	vector<vlist_t> m_nodes;
	Graph* clone();
	void print();
};

Graph* Graph::clone()
{
	Graph* ret = new Graph();

	for(auto it : m_nodes)
	{
		ret->m_nodes.push_back(it);
	}
	return ret;
}

void Graph::print()
{
	for(auto it : m_nodes)
	{
		for (auto it1 : it)
		{
			cout << it1 << " " ;
		}
		cout << endl;
	}
}