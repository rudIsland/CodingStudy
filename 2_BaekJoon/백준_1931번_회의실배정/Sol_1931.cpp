#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
백준 1931번 회의실 배정
그리드 알고리즘

회의의 종료시간을 기준으로 정렬해주면 가장 빨리 끝나는 회의가 가장 위로 올라오게된다.
회의의 시작시간은 이전 회의의 종료시간과 같거나 커야한다.

*/
int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> A(N);

	//종료시간을 
	for (int i = 0; i < N; i++) {
		cin >> A[i].second; //정렬을 편하게 하기위해 시작시간을 second로 둔다.
		cin >> A[i].first; //종료시간을 first로 하여 sort가 편해짐.
	}

	//종료시간을 기준으로 정렬
	sort(A.begin(), A.end());

	int count = 0; //회의진행 갯수
	int end = -1; //종료시간

	for (int i = 0; i < N; i++) {
		if (end <= A[i].second) //진행중인 회의의 종료시간이 다음 회의시간의 시작시간보다 크거나 같을경우
		{
			end = A[i].first; //다음 회의종료시간을 end에 삽입
			count++; //카운트 증가
		}
	}

	cout << count;

}