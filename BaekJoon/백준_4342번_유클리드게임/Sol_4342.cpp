#include <iostream>
#include <algorithm>
using namespace std;

bool Game(long long A, long long B, bool turn) {

	if (A % B == 0) return turn; //�ݵ�� �̱�Ƿ� ������ ����

	//A�� B�� 2�� �̻��ϰ�� ���� �İ��� ������ �� �����Ƿ� �ʽ�
	if (A >= B * 2) return turn;

	//�� �ܿ��� �� �ѱ�� �����
	else
		return Game(B, A%B, !turn);
}

int main() {

	while (1) {
		long long A, B;
		cin >> A >> B;
		if (A == 0 && B == 0) return 0;

		//ture�� ����, false�� ����
		bool turn = 1;
		if (A < B) swap(A, B);

		if (Game(A, B, turn))
			cout << "A wins\n";
		else
			cout << "B wins\n";
	}
}
