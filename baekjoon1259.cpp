#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string input;
	while (input != "0") {
		cin >> input;
		string buf = input; //reverse �ϱ� �� ���� ���� 
		reverse(input.begin(), input.end()); // input���ڿ��� reverse 
		if (input != "0") {
			if (input == buf) cout << "yes\n";
			else cout << "no\n";
		}
	}

	return 0;
}