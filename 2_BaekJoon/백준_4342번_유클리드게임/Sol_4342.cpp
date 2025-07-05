#include <iostream>
#include <algorithm>
using namespace std;

bool Game(long long A, long long B, bool turn) {

	if (A % B == 0) return turn; //반드시 이기므로 현재턴 리턴

	//A가 B의 2배 이상일경우 선공 후공을 선택할 수 있으므로 필승
	if (A >= B * 2) return turn;

	//그 외에는 턴 넘기고 재실행
	else
		return Game(B, A%B, !turn);
}

int main() {

	while (1) {
		long long A, B;
		cin >> A >> B;
		if (A == 0 && B == 0) return 0;

		//ture면 동혁, false면 동규
		bool turn = 1;
		if (A < B) swap(A, B);

		if (Game(A, B, turn))
			cout << "A wins\n";
		else
			cout << "B wins\n";
	}
}
