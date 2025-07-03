#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* 문제는 버블 정렬로 정렬이 총 몇 번 돌았는지 카운트하는 것.
* 배열의 크기는 500,000보다 작거나 같은데 버블정렬의 최대 시간복잡도는 N^2
* O(500,000^2)는 2초가 넘기 때문에 기존 버블 정렬로는 풀 수 없음.
* 
* 버블 정렬이 돌아간 횟수는 기존 값들이 움직인 횟수로 판별 가능.
* 정렬 한 번당 값이 오른쪽으로 이동 한 거리는 최대 N-1 까지 갈 수 있지만 왼쪽으로 이동가능 한 거리는 최대 1임.
* 즉 기존 인덱스 들 중에서 이동거리가 가장 큰 값이 버블 정렬로 정렬이 돌아간 횟수가 되는 셈.
* 
* 정렬 전 인덱스 - 정렬 후 인덱스가 정렬 + 1
* 정렬 되어 있지만 그걸 판별 하기위해 한번 더 돌아봐야 하므로 +1 을 하는 것
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	//배열 입력 및 초기화
	vector<pair<int, int>> A(N);
	for (int i = 0; i < N;i++) {
		cin >> A[i].first;
		A[i].second = i;
	}

	 //정렬 O(NlongN)
	sort(A.begin(), A.end());

	//인덱스의 이동 순서로 판별
	int Max = 0;
	for (int i = 0; i < N; i++) {
		if (Max < A[i].second - i) {
			Max = A[i].second - i;
		}
	}

	cout << Max+1;
}