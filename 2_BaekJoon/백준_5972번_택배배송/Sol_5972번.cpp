#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 999999; // 무한대 값 (도달할 수 없는 거리)

vector<int> dist; // 최단 거리 배열
vector<vector<pair<int, int>>> Node; // 그래프 인접 리스트 (연결된 노드, 거리)

int N, M; // N: 노드 개수, M: 간선 개수
/*
N,M은 최소1, 최대 50,000
간선의 비용이 양수이고 NlogM으로 비용이 1억 아래이므로 다익스트라 알고리즘에 적합.


6 8
4 5 3
2 4 0
4 1 4
2 1 1
5 6 1
3 6 2
3 2 6
3 4 4
*/


int Dijkstra(int start, int end) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //최소비용 큐
	dist[start] = 0; //출발노드의 비용은 0으로
	pq.push({ 0, start }); //큐에 삽입

	while (!pq.empty()) {
		int cost = pq.top().first; //큐에서 탐색할 노드 값 추출
		int node = pq.top().second; //해당 노드의 비용 값 추출
		pq.pop(); //큐에서 제거

		if (cost > dist[node]) continue; //비용이 탐색할 노드의 값보다 크면 건너뛰기

		for (int i = 0; i < Node[node].size();i++) {
			int nextNode = Node[node][i].first;
			int nextCost = Node[node][i].second;

			if (dist[nextNode] > dist[node] + nextCost) {
				dist[nextNode] = dist[node] + nextCost;
				pq.push({dist[nextNode], nextNode});
			}

		}


	}


	return 0;
	
}

int main() {
	// 사용자 입력: N(노드 개수), M(간선 개수)
	cin >> N >> M;

	dist.resize(N+1, INF);
	Node.resize(N+1);

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		Node[A].push_back({ B, C });
		Node[B].push_back({ A, C });
	}


	int result = Dijkstra(1, N);

	cout << "최단 거리: " << result << endl;
}