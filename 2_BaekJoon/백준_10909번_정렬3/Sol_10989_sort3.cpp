#include <iostream>
#include <vector>
using namespace std;

/*
N�� 1<= N <= 10,000,000 ���̰�,
�Է°��� K�� 10,000���� ���� �ڿ���.

�ð������� 5������ NlogN���ε� N�� 5�￡ ���߱� ��ƴ�.
�� �� ���� �ð� ���⵵�� �˰��� Ǯ�̰� �ʿ�.

������ķ� �޸�ũ��� ũ���� �ð����⵵�� O(N+K(�������� �ִ밪))
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> val_Arr(10001, 0); //10000���� �Է°����ϱ⶧���� ũ�⸦ �̷��� �Ҵ�
	for (int i = 0; i < N; i++) {
		int K =0;
		cin >> K;
		val_Arr[K]++; //�Է��� ���� �ش��ϴ� �ε����� ���� 1�� ����
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < val_Arr[i]; j++) {
			cout << i << "\n";
		}
	}
	

}