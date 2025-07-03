#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int>> mirro;
int N, M;
int visited[100][100];
int moveX[4] = { -1,1,0,0 }; //상 하 좌 우 순서
int moveY[4] = { 0,0,-1,1 }; //상 하 좌 우 순서

void BFS(int x, int y) {
	queue<pair<int, int>> que;
	visited[0][0] = 1; //0,0은 방문

	que.push({ 0, 0 });
	while (!que.empty()) {
		//큐 방문
		int nX = que.front().first;
		int nY = que.front().second;
		que.pop();

		//cout << "nx: " << nX << " / ";
		//cout << "nY: " << nY << "\n";
		for (int i = 0; i < 4; i++) {
			//상 하 좌 우 순서로 판별
			int nextX = nX + moveX[i];
			int nextY = nY + moveY[i];

			//좌표가 미로 좌표계 안에 있는가?
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
				continue;
			//다음 좌표가 0인가?
			if (mirro[nextX][nextY] == 0)
				continue;
			//다음 좌표를 방문 했었는가?
			if (visited[nextX][nextY])
				continue;
			
			//다음으로 갈 좌표에 이전 좌표보다 +1로 거리갱신
			visited[nextX][nextY] = visited[nX][nY]+1;
			que.push({ nextX, nextY });
			//out << "삽입: " << nextX <<"," << nextY << "\n";
			//cout << "탐색 끝\n";
		}
	}
}

int main() {
	// N: 행의 개수, M: 열의 개수 입력받기
	cin >> N >> M;

	// 2차원 벡터 크기 초기화 (N행 M열, 초기값 0)
	mirro.resize(N, vector<int>(M, 0));
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line; // 각 줄을 문자열로 입력받음

		for (int j = 0; j < M; j++) {
			mirro[i][j] = line[j] - '0';
		}
	}

	// BFS 실행
	BFS(0, 0);

	cout << visited[N - 1][M - 1];


	return 0;
	
}