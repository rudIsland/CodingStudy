#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph; //친구관계
vector <bool> visited; //방문 여부
bool arrived = false; //도착여부

void DFS(int node, int count, int targetCount) {

	if (count == targetCount || arrived) {
		arrived = true;//목표 관계까지 도달했으면 true
		return;
	}
	visited[node] = true; //방문했으니 true로

	//각 노드 사이즈만큼 순회
	for (size_t i = 0; i < graph[node].size(); i++) {
		int connectionNode = graph[node][i]; //친구를 한명씩 가져옴
		if (!visited[connectionNode]) { //친구면 DFS재귀
			DFS(connectionNode, count + 1, targetCount);
		}
	}

	//위 DFS재귀에서 카운트를 채우지 못했으면 방문했던 노드는 false로하여 다시 갈 수 있게 설정
	//하지 않을경우 1 2 / 1 3 에서 2방문 후 3을 탐색하지 않게됨
	visited[node] = false;
}

int main() {

	int N, M; //N은 친구 수
	cin >> N >> M; //M은 친구 관계

	graph.resize(N);
	visited = vector<bool>(N, false);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		//양방향으로 서로 친구임을 설정
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		DFS(i, 1, 5);
	}

	if (arrived)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}