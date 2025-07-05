#include <iostream>
#include <vector>

using namespace std;


vector<int> findMissingPoint(const vector<vector<int>> v) {
    vector<int> ans;

    int x = 0, y = 0;

    // XOR 연산을 활용하여 네 번째 좌표 찾기
    for (const auto& point : v) {
        x ^= point[0];
        y ^= point[1];
    }

    ans.push_back(x);
    ans.push_back(y);

    return ans;
}


int main() {
    vector<vector<int>> v = { {1, 2}, {2, 1}, {1, 1} };
    vector<int> asw = findMissingPoint(v);

    cout << "네 번째 좌표: (" << asw[0] << ", " << asw[1] << ")" << endl;

    return 0;
}