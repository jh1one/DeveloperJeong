#pragma once
#include <iostream>
using namespace std;

class Graph {
public :
	Graph() {
		int n = 0;
		int e = 0;
	}
	virtual ~Graph(){}
	bool IsEmpty() const { return n == 0; }
	int NumberOfVertices() const { return n; }
	int NumberOfEdges() const { return e; }
	void AddNumberOfVertices() { n++; }
	void AddNumberOfEdges() { e++; }

	virtual int Degree(int u) const = 0;
	virtual bool ExistsEdge(int u, int n) const = 0;	//파생 클래스의 그래프 표현방법에따라 Edge 확인 방법이 달라지므로 가상함수로 구현
	virtual void InsertVertex(int v) = 0;
	virtual void InsertEdge(int u, int v) = 0;
	//virtual void DeleteVertex(int v) = 0;				//삭제도 그래프 표현 방법에따라 구현 방식이 바뀜.
	//virtual void DeleteEdge(int u, int v) = 0;

private :
	int n;
	int e;
};