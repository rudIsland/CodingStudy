
#include <iostream>
using namespace std;

void SequentialSeach(int tArray[], int len, int data) {
    for (int i = 0; i < len; i++) {
        if (tArray[i] == data) {
            cout << "값을 찾음!" << endl;
            cout << i + 1 << "번째에 찾음" << endl;
            return;
        }
    }
}

int main()
{
    int tArray[7] = { 8,30,1,9,11,19,2 };

    SequentialSeach(tArray, 7, 9);
    SequentialSeach(tArray, 7, 777);

    return 0;
}
