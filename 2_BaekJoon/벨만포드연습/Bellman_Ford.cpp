#include <vector>
#include <iostream>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dist;


const int INF = 9999999; //�ִ밪 ����

/*
6 8
1 2 5
1 3 2
2 4 3
2 5 2
3 5 6
4 6 1
5 6 4
6 2 -10
*/
void Bellman_Ford(int start, int end) {
	dist[start] = 0; //��� ��� ��� 0

	for (int i = 0; i < dist.size()-1; i++) {
		//dist�� �ϳ��� ��� ����Ŵ.

		//�׷����� �ϳ��� ��� Ž��
		for (int j = 0; j < graph.size(); j++) {
			if (dist[j] == INF) continue; //�ش� ��尡 ����� INF�� �ǳʶٱ�

			for (int k = 0; k < graph[j].size(); k++) {
				int now = graph[j][k].first; //����� ���
				int cost = graph[j][k].second; //����� ���� ���� ���

				if (dist[now] > dist[j] + cost) //���� ��� ����� ���� ����+��뺸�� ������
					dist[now] = dist[j] + cost; //�ּҺ�� ����
			}
		}

	}
	
	/* ���� ����Ŭ �˻�
	�̹� �ִ� ��ΰ� �������µ� ����� ��� �۾����µ� Ȯ���ϴ� ����.
	���� �۾����ٸ� ��������Ŭ(���鼭 ��� ����� �پ��� ����)�� �����Ѵ� ���̹Ƿ� 
	�˰��� �ǹ̰� ������.
	*/
	for (int j = 0; j < graph.size(); j++) {
		if (dist[j] == INF) continue;

		for (int k = 0; k < graph[j].size(); k++) {
			int now = graph[j][k].first;
			int cost = graph[j][k].second;

			if (dist[now] > dist[j] + cost) {
				cout << "���� ����Ŭ ����.\n";
				return;
			}
		}
	}

	// ��� ���
	if (dist[end] == INF) {
		cout << "-1\n"; // ���� �Ұ���
	}
	else {
		cout << "Minimum cost: " << dist[end] << "\n";
	}
}


int main() {
	int N, M; //N: ��� M: ����(����)
	cin >> N >> M;

	graph.resize(N);
	dist.resize(N, INF);

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		A--; B--;
		graph[A].push_back({ B,C });
	}

	int start = 3; int end = 6;
	Bellman_Ford(start-1, end-1);

}