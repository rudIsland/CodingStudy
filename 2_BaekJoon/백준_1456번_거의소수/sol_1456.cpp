#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isDecimal(int n) {
	double num = sqrt(n);
	if (num % 1 == 0)
		return true;
	else
		return false;
}

int main() {
	int a, b;
	cin >> a >> b;


	int count = 0;
	for (int i = a; i <= b; i++) {
		if (isDecimal(i))
			count++;
	}

	cout << count;
}
