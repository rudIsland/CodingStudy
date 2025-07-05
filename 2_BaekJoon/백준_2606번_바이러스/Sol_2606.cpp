#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int result = 0;

void DFS(int node) {
	visited[node] = true; //ù ��� �湮�� true;
		
	for (int i = 0; i < graph[node].size(); i++) {
		int connectNode = graph[node][i]; //����� ���
		if (!visited[connectNode]) {
			DFS(connectNode);
			result++;
		}
	}
}



int main() {

	int com, pair;
	cin >> com >> pair;

	visited.resize(com+1,false);
	graph.resize(com+1);

	//�� �Է�
	for (int i = 0; i < pair; i++) {
		int A, B;
		cin >> A >> B;

		//����� ����
		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	DFS(1); //1���ͽ���


	cout << result;
}