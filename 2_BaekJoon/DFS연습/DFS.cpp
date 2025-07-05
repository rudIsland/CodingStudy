#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph; // �ִ� ���� ������ 1000
vector<bool> visited;      // �湮 ���� Ȯ��
queue<int> que; //bfs ť

void DFS(int node) {
    visited[node] = true; //�湮�� ���� true�� ����
    cout << node+1 << " ";

    //�ش� ��忡 ����� ��� ���� �湮
    //i�� int�ε� ���ؿ��� ������ ���� �ɷ��� size_t��
    for (size_t i = 0; i < graph[node].size(); i++) {
        int connectedNode = graph[node][i]; // ����� ��� ��������
        if (!visited[connectedNode]) //�湮���� �ʾ����� �湮�ϵ��� ���
            DFS(connectedNode);
    }
}

//BFS
//ť���� ���� ��尪�� �湮�Ͽ� ����Ǿ� �ִ� ��尪���� ����
       /*
       * 1: 2 3
       * 2: 1 5
       * 3: 1 4
       * 4: 3 5
       * 5: 2 4
       *
       * 1���� Ž������
       * 1.
       * �켱 1�� ť�� �ְ� �湮�� �����Ƿ� visited[0]�� true�ϰ� 1�� ������带 Ž���Ѵ�.
       * while���� ���� ť�� 1�� �����Ƿ� 1�� search�� �ְ� ����� �� pop��Ų��.
       * for������ 1�� �ִ� ����� �湮���θ� �˻��ϰ� 2 3 ��带 ť�� �ִ´�.
       * �׷� ť���� { 3 | 2 } �� 2�� �������� �������ʷ� �ִ�.
       * visited[near] = true�� ���� 2�� 3�� �湮ó���Ѵ�.
       * visited[T, T, T, F, F]
       *
       * 2.
       * ���� ť�� ������� �����Ƿ� while�� ����
       * ť���� ���� ���� ����Ѵ�. 2�� ���
       * 2�� ��带 �ϳ��� �����´�. 1�� 5�� �ִ�.
       * 1�� 5�� �湮 ���θ� �˻��Ѵ�. �̶� 1�� �̹� �湮�߾����Ƿ� �Ѿ��.
       * 5�� �˻��ϰ� �湮���� �ʾ����Ƿ� ť�� 5�� �ִ´�. �̶� ť�� back{ 5 | 3 }front �̴�.
       * 5�� �˻������� visited�� true��Ų��.
       * visited[T,T,T,F,T]
       *
       * 3.
       * ť�� ������� �����Ƿ� ��� Ž��. 3�� ���� ����ϰ� �ٽ� 3�� ��������� �湮���θ� Ȯ���Ѵ�.
       * �̹� 1�� �湮�߾����� �ѱ�� 4�� ť�� �ִ´�. back{ 4 | 5 } front
       * visited[T,T,T,T,T]�� �ǰ� ��� ����
       *
       * 4. ť�� front�� 5�� ���� ���(ť�� 4������) Ž�� 5�� ������� 2��4�� �̹� visted �� �ε����� ��� true�̹Ƿ� �ٷ� �н�
       * 
       * 5. ���� queue 4�� ���� ��� ������� 3��5�� �湮���� �˻�. �̹� �湮�����Ƿ� ��� �н� ��
       * 
       * 6. ť�� ��� ������� ����.
       * 
       * �����ߴٸ� 1 2 5 4 3�� ���ð��̴�.
       *
       */
void BFS(int node) {
    que.push(node); //��� ����
    visited[node] = true;

    while (!que.empty()){ //ť�� �������� Ž��
        int search = que.front();
        que.pop();
        cout << search + 1 << " ";
       
        for (size_t i = 0; i < graph[search].size(); i++) {
            int near = graph[search][i]; //ť���� ���� ����� ������尪�� �ϳ��� �����´�.
            if (!visited[near]) { //�ش� ��带 �湮���� �ʾ����� �� ��忡 �ִ� �������� �� �湮���� ���� ��带 ť�� �����Ѵ�.
                que.push(near);
                visited[near] = true; //�ش� ��带 �湮 ó���Ѵ�.
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; //���� ����
    int M; //���� ����
    int v; //������ ��ȣ

    cin >> N >> M >> v;

    graph.resize(N);
    visited = vector<bool>(N, false);

    //���� �Է�
    for (int i = 0; i < M; i++) {
        int node, near;
        cin >> node >> near;
        if (node > N) return 0;

        //�迭 �ε����� ���� -1��
        node--;
        near--;

        //����� ����
        graph[node].push_back(near);
        graph[near].push_back(node);
    }

    // ���� ��ȣ�� ������ �湮�ϱ� ���� ����
    for (int i = 0; i < N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    
    //DFS
    //1���� �����̸� �ε��� 0���� �����̹Ƿ� -1��Ų �� ����
    DFS(v-1); //v���� ����
    
    cout << "\n";

    //BFS
    graph.resize(N); //�׷��� �ʱ�ȭ
    visited = vector<bool>(N, false); //�湮 �ʱ�ȭ

    BFS(v - 1);

    
}
