#include <iostream>
#include <vector>
using namespace std;


void QuickSort(vector<int>& arr, int start, int end) {
	// start가 end보다 크면 안되므로 방지코드
	if (start >= end) return;

	//1. 피벗값을 중앙 값으로 선택
	int mid = start + (end - start) / 2;
	int pivot = arr[mid]; //피벗값 설정

	//2. 포인터 초기화
	int left = start;
	int right = end;

	//3. 분할
	while (left <= right) {

		//파티클 나누기 위해 left와 right 위치를 조정
		//left에는 피벗보다 작은값, right에는 피벗보다 큰값이 와야함.
		while (arr[left] < pivot) //피벗보다 작으면 left를 증가
			left++;
		while (arr[right] > pivot) //피벗보다 크면 right를 감소
			right--; 

		//값 교환 후 포인터 이동
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	// 4. 재귀 호출로 정렬
	QuickSort(arr, start, right); // 피벗 기준 왼쪽 정렬
	QuickSort(arr, left, end);    // 피벗 기준 오른쪽 정렬
}


int main() {
	vector<int> arr = { 8, 3, 5, 9, 2, 7, 1 }; // 정렬할 배열

	QuickSort(arr, 0, arr.size() - 1);

	cout << "Sorted array: ";
	for (int num : arr) {
		cout << num << " ";
	}
	return 0;
}