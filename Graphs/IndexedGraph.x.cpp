#include "IndexedGraph.h"



int main()
{
	Graph* g = new Graph();
	//g.m_nodes.push_back(list<int>(1,2));
	g->m_nodes.push_back({1, 2});
	g->m_nodes.push_back({0});
	g->m_nodes.push_back({0});

	g->print();

	auto gc = g->clone();

	g->m_nodes.push_back({0});
	g->print();
	delete g;	

	gc->print();

	delete gc;	

	return 0;
}