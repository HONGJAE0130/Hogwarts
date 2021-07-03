#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#pragma warning(disable : 4996)
#define MAX_LEN 100000 + 1
using namespace std;


int main() {
	// init
	int new_bar = 0;
	int depth = 0;
	int _input_len = 0;
	int answer = 0;

	char _input[MAX_LEN];
	cin >> _input;

	_input_len = strlen(_input);
	// ���ڿ��� ������ Ž���غ���. 
	for (int n_idx = 1; n_idx < _input_len; n_idx++) {
		//    ( �� ������ depth �� + 1,  ) �� ������ depth �� -1
		if (_input[n_idx] == '(') depth++;
		else depth--;

		//    ���� (( �����̸� new_bar �� �ϳ� �߰����ش�.
		if (_input[n_idx - 1] == '(' && _input[n_idx] == '(') new_bar++;

		//    ���� ()�� ������ ���� depth ��ŭ ���信 �߰��ϰ�
		//    new_bar�� 0���� �����.  
		if (_input[n_idx - 1] == '(' && _input[n_idx] == ')') {
			answer += new_bar + depth + 1;
			new_bar = 0;
		}

	}

	cout << answer;

	return 0;
}
