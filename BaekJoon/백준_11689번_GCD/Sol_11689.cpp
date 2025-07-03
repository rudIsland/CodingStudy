#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
오일러피 함수
N이 10^12 까지 이므로 long형으로 정의
2부터 시작하여 N의 제곱근까지 반복문을 돌린다.
만약 N과 나누어 떨어지면 결과값을 오일러피 함수의 P[i] = P[i] - P[i]/k 를 통해 나눈다.
그리고 N을 계속해서 p로 나눠준다. 왜? 45의 경우 1, 3^2, 5, 15, 45일때 3이 2번 들어가니까 나눠줘야함.
이를 계속해서 반복하면 값이 나옴.

근데 N이 1보다 크면 남은 소수가 있다는 것이므로 마지막 처리.
*/

int main() {
	long N;
	cin >> N;
	long result = N;

	//오일러 피 함수
	for (long p = 2; p <= sqrt(N); p++) {
		if (N % p == 0) {
			result = result - (result / p); // P[i] = P[i] - P[i]/k사용
			while (N % p == 0) N /= p; //계속 N값을 나누며 소인수를 찾는다.
		}
	}

	if (N > 1)
		result = result - result / N;

	cout << result;
}