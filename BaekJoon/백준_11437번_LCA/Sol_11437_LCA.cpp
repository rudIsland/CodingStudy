#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int calLCA(int a, int b);
void BFS(int node);
/*
1. 탐색 알고리즘(DFS, BFS)로 깊이를 구함.

2. 깊이를 맞추기 위해 부모 노드로 이동

3. 부모 노드로 계속 올라가면서 최소 공통 조상을 찾는다.
*/

int treeHeight; //트리 높이
int N, M;
vector<int> depth, parent;
vector<bool> visited;
vector<vector<int>> tree; //트리


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	tree.resize(N+1); //1부터 시작하므로 +1
	depth.resize(N + 1);
	parent.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < N-1; i++) {
		int s, e;
		cin >> s >> e;
		//양방향 삽입
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	BFS(1); //루트 노드가 1부터 시작이므로 1로 탐색

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int LCA = calLCA(a, b);
		cout << LCA << "\n";
	}
}

int calLCA(int a, int b) {

	// 깊이 맞추기
	while (depth[a] > depth[b]) {
		a = parent[a];  // 더 깊은 노드를 부모로 올림
	}
	while (depth[b] > depth[a]) {
		b = parent[b];  // 반대의 경우도 처리
	}

	//같은 조상 나올 때 까지 두 노드가 함께 한칸씩 올라감
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}


void BFS(int node) {
	queue<int> que;
	que.push(node);
	visited[node] = true;
	depth[node] = 0;   
	parent[node] = 0;    

	int level = 1; //깊이
	int now_size = 1; //현재 깊이 크기
	int count = 0; //현재 depth에서 몇개 노드를 처리했는지 카운트

	while (!que.empty()) {
		int now_node = que.front();
		que.pop();

		for (int next : tree[now_node]) {
			if (!visited[next]) {
				visited[next] = true; //방문처리
				que.push(next); //큐에 삽입
				parent[next] = now_node;
				depth[next] = depth[now_node] + 1;  // 부모의 깊이 + 1
			}
		}
	}

}