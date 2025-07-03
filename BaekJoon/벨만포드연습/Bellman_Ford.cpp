#include <vector>
#include <iostream>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dist;


const int INF = 9999999; //최대값 설정

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
	dist[start] = 0; //출발 노드 비용 0

	for (int i = 0; i < dist.size()-1; i++) {
		//dist를 하나씩 모두 계산시킴.

		//그래프를 하나씩 모두 탐색
		for (int j = 0; j < graph.size(); j++) {
			if (dist[j] == INF) continue; //해당 노드가 비용이 INF면 건너뛰기

			for (int k = 0; k < graph[j].size(); k++) {
				int now = graph[j][k].first; //연결된 노드
				int cost = graph[j][k].second; //연결된 노드로 가는 비용

				if (dist[now] > dist[j] + cost) //다음 노드 비용이 현재 간선+비용보다 작으면
					dist[now] = dist[j] + cost; //최소비용 업뎃
			}
		}

	}
	
	/* 음수 사이클 검사
	이미 최단 경로가 정해졌는데 비용이 계속 작아지는데 확인하는 것임.
	값이 작아진다면 음수사이클(돌면서 계속 비용이 줄어드는 현상)이 존재한단 것이므로 
	알고리즘 의미가 없어짐.
	*/
	for (int j = 0; j < graph.size(); j++) {
		if (dist[j] == INF) continue;

		for (int k = 0; k < graph[j].size(); k++) {
			int now = graph[j][k].first;
			int cost = graph[j][k].second;

			if (dist[now] > dist[j] + cost) {
				cout << "음수 사이클 존재.\n";
				return;
			}
		}
	}

	// 결과 출력
	if (dist[end] == INF) {
		cout << "-1\n"; // 도달 불가능
	}
	else {
		cout << "Minimum cost: " << dist[end] << "\n";
	}
}


int main() {
	int N, M; //N: 노드 M: 엣지(간선)
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