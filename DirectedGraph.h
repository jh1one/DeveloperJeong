#pragma once
#include "Graph.h"
#include <queue>
#include <stack>
#include <list>
#include <vector>

class DirectedGraph;
class Vertex {
	friend class DirectedGraph;
public:
	void Visit() {
		cout << data << " " << "�Ÿ� : " << distance << endl;
		visited = true;
	}
private:
	int data;
	list<int> adjacency;
	Vertex* predecessor;
	int distance;
	bool visited;
	int degree;
};

//��������Ʈ�� ǥ��
class DirectedGraph : protected Graph {
public:
	DirectedGraph(int size) {
		capacity = size;
		vertices.reserve(capacity);
	}
	~DirectedGraph() { };

	virtual int Degree(int u) const { return vertices[u].degree; }

	virtual bool ExistsEdge(int u, int v)
	{
		for (int i = 0; i < vertices[u].degree; i++) {
			list<int>::iterator it = vertices[u].adjacency.begin();
			if (*it == v)
				return true;
			it++;
		}
		return false;
	}

	virtual void InsertVertex(int v) {
		Vertex newVertex;
		newVertex.data = v;
		newVertex.degree = 0;
		newVertex.adjacency.clear();

		vertices.push_back(newVertex);
		AddNumberOfVertices();
	}

	//�� �� ����غ����� ��. ������ ����� �ε����� ������ ��Ī�� �ٸ��� �� ��� ��� ȿ�������� ���ϴ� ������ ã�Ƴ���...?
	virtual void InsertEdge(int u, int v) {
		int NumOfE = NumberOfEdges();

		vertices[u - 1].adjacency.push_back(v - 1);
		vertices[u - 1].degree++;

		vertices[v - 1].adjacency.push_back(u - 1);
		vertices[v - 1].degree++;

		AddNumberOfEdges();
	}

	void BFS(int start) {
		//�ʱ�ȭ
		for (int i = 0; i < capacity; i++) {
			vertices[i].distance = INFINITY;
			vertices[i].visited = false;
			vertices[i].predecessor = NULL;
		}

		vertices[start].distance = 0;
		vertices[start].Visit();

		queue<Vertex> graphQ;
		graphQ.push(vertices[start]);

		while (!graphQ.empty()) {
			Vertex s = graphQ.front();
			graphQ.pop();
			list<int>::iterator begin_it = s.adjacency.begin();
			for (int i = 0; i < s.degree; i++) {
				if (!vertices[*begin_it].visited)
				{
					vertices[*begin_it].distance = s.distance + 1;
					vertices[*begin_it].predecessor = &s;
					vertices[*begin_it].Visit();
					graphQ.push(vertices[*begin_it]);
				}
				begin_it++;
			}
		}
	}

	void DFS(int start) {
		for (int i = 0; i < capacity; i++) {
			vertices[i].distance = INFINITY;
			vertices[i].visited = false;
			vertices[i].predecessor = NULL;
		}

		vertices[start].distance = 0;

		stack<Vertex*> graphS;
		graphS.push(&vertices[start]);

		while (!graphS.empty()) {
			Vertex* s = graphS.top();
			
			if(!s->visited)
				s->Visit();

			//graphS.pop();
			if (s->degree > 0) {
				list<int>::iterator begin_it = s->adjacency.begin();
				int i;
				for (i = 0; i < s->degree; i++) {
					if (!vertices[*begin_it].visited) {
						vertices[*begin_it].predecessor = s;
						vertices[*begin_it].distance = s->distance + 1;
						graphS.push(&vertices[*begin_it]);
						break;
					}
					begin_it++;
				}

				if (i >= s->degree)
					graphS.pop();
			}
			else
				graphS.pop();
		}
	}

	//void DeleteVertex(int v)
	//{
	//	
	//	
	//}

	//void DeleteEdge(int u, int v) {
	//for (int i = 0; i < n; i++) {
	//		for (int j = i; j < n; j++)
	//			if (i == v || j == v)
	//				edges[i][j] = 0;
	//	}
	//}

private:
	vector<Vertex> vertices; //����׷����� ��������Ʈfmf ����ϴ� ���� ȿ�����̹Ƿ� ����Ʈ�� ǥ��
	int capacity;
};
