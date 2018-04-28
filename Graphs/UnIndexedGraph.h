#include <bits/stdc++.h>

using namespace std;


struct Graph
{
	struct Node
	{
		Node() = default;
		Node(int d) { data = d;}

		int data;
		list<Node*> adj;
		void print()
		{
			cout << "data : " << data << " adj : ";
			for (auto it : adj)
			{
				cout << it->data << " " ;
			}
			cout << endl;
		}
	};

	list<Node*> m_nodes {};
	~Graph()
	{
		for (auto it : m_nodes)
		{
			delete it;
		}
	}

	void print()
	{
		cout << "graph size : " << m_nodes.size() << endl;
		for (auto it : m_nodes)
		{
			it->print();
		}
	}

	Graph* clone()
	{
		Graph* ret = new Graph();

		map<Node*, Node*> mp;

		for (auto it : m_nodes)
		{
			Node* n = new Node();
			n->data = it->data;
			mp[it] = n;
			ret->m_nodes.push_back(n);
		}

		for (auto it : m_nodes)
		{
			assert (mp.find(it) != mp.end());
			Node* clonednode = mp[it];
			for (auto it1 : it->adj)
			{
				assert(mp.find(it1) != mp.end());
				clonednode->adj.push_back(mp[it1]);
			}
		}

		return ret;
	}
};