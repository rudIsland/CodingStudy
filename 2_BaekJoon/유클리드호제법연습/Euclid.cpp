#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	
	int Max = max(A, B);
	int Min = min(A, B);

	int mod = 1;
	while (Min) { //Min 0�� �Ǳ� ������ ��� �ݺ�
		mod = Max % Min; //1. ū���� ���� ���� ������.
		Max = Min; //2. 1���� �������� ū���� �����Ѵ�.
		Min = mod;
	}

	cout << Max;
	
}