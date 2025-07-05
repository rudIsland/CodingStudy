#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int> &arr, int left, int right) {

	//피벗 설정
	int mid = (left + right) / 2; //중간값
	int key = arr[mid]; //키(피봇) 설정

	while (left <= right) {

		//left right 설정
		while (key > arr[left]) left++; //왼쪽
		while (key < arr[right]) right--; //오른쪽

		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	return left; //왼쪽 파티션을 가져옴
}



void QuickSort(vector<int>& arr, int start, int end) {
	if (start >= end) return; //종료 조건

	int pivot = Partition(arr, start, end); //파티션에서 피봇값 가져오기

	QuickSort(arr, start, pivot-1); //왼쪽 파티션 정렬
	QuickSort(arr, pivot, end); //오른쪽 파티션 정렬
}


int main() {
	vector<int> A = { 5, 3, 8, 4, 9, 1, 6, 2, 7 }; //벡터 초기화

	QuickSort(A, 0, A.size()-1);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
}