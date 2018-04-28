#include "UnIndexedGraph.h"



int main()
{
	Graph* g = new Graph();

	using Node = Graph::Node;

	Node* n1 = new Node(1); g->m_nodes.push_back(n1);
	Node* n2 = new Node(2); g->m_nodes.push_back(n2);
	Node* n3 = new Node(3); g->m_nodes.push_back(n3);
	Node* n4 = new Node(4); g->m_nodes.push_back(n4);

	n1->adj.push_back(n2);
	n2->adj.push_back(n3);
	n3->adj.push_back(n4);
	n4->adj.push_back(n1);

	g->print();

	auto gc = g->clone();

    Node* n5 = new Node(4); g->m_nodes.push_back(n5);
	n5->adj.push_back(n1);
	n5->adj.push_back(n2);
	n5->adj.push_back(n3);
	n5->adj.push_back(n4);
	g->print();

	delete g;

	gc->print();

	delete gc;

	return 0;
}