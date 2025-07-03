#include <iostream>
#include <vector>

using namespace std;

const int INF = 999999; // 무한대 값 (도달할 수 없는 거리)

vector<bool> visited; // 방문 여부를 저장하는 배열
vector<int> dist; // 최단 거리 배열
vector<vector<pair<int, int>>> Node; // 그래프 인접 리스트 (연결된 노드, 거리)

int N, M; // N: 노드 개수, M: 간선 개수
/*
N,M은 최소1, 최대 50,000
간선의 비용이 양수이고 NlogM으로 비용이 1억 아래이므로 다익스트라 알고리즘에 적합.
*/


int Dijkstra(int start, int end) {
	//모든 노드를 최대비용으로 초기화
	for (int i = 0; i < N; i++)
		dist[i] = INF;

	dist[start] = 0; //출발 노드는 비용 0으로

	for (int i = 0; i < N; i++) {
		int minDist = INF; //현재 가장 짧은 거리를 저장할 변수
		int now = -1; //현재 선택된 노드를 저장할 변수

		//방문하지 않은 노드 중 최단거리가 가장 작은 노드 선택
		for (int j = 0; j < N; j++) {
			if (!visited[j] && dist[j] < minDist) {
				minDist = dist[j]; //최단거리 업뎃
				now = j; //선택 노드 업데이트
			}
		}

		if (now == -1)break; //방문할 노드가 없으면 종료

		visited[now] = true; //방문했으니 방문처리

		for (int j = 0; j < Node[now].size(); j++) {
			int nextNode = Node[now][j].first;
			int cost = Node[now][j].second;

			if (!visited[nextNode] && dist[nextNode] > dist[now] + cost) {
				dist[nextNode] = dist[now] + cost; //최단 거리 업뎃
			}
		}
	}

	// 최종적으로 도착지(end)까지의 거리를 반환
	if (dist[end] == INF) {
		return -1; // 도달할 수 없는 경우 -1 반환
	}
	else {
		return dist[end]; // 최단 거리 반환
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

	cout << "최단 거리: " << count << endl;
}