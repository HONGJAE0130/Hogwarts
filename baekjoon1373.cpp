#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	string s = "";
	// string���� �Է�
	getline(cin, s);
	// �ڸ����� 3���� ������ �������� �����
	while (s.size() % 3 != 0) {
		s = '0' + s;
	}
	string ans = "";
	for (int i = 0; i < s.size(); i += 3) {
		int tmp = 0;
		// 3�ڸ��� 8������ ��ȯ�ϱ�
		for (int j = i; j < i + 3; j++) {
			tmp += (s[j] - '0')*pow(2, 2 - (j % 3));
		}
		ans += to_string(tmp);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%c", ans[i]);
	}
}