#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	int Max = max(A, B);
	int Min = min(A, B);

	while (Min) {
		int mod = Max % Min;
		Max = Min;
		Min = mod;
	}

	cout << Max << "\n";
	cout << (A * B) / Max;
}