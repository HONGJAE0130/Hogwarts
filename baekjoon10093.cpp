#include <iostream>

using namespace std;

int main() {
	long long A, B;
	cin >> A >> B;

	if (A == B) cout << 0;
	else if (A < B) {
		cout << B - A - 1 << "\n";
		for (long long i = A + 1; i < B; i++) cout << i << " ";
	}

	else if (B < A) {
		cout << A - B - 1 << "\n";
		for (long long i = B + 1; i < A; i++) cout << i << " ";
	}

	return 0;
}