#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	
	int Max = max(A, B);
	int Min = min(A, B);

	int mod = 1;
	while (Min) { //Min 0이 되기 전까지 계속 반복
		mod = Max % Min; //1. 큰수를 작은 수로 나눈다.
		Max = Min; //2. 1에서 작은값을 큰수로 지정한다.
		Min = mod;
	}

	cout << Max;
	
}