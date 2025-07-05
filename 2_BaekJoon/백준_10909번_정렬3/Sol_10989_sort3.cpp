#include <iostream>
#include <vector>
using namespace std;

/*
N은 1<= N <= 10,000,000 값이고,
입력값은 K는 10,000보다 작은 자연수.

시간제한이 5초지만 NlogN으로도 N을 5억에 맞추기 어렵다.
즉 더 낮은 시간 복잡도의 알고리즘 풀이가 필요.

계수정렬로 메모리크기는 크지만 시간복잡도는 O(N+K(데이터의 최대값))
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> val_Arr(10001, 0); //10000까지 입력가능하기때문에 크기를 이렇게 할당
	for (int i = 0; i < N; i++) {
		int K =0;
		cin >> K;
		val_Arr[K]++; //입력한 값에 해당하는 인덱스에 값을 1씩 증가
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < val_Arr[i]; j++) {
			cout << i << "\n";
		}
	}
	

}