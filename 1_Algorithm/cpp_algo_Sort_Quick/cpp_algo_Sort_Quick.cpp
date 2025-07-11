
#include <iostream>
using namespace std;



void Quick_Sort(int array[], int left, int right) {
    if (left >= right) return;
    int L = left;
    int R = right;
    int pivot = array[(left + right) / 2];  // 피벗값 중간으로 값 저장

    //L이 R보다 커지면 종료
    while (L <= R) {
        while (array[L] < pivot) { //L이 피봇보다 작으면 하나증가
            L++;
        }
        while ( array[R] > pivot) { //R이 피봇보다 크면 하나 감소
            R--;
        }

        //서로 교환시키고 L은 증가 R은 감소시키기
        if (L <= R) {
            int temp = array[R];
            array[R] = array[L];
            array[L] = temp;
            L++;
            R--;
        }
    }

    //재귀호출로 파티션별로 처리
    Quick_Sort(array, left, R);
    Quick_Sort(array, L, right);
}


int main()
{
    int data[7] = { 38,27,43,9,3,82,10 };
    int len = 7;
    Quick_Sort(data, 0, len - 1);

    for (auto t : data) {
        cout << t << "\t";
    }

    return 0;
}
