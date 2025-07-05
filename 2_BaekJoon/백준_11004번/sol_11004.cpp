#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int>& arr, int start, int end) {
	if (start >= end) return;

	int pivot = arr[start + (end - start) / 2]; //�ǹ����� �߾Ӱ����� ����

	//������ �ʱ�ȭ
	int left = start;
	int right = end;

	//left right �� ������ ��ġ ����
	while (left <= right) {//������ �����ʺ��� �� ���� �ȵǹǷ�

		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;

		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	QuickSort(arr, start, right); //���� ��Ƽ�� start ~ �̵��ߴ� right����
	QuickSort(arr, left, end); //������ ��Ƽ�� �̵��ߴ� left ~ end ����
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