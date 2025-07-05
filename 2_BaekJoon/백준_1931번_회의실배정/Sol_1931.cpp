#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
���� 1931�� ȸ�ǽ� ����
�׸��� �˰���

ȸ���� ����ð��� �������� �������ָ� ���� ���� ������ ȸ�ǰ� ���� ���� �ö���Եȴ�.
ȸ���� ���۽ð��� ���� ȸ���� ����ð��� ���ų� Ŀ���Ѵ�.

*/
int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> A(N);

	//����ð��� 
	for (int i = 0; i < N; i++) {
		cin >> A[i].second; //������ ���ϰ� �ϱ����� ���۽ð��� second�� �д�.
		cin >> A[i].first; //����ð��� first�� �Ͽ� sort�� ������.
	}

	//����ð��� �������� ����
	sort(A.begin(), A.end());

	int count = 0; //ȸ������ ����
	int end = -1; //����ð�

	for (int i = 0; i < N; i++) {
		if (end <= A[i].second) //�������� ȸ���� ����ð��� ���� ȸ�ǽð��� ���۽ð����� ũ�ų� �������
		{
			end = A[i].first; //���� ȸ������ð��� end�� ����
			count++; //ī��Ʈ ����
		}
	}

	cout << count;

}