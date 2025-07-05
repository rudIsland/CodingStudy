/*
선택 정렬 알고리즘
오름차순 정렬로 가정하여(최소값 선택)
*/
#include <iostream>
using namespace std;

//앞에서부터 하나씩 검사하면서 뒤에서 가장 작은 값과 Swap하며 정렬하는 알고리즘
//최소값을 한 번 찾고, 한 번만 스왑시키는 정렬.
void SelectionSort(int tArray[], int len) {

	int MinIdx = 0;
	for (int i = 0; i < len - 1; i++) {
		MinIdx = i; //1. 가장 앞의 인덱스를 저장한다.
		for (int j = i+1; j < len; j++) {
			if (tArray[MinIdx] > tArray[j]) { //2. 가장 앞의 인덱스보다 작으면 j값으로 갱신한다.
				MinIdx = j;
			}
		}

		//3. 가장 작은 값이 없으면 실행하지 않도록하고 있으면 Swap한다.
		if (MinIdx != i) {
			int temp = tArray[i];
			tArray[i] = tArray[MinIdx];
			tArray[MinIdx] = temp;
		}

	}
}

int main()
{
	int tArray[5] = { 69,10,30,2,16 };

	for (auto t : tArray) {
		cout << t << "\t";
	} cout << endl;

	SelectionSort(tArray, 5);

	for (auto t : tArray) {
		cout << t << "\t";
	}


	return 0;
}
