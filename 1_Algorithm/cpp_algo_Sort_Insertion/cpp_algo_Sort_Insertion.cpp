
#include <iostream>
using namespace std;

void Insertion_Sort(int array[], int len) {
	int i, j;

	for (i = 1; i < len; i++) {
		int temp = array[i]; //임시 저장 변수
		
		for (j = i - 1; j >= 0 && temp < array[j]; j--) {
				array[j + 1] = array[j]; //오른쪽으로 하나씩 이동
		}
		array[j + 1] = temp;
	}
}


int main()
{

	int array[5] = { 8, 5, 6, 2, 4 };

	Insertion_Sort(array, 5);
	for (auto t : array) {
		cout << t << "\t";
	}

	return 0;
}

