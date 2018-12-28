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
	virtual bool ExistsEdge(int u, int n) const = 0;	//�Ļ� Ŭ������ �׷��� ǥ����������� Edge Ȯ�� ����� �޶����Ƿ� �����Լ��� ����
	virtual void InsertVertex(int v) = 0;
	virtual void InsertEdge(int u, int v) = 0;
	//virtual void DeleteVertex(int v) = 0;				//������ �׷��� ǥ�� ��������� ���� ����� �ٲ�.
	//virtual void DeleteEdge(int u, int v) = 0;

private :
	int n;
	int e;
};