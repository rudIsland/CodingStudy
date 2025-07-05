/*
이진 검색 binary search
(이분 검색 Interpolation search)


데이터들이 '정렬된 상태'를 가정하고 검색한다.

시간복잡도는 O(log(N))
<<--왜냐하면 절반씩 덜어내기 때문.
공간복잡도는 O(N)
<--why? 별도의 메모리 공간을 더 확보하지는 않기 때문
*/

#include <iostream>
using namespace std;

//비교 횟수 기록용
int gCount = 0;

//이분 탐색 검색
void BinarySearch(int tArray[], int Begin, int End, int data) {
    if (Begin > End) {
        cout << gCount << "번의 비교만에 찾지 못함!" << endl;
        cout << "검색 실패" << endl;
        return;
    }

    int tMiddle = (Begin + End) / 2;
    gCount++;

    if (data == tArray[tMiddle]) {
        cout << gCount << "번의 비교만에 찾음!" << endl;
        cout << "검색 성공" << endl;
    }
    else if (data < tArray[tMiddle]) {
        BinarySearch(tArray, Begin, tMiddle - 1, data);
    }
    else {
        BinarySearch(tArray, tMiddle + 1, End, data);
    }

}

int main() {
	int tArray[7] = { 1,2,8,9,11,19,29 };

	gCount = 0;
	BinarySearch(tArray, 0, 6, 29);

	gCount = 0;
	BinarySearch(tArray, 0, 6, 9);

	gCount = 0;
	BinarySearch(tArray, 0, 6, 777);

	return 0;
}