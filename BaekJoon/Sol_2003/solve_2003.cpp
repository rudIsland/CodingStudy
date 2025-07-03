#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; int M;
	cin >> N >> M;

	//벡터 A
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//갯수 구하기
	int left=0, right=0, count=0;
	int sum = A[0];

	while (right < N) {
		if (sum == M) {
			count++;
			if (++right < N) { // right가 경계를 초과하지 않도록 확인
				sum += A[right];
			}
		}
		else if (sum < M) { //right가 늘어날땐 어차피 left부터right까지의 사이값을 모두 더하므로 right증가값까지 더하기
			if (++right < N) {
				sum += A[right];
			}
		}
		else { //sum이 M보다 크면
			sum -= A[left++]; //left값을 빼고 left를 증가시킴.
		}
	}

	cout << count;
}