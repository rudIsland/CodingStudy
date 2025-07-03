#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N=0; //수의 개수 N
	cin >> N;

	//A 벡터 설정
	vector<int> A(N,0);
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
	}

	//정렬
	sort(A.begin(), A.end());

	int result = 0;

	for (int i = 0; i < N; i++) {
		int find = A[i]; //찾을 값
		int left = 0, right = N - 1;
		while (left < right) {

			//i(Target)과 겹치면 안됨
			
			//left가 i랑 같으면 left를 올림
			if (left == i) {
				left++;
				continue;
			}

			//right가 i랑 같으면 right를 내림
			else if (right == i) {
				right--;
				continue;
			}

			//좋은 수 일 경우
			if (A[left] + A[right] == find) {
				result++;
				break;
			}
			
			//두 합이 
			//찾을 값보다 작으면 left를 올리고(합을 키우기 위함) 
			//크면 right를 내린다.(합을 줄이기 위함)
			if (A[left] + A[right] < find) {
				left++;
			}
			else {
				right--;
			}
		}
	}

	cout << result;


}