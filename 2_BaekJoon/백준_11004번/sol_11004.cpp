#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int>& arr, int start, int end) {
	if (start >= end) return;

	int pivot = arr[start + (end - start) / 2]; //피벗값을 중앙값으로 설정

	//포인터 초기화
	int left = start;
	int right = end;

	//left right 투 포인터 위치 조정
	while (left <= right) {//왼쪽이 오른쪽보다 더 가면 안되므로

		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;

		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	QuickSort(arr, start, right); //왼쪽 파티션 start ~ 이동했던 right까지
	QuickSort(arr, left, end); //오른쪽 파티션 이동했던 left ~ end 까지
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	QuickSort(arr, 0, N-1);

	cout << arr[K - 1];
}