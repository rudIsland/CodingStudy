#include <iostream>
#include <vector>

using namespace std;

const int INF = 999999; // ���Ѵ� �� (������ �� ���� �Ÿ�)

vector<bool> visited; // �湮 ���θ� �����ϴ� �迭
vector<int> dist; // �ִ� �Ÿ� �迭
vector<vector<pair<int, int>>> Node; // �׷��� ���� ����Ʈ (����� ���, �Ÿ�)

int N, M; // N: ��� ����, M: ���� ����
/*
N,M�� �ּ�1, �ִ� 50,000
������ ����� ����̰� NlogM���� ����� 1�� �Ʒ��̹Ƿ� ���ͽ�Ʈ�� �˰��� ����.
*/


int Dijkstra(int start, int end) {
	//��� ��带 �ִ������� �ʱ�ȭ
	for (int i = 0; i < N; i++)
		dist[i] = INF;

	dist[start] = 0; //��� ���� ��� 0����

	for (int i = 0; i < N; i++) {
		int minDist = INF; //���� ���� ª�� �Ÿ��� ������ ����
		int now = -1; //���� ���õ� ��带 ������ ����

		//�湮���� ���� ��� �� �ִܰŸ��� ���� ���� ��� ����
		for (int j = 0; j < N; j++) {
			if (!visited[j] && dist[j] < minDist) {
				minDist = dist[j]; //�ִܰŸ� ����
				now = j; //���� ��� ������Ʈ
			}
		}

		if (now == -1)break; //�湮�� ��尡 ������ ����

		visited[now] = true; //�湮������ �湮ó��

		for (int j = 0; j < Node[now].size(); j++) {
			int nextNode = Node[now][j].first;
			int cost = Node[now][j].second;

			if (!visited[nextNode] && dist[nextNode] > dist[now] + cost) {
				dist[nextNode] = dist[now] + cost; //�ִ� �Ÿ� ����
			}
		}
	}

	// ���������� ������(end)������ �Ÿ��� ��ȯ
	if (dist[end] == INF) {
		return -1; // ������ �� ���� ��� -1 ��ȯ
	}
	else {
		return dist[end]; // �ִ� �Ÿ� ��ȯ
	}
}

int main() {
	cin >> N >> M;

	visited.resize(N, false);
	dist.resize(N, INF);
	Node.resize(N);

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		A--; B--;

		Node[A].push_back({ B, C });
		Node[B].push_back({ A, C });
	}


	int count = Dijkstra(0, N - 1);

	cout << "�ִ� �Ÿ�: " << count << endl;
}