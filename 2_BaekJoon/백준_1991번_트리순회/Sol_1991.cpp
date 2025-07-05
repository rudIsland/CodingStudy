#include <iostream>
#include <vector>
using namespace std;
void Pre_Order(int node);
void In_Order(int node);
void Post_Order(int node);

int N;
vector<vector<int>> Tree(26, vector<int>(2, -1)); //�ִ�26ũ���� 2�����迭�� -1�� �ʱ�ȭ

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

	Pre_Order(0); //������ȸ
	cout << "\n";
	In_Order(0); //������ȸ
	cout << "\n";
	Post_Order(0); //������ȸ
	
}

void Pre_Order(int node) { //������ȸ: ������ -> �����ڽ� -> �������ڽ�
	if (node == -1) return; //-1�̸� ����
	cout << (char)(node + 'A'); //������ ���
	Pre_Order(Tree[node][0]);  //�����ڽ�
	Pre_Order(Tree[node][1]);  //�������ڽ�
}

void In_Order(int node) { //���� ��ȸ: �����ڽ� -> ������ -> ������ �ڽ�
	if (node == -1) return; //-1�̸� ����
	In_Order(Tree[node][0]);  //�����ڽ�
	cout << (char)(node + 'A'); //������ ���
	In_Order(Tree[node][1]);  //�������ڽ�
}

void Post_Order(int node) { //���� ��ȸ: �����ڽ� -> �������ڽ� -> ��Ʈ
	if (node == -1) return; //-1�̸� ����
	Post_Order(Tree[node][0]);  //�����ڽ�
	Post_Order(Tree[node][1]);  //�������ڽ�
	cout << (char)(node + 'A'); //������ ���
}