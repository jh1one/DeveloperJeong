#pragma once
#include "Graph.h"
#include <queue>
#include <vector>

class UndirectedGraph;
class Vertex {
	friend class UndirectedGraph;
public:
	void Visit() {
		cout << data << " " << "거리 : " << distance << endl;
		visited = true;
	}
private:
	int data;
	Vertex* predecessor;
	int distance;
	bool visited;
	int degree;
};

//인접행렬로 표현
class UndirectedGraph : protected Graph{
public:
	UndirectedGraph(int size) {
		capacity = size;
		vertices.reserve(capacity);
		edges = new int*[capacity];
	}
	~UndirectedGraph() { };

	virtual int Degree(int u) const
	{
		for (int i = 0; i < NumberOfVertices(); i++) {
			if (vertices[i].data == u) return vertices[i].degree;
		}

		cout << "There is not Vertex" << u << endl;
		return 0;
	}

	virtual bool ExistsEdge(int u, int v) const { return edges[u][v] > 0 ? true : false; }

	virtual void InsertVertex(int v) {
		int NumOfV = NumberOfVertices();
		//입력한 정점 개수보다 더 많은 정점이 입력될 때 정점리스트 크기 증가 > 그러나 애초에 입력을 정점 개수만큼만 받게하면 해결
		//if (NumOfV + 1 > capacity) {
		//	Vertex* temp = new Vertex[capacity * 2];
		//	memcpy(&temp[0], &vertices[0], sizeof(int) * NumOfV);
		//	delete[] vertices;
		//	vertices = temp;
		//}

		Vertex newVertex;
		newVertex.data = v;
		newVertex.degree = 0;

		vertices.push_back(newVertex);
		edges[v] = (int*)calloc(capacity, sizeof(int));
		AddNumberOfVertices();
	}

	//이 때 고려해봐야할 점. 정점이 저장될 인덱스와 정점의 명칭을 다르게 할 경우 어떻게 효율적으로 원하는 정점을 찾아낼지...?
	virtual void InsertEdge(int u, int v) {
		int NumOfE = NumberOfEdges();
		
		if (!edges[u][v] && !edges[v][u]) {
			edges[u][v] = 1;
			edges[v][u] = 1;
		}
		
		vertices[u].degree++;
		vertices[v].degree++;

		AddNumberOfEdges();
	}

	void BFS(int start) {
		//초기화
		for (int i = 1; i < capacity; i++) {
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
			for (int i = s.data; i <= NumberOfVertices(); i++) {
				if (edges[s.data][i] > 0 && !vertices[i].visited) {
					vertices[i].predecessor = &s;
					vertices[i].distance = s.distance + 1;
					vertices[i].Visit();
					graphQ.push(vertices[i]);
				}
			}
			for (int j = 1; j < s.data; j++) {
				if (edges[j][s.data] > 0 && !vertices[j].visited) {
					vertices[j].predecessor = &s;
					vertices[j].distance = s.distance + 1;
					vertices[j].Visit();
					graphQ.push(vertices[j]);
				}
			}
		}
	}

	/*void DFS(int start) {
		for (int i = 1; i < capacity; i++) {
			vertices[i].distance = INFINITY;
			vertices[i].visited = false;
			vertices[i].predecessor = NULL;
		}

		vertices[start].distance = 0;
		vertices[start].Visit();

		stack<Vertex> graphS;
		graphS.push(vertices[start]);

		while (!graphS.empty()) {
			Vertex* s = &graphS.top();
			graphS.pop();
	
			for (int i = s->data + 1; i < capacity; i++) {
				if (edges[s->data][i]) {
					vertices[i].distance = vertices[s->data].distance + 1;
					vertices[i].predecessor = s;
					vertices[i].Visit();

					graphS.push(vertices[i]);
				}
			}
		}
	}*/

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
	vector<Vertex> vertices;
	int** edges;	//무방향그래프는 인접리스트보다 인접 행렬을 사용하는 것이 효율적...?
	int capacity;
};
