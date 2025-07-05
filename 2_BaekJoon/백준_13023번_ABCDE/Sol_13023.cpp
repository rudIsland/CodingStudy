#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph; //ģ������
vector <bool> visited; //�湮 ����
bool arrived = false; //��������

void DFS(int node, int count, int targetCount) {

	if (count == targetCount || arrived) {
		arrived = true;//��ǥ ������� ���������� true
		return;
	}
	visited[node] = true; //�湮������ true��

	//�� ��� �����ŭ ��ȸ
	for (size_t i = 0; i < graph[node].size(); i++) {
		int connectionNode = graph[node][i]; //ģ���� �Ѹ� ������
		if (!visited[connectionNode]) { //ģ���� DFS���
			DFS(connectionNode, count + 1, targetCount);
		}
	}

	//�� DFS��Ϳ��� ī��Ʈ�� ä���� �������� �湮�ߴ� ���� false���Ͽ� �ٽ� �� �� �ְ� ����
	//���� ������� 1 2 / 1 3 ���� 2�湮 �� 3�� Ž������ �ʰԵ�
	visited[node] = false;
}

int main() {

	int N, M; //N�� ģ�� ��
	cin >> N >> M; //M�� ģ�� ����

	graph.resize(N);
	visited = vector<bool>(N, false);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		//��������� ���� ģ������ ����
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