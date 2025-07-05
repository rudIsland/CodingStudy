#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph; // 최대 정점 개수는 1000
vector<bool> visited;      // 방문 여부 확인
queue<int> que; //bfs 큐

void DFS(int node) {
    visited[node] = true; //방문한 곳에 true로 설정
    cout << node+1 << " ";

    //해당 노드에 연결된 모든 정점 방문
    //i는 int인데 백준에선 컴파일 에러 걸려서 size_t로
    for (size_t i = 0; i < graph[node].size(); i++) {
        int connectedNode = graph[node][i]; // 연결된 노드 가져오기
        if (!visited[connectedNode]) //방문하지 않았으면 방문하도록 재귀
            DFS(connectedNode);
    }
}

//BFS
//큐에서 나온 노드값에 방문하여 연결되어 있는 노드값들을 삽입
       /*
       * 1: 2 3
       * 2: 1 5
       * 3: 1 4
       * 4: 3 5
       * 5: 2 4
       *
       * 1부터 탐색예시
       * 1.
       * 우선 1을 큐에 넣고 방문을 했으므로 visited[0]을 true하고 1의 인접노드를 탐색한다.
       * while문을 통해 큐에 1이 있으므로 1을 search에 넣고 출력한 후 pop시킨다.
       * for문에서 1에 있는 노드의 방문여부를 검사하고 2 3 노드를 큐에 넣는다.
       * 그럼 큐에는 { 3 | 2 } 로 2가 다음으로 나올차례로 있다.
       * visited[near] = true를 통해 2와 3은 방문처리한다.
       * visited[T, T, T, F, F]
       *
       * 2.
       * 아직 큐가 비어있지 않으므로 while문 실행
       * 큐에서 값을 빼고 출력한다. 2를 출력
       * 2의 노드를 하나씩 가져온다. 1과 5가 있다.
       * 1과 5의 방문 여부를 검사한다. 이때 1은 이미 방문했었으므로 넘어간다.
       * 5를 검사하고 방문하지 않았으므로 큐에 5를 넣는다. 이때 큐는 back{ 5 | 3 }front 이다.
       * 5를 검사했으니 visited를 true시킨다.
       * visited[T,T,T,F,T]
       *
       * 3.
       * 큐가 비어있지 않으므로 계속 탐색. 3을 빼고 출력하고 다시 3의 인접노드의 방문여부를 확인한다.
       * 이미 1은 방문했었으니 넘기고 4를 큐에 넣는다. back{ 4 | 5 } front
       * visited[T,T,T,T,T]가 되고 계속 수행
       *
       * 4. 큐에 front값 5를 빼고 출력(큐에 4만남음) 탐색 5에 인접노드 2와4는 이미 visted 의 인덱스가 모두 true이므로 바로 패스
       * 
       * 5. 남은 queue 4를 빼고 출력 인접노드 3과5의 방문여부 검사. 이미 방문했으므로 모두 패스 후
       * 
       * 6. 큐가 모두 비었으니 종료.
       * 
       * 이해했다면 1 2 5 4 3이 나올것이다.
       *
       */
void BFS(int node) {
    que.push(node); //노드 삽입
    visited[node] = true;

    while (!que.empty()){ //큐가 빌때까지 탐색
        int search = que.front();
        que.pop();
        cout << search + 1 << " ";
       
        for (size_t i = 0; i < graph[search].size(); i++) {
            int near = graph[search][i]; //큐에서 빼온 노드의 인접노드값을 하나씩 가져온다.
            if (!visited[near]) { //해당 노드를 방문하지 않았으면 그 노드에 있는 인접노드들 중 방문하지 않은 노드를 큐에 삽입한다.
                que.push(near);
                visited[near] = true; //해당 노드를 방문 처리한다.
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; //정점 개수
    int M; //간선 개수
    int v; //시작할 번호

    cin >> N >> M >> v;

    graph.resize(N);
    visited = vector<bool>(N, false);

    //간선 입력
    for (int i = 0; i < M; i++) {
        int node, near;
        cin >> node >> near;
        if (node > N) return 0;

        //배열 인덱스를 위해 -1씩
        node--;
        near--;

        //양방향 삽입
        graph[node].push_back(near);
        graph[near].push_back(node);
    }

    // 작은 번호의 노드부터 방문하기 위해 정렬
    for (int i = 0; i < N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    
    //DFS
    //1부터 시작이면 인덱스 0부터 시작이므로 -1시킨 값 전달
    DFS(v-1); //v부터 시작
    
    cout << "\n";

    //BFS
    graph.resize(N); //그래프 초기화
    visited = vector<bool>(N, false); //방문 초기화

    BFS(v - 1);

    
}
