#include <iostream>
#include <vector>
using namespace std;

/*
시간복잡도는 N이 8이고 처음 1의자리가 node<2 3 5 7>로 시작하여
해당 숫자에 * 10 + node2<1 3 5 7 9>로 끝나는 숫자만 소수이므로
O(4 * (4 + 5^N)) 이므로 크지않음

처음 1의 자리는 2 3 5 7만 소수이므로 탐색을 시작
main에서 차례로 탐색시키면 알아서 오름차순으로 정렬됨

뒷자리가 1 3 7 9인 자릿수를 출력
*/

//소수판별
bool isPrime(int num) {
	//자기자신의 반토막까지 나눠보고 나눠지는 수가 있을경우 소수가아님
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void DFS(int num, int N, int targetN) {
	//자릿수가 타겟 지점에 도착하고 소수면 출력
	if (N == targetN ) {
		if (isPrime(num))
			cout << num << "\n";
		return;
	}
	//계속해서 탐색
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) continue; //뒷자리 짝수는 제외

		if (isPrime(num * 10 + i)) { //num * 10는 십의자리씩 늘리기위함
			DFS(num * 10 + i, N+1, targetN);
		}
	}
}

int main() {
	
	int N;
	cin >> N;

	//처음{ 2 3 5 7 }만 소수이므로 {1}의자리부터 탐색시작, 목표는 {N}의자리
	DFS(2, 1 , N);
	DFS(3, 1, N);
	DFS(5, 1, N);
	DFS(7, 1, N);

}