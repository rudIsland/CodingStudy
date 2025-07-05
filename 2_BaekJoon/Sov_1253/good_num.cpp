#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N=0; //���� ���� N
	cin >> N;

	//A ���� ����
	vector<int> A(N,0);
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
	}

	//����
	sort(A.begin(), A.end());

	int result = 0;

	for (int i = 0; i < N; i++) {
		int find = A[i]; //ã�� ��
		int left = 0, right = N - 1;
		while (left < right) {

			//i(Target)�� ��ġ�� �ȵ�
			
			//left�� i�� ������ left�� �ø�
			if (left == i) {
				left++;
				continue;
			}

			//right�� i�� ������ right�� ����
			else if (right == i) {
				right--;
				continue;
			}

			//���� �� �� ���
			if (A[left] + A[right] == find) {
				result++;
				break;
			}
			
			//�� ���� 
			//ã�� ������ ������ left�� �ø���(���� Ű��� ����) 
			//ũ�� right�� ������.(���� ���̱� ����)
			if (A[left] + A[right] < find) {
				left++;
			}
			else {
				right--;
			}
		}
	}

	cout << result;


}