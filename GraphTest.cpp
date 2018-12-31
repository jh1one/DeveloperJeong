//#include "UnDirectedGraph.h"
#include "DirectedGraph.h"

int main() {
	int n;
	cin >> n;

	//UndirectedGraph UDGraph(n);

	//for (int i = 0; i < n; i++)
	//{
	//	int v;
	//	cin >> v;
	//	UDGraph.InsertVertex(v);
	//}

	////간선은 자기 자신에게로 향하지 않고, 중복되지 않으므로 최대 개수 = 정점 개수 * 정점 개수 / 2 + 2
	//for (int j = 0; j < (n * (n - 1))/2; j++) {
	//	int s, e;
	//	cin >> s >> e;
	//	if (s == 0 || e == 0)
	//		break;

	//	UDGraph.InsertEdge(s, e);
	//}

	///*for (int k = 1; k <= n; k++)
	//	cout << "정점" << k << "의 차수 : " << UDGraph.Degree(k) << endl;*/

	//UDGraph.BFS(1);
	////UDGraph.DFS(1);

	DirectedGraph digraph(n);

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		digraph.InsertVertex(v);
	}

	for (int j = 0; j < (n * (n - 1))/2; j++) {
		int s, e;
		cin >> s >> e;
		if (s == 0 || e == 0)
			break;

		digraph.InsertEdge(s, e);
	}

	digraph.DFS(0);
}