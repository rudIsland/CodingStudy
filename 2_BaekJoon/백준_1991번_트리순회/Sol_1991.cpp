#include <iostream>
#include <vector>
using namespace std;
void Pre_Order(int node);
void In_Order(int node);
void Post_Order(int node);

int N;
vector<vector<int>> Tree(26, vector<int>(2, -1)); //최대26크기의 2차원배열을 -1로 초기화

int main() {
	char root, left, right;

	cin >> N;
	Tree.resize(N);
	for (int i = 0; i < N; i++) {
		Tree[i].resize(2, -1);
	}

	for (int i = 0; i < N; i++) {
		cin >> root >> left >> right;
		int node = (int)(root - 'A');

		if (left == '.') {
			Tree[node][0] = -1;
		}
		else {
			Tree[node][0] = (int)(left - 'A');
		}
		if (right == '.') {
			Tree[node][1] = -1;
		}
		else {
			Tree[node][1] = (int)(right - 'A');
		}
	}

	Pre_Order(0); //전위순회
	cout << "\n";
	In_Order(0); //중위순회
	cout << "\n";
	Post_Order(0); //후위순회
	
}

void Pre_Order(int node) { //전위순회: 현재노드 -> 왼쪽자식 -> 오른쪽자식
	if (node == -1) return; //-1이면 리턴
	cout << (char)(node + 'A'); //현재노드 출력
	Pre_Order(Tree[node][0]);  //왼쪽자식
	Pre_Order(Tree[node][1]);  //오른쪽자식
}

void In_Order(int node) { //중위 순회: 왼쪽자식 -> 현재노드 -> 오른쪽 자식
	if (node == -1) return; //-1이면 리턴
	In_Order(Tree[node][0]);  //왼쪽자식
	cout << (char)(node + 'A'); //현재노드 출력
	In_Order(Tree[node][1]);  //오른쪽자식
}

void Post_Order(int node) { //후위 순회: 왼쪽자식 -> 오른쪽자식 -> 루트
	if (node == -1) return; //-1이면 리턴
	Post_Order(Tree[node][0]);  //왼쪽자식
	Post_Order(Tree[node][1]);  //오른쪽자식
	cout << (char)(node + 'A'); //현재노드 출력
}