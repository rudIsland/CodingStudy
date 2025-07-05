#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
���Ϸ��� �Լ�
N�� 10^12 ���� �̹Ƿ� long������ ����
2���� �����Ͽ� N�� �����ٱ��� �ݺ����� ������.
���� N�� ������ �������� ������� ���Ϸ��� �Լ��� P[i] = P[i] - P[i]/k �� ���� ������.
�׸��� N�� ����ؼ� p�� �����ش�. ��? 45�� ��� 1, 3^2, 5, 15, 45�϶� 3�� 2�� ���ϱ� ���������.
�̸� ����ؼ� �ݺ��ϸ� ���� ����.

�ٵ� N�� 1���� ũ�� ���� �Ҽ��� �ִٴ� ���̹Ƿ� ������ ó��.
*/

int main() {
	long N;
	cin >> N;
	long result = N;

	//���Ϸ� �� �Լ�
	for (long p = 2; p <= sqrt(N); p++) {
		if (N % p == 0) {
			result = result - (result / p); // P[i] = P[i] - P[i]/k���
			while (N % p == 0) N /= p; //��� N���� ������ ���μ��� ã�´�.
		}
	}

	if (N > 1)
		result = result - result / N;

	cout << result;
}