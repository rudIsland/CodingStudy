#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int>> mirro;
int N, M;
int visited[100][100];
int moveX[4] = { -1,1,0,0 }; //�� �� �� �� ����
int moveY[4] = { 0,0,-1,1 }; //�� �� �� �� ����

void BFS(int x, int y) {
	queue<pair<int, int>> que;
	visited[0][0] = 1; //0,0�� �湮

	que.push({ 0, 0 });
	while (!que.empty()) {
		//ť �湮
		int nX = que.front().first;
		int nY = que.front().second;
		que.pop();

		//cout << "nx: " << nX << " / ";
		//cout << "nY: " << nY << "\n";
		for (int i = 0; i < 4; i++) {
			//�� �� �� �� ������ �Ǻ�
			int nextX = nX + moveX[i];
			int nextY = nY + moveY[i];

			//��ǥ�� �̷� ��ǥ�� �ȿ� �ִ°�?
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
				continue;
			//���� ��ǥ�� 0�ΰ�?
			if (mirro[nextX][nextY] == 0)
				continue;
			//���� ��ǥ�� �湮 �߾��°�?
			if (visited[nextX][nextY])
				continue;
			
			//�������� �� ��ǥ�� ���� ��ǥ���� +1�� �Ÿ�����
			visited[nextX][nextY] = visited[nX][nY]+1;
			que.push({ nextX, nextY });
			//out << "����: " << nextX <<"," << nextY << "\n";
			//cout << "Ž�� ��\n";
		}
	}
}

int main() {
	// N: ���� ����, M: ���� ���� �Է¹ޱ�
	cin >> N >> M;

	// 2���� ���� ũ�� �ʱ�ȭ (N�� M��, �ʱⰪ 0)
	mirro.resize(N, vector<int>(M, 0));
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line; // �� ���� ���ڿ��� �Է¹���

		for (int j = 0; j < M; j++) {
			mirro[i][j] = line[j] - '0';
		}
	}

	// BFS ����
	BFS(0, 0);

	cout << visited[N - 1][M - 1];


	return 0;
	
}