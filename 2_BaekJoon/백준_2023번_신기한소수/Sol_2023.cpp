#include <iostream>
#include <vector>
using namespace std;

/*
�ð����⵵�� N�� 8�̰� ó�� 1���ڸ��� node<2 3 5 7>�� �����Ͽ�
�ش� ���ڿ� * 10 + node2<1 3 5 7 9>�� ������ ���ڸ� �Ҽ��̹Ƿ�
O(4 * (4 + 5^N)) �̹Ƿ� ũ������

ó�� 1�� �ڸ��� 2 3 5 7�� �Ҽ��̹Ƿ� Ž���� ����
main���� ���ʷ� Ž����Ű�� �˾Ƽ� ������������ ���ĵ�

���ڸ��� 1 3 7 9�� �ڸ����� ���
*/

//�Ҽ��Ǻ�
bool isPrime(int num) {
	//�ڱ��ڽ��� ���丷���� �������� �������� ���� ������� �Ҽ����ƴ�
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void DFS(int num, int N, int targetN) {
	//�ڸ����� Ÿ�� ������ �����ϰ� �Ҽ��� ���
	if (N == targetN ) {
		if (isPrime(num))
			cout << num << "\n";
		return;
	}
	//����ؼ� Ž��
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) continue; //���ڸ� ¦���� ����

		if (isPrime(num * 10 + i)) { //num * 10�� �����ڸ��� �ø�������
			DFS(num * 10 + i, N+1, targetN);
		}
	}
}

int main() {
	
	int N;
	cin >> N;

	//ó��{ 2 3 5 7 }�� �Ҽ��̹Ƿ� {1}���ڸ����� Ž������, ��ǥ�� {N}���ڸ�
	DFS(2, 1 , N);
	DFS(3, 1, N);
	DFS(5, 1, N);
	DFS(7, 1, N);

}