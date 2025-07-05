#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; int M;
	cin >> N >> M;

	//���� A
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//���� ���ϱ�
	int left=0, right=0, count=0;
	int sum = A[0];

	while (right < N) {
		if (sum == M) {
			count++;
			if (++right < N) { // right�� ��踦 �ʰ����� �ʵ��� Ȯ��
				sum += A[right];
			}
		}
		else if (sum < M) { //right�� �þ�� ������ left����right������ ���̰��� ��� ���ϹǷ� right���������� ���ϱ�
			if (++right < N) {
				sum += A[right];
			}
		}
		else { //sum�� M���� ũ��
			sum -= A[left++]; //left���� ���� left�� ������Ŵ.
		}
	}

	cout << count;
}