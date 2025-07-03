#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int> &arr, int left, int right) {

	//�ǹ� ����
	int mid = (left + right) / 2; //�߰���
	int key = arr[mid]; //Ű(�Ǻ�) ����

	while (left <= right) {

		//left right ����
		while (key > arr[left]) left++; //����
		while (key < arr[right]) right--; //������

		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	return left; //���� ��Ƽ���� ������
}



void QuickSort(vector<int>& arr, int start, int end) {
	if (start >= end) return; //���� ����

	int pivot = Partition(arr, start, end); //��Ƽ�ǿ��� �Ǻ��� ��������

	QuickSort(arr, start, pivot-1); //���� ��Ƽ�� ����
	QuickSort(arr, pivot, end); //������ ��Ƽ�� ����
}


int main() {
	vector<int> A = { 5, 3, 8, 4, 9, 1, 6, 2, 7 }; //���� �ʱ�ȭ

	QuickSort(A, 0, A.size()-1);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
}