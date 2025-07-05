#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int calLCA(int a, int b);
void BFS(int node);
/*
1. Ž�� �˰���(DFS, BFS)�� ���̸� ����.

2. ���̸� ���߱� ���� �θ� ���� �̵�

3. �θ� ���� ��� �ö󰡸鼭 �ּ� ���� ������ ã�´�.
*/

int treeHeight; //Ʈ�� ����
int N, M;
vector<int> depth, parent;
vector<bool> visited;
vector<vector<int>> tree; //Ʈ��


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	tree.resize(N+1); //1���� �����ϹǷ� +1
	depth.resize(N + 1);
	parent.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < N-1; i++) {
		int s, e;
		cin >> s >> e;
		//����� ����
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	BFS(1); //��Ʈ ��尡 1���� �����̹Ƿ� 1�� Ž��

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int LCA = calLCA(a, b);
		cout << LCA << "\n";
	}
}

int calLCA(int a, int b) {

	// ���� ���߱�
	while (depth[a] > depth[b]) {
		a = parent[a];  // �� ���� ��带 �θ�� �ø�
	}
	while (depth[b] > depth[a]) {
		b = parent[b];  // �ݴ��� ��쵵 ó��
	}

	//���� ���� ���� �� ���� �� ��尡 �Բ� ��ĭ�� �ö�
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

	int level = 1; //����
	int now_size = 1; //���� ���� ũ��
	int count = 0; //���� depth���� � ��带 ó���ߴ��� ī��Ʈ

	while (!que.empty()) {
		int now_node = que.front();
		que.pop();

		for (int next : tree[now_node]) {
			if (!visited[next]) {
				visited[next] = true; //�湮ó��
				que.push(next); //ť�� ����
				parent[next] = now_node;
				depth[next] = depth[now_node] + 1;  // �θ��� ���� + 1
			}
		}
	}

}