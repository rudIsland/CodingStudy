#include <iostream>
#include <vector>
using namespace std;


void QuickSort(vector<int>& arr, int start, int end) {
	// start�� end���� ũ�� �ȵǹǷ� �����ڵ�
	if (start >= end) return;

	//1. �ǹ����� �߾� ������ ����
	int mid = start + (end - start) / 2;
	int pivot = arr[mid]; //�ǹ��� ����

	//2. ������ �ʱ�ȭ
	int left = start;
	int right = end;

	//3. ����
	while (left <= right) {

		//��ƼŬ ������ ���� left�� right ��ġ�� ����
		//left���� �ǹ����� ������, right���� �ǹ����� ū���� �;���.
		while (arr[left] < pivot) //�ǹ����� ������ left�� ����
			left++;
		while (arr[right] > pivot) //�ǹ����� ũ�� right�� ����
			right--; 

		//�� ��ȯ �� ������ �̵�
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	// 4. ��� ȣ��� ����
	QuickSort(arr, start, right); // �ǹ� ���� ���� ����
	QuickSort(arr, left, end);    // �ǹ� ���� ������ ����
}


int main() {
	vector<int> arr = { 8, 3, 5, 9, 2, 7, 1 }; // ������ �迭

	QuickSort(arr, 0, arr.size() - 1);

	cout << "Sorted array: ";
	for (int num : arr) {
		cout << num << " ";
	}
	return 0;
}