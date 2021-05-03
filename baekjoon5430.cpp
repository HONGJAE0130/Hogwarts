#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	int ts;
	int n;
	int num;
	string s;
	string arr;
	bool reverse;
	bool error;
	deque<int> d;

	cin >> ts;                             //�׽�Ʈ���̽�

	while (ts--) {
		d.clear();
		num = 0;
		reverse = false;
		error = false;

		cin >> s;
		cin >> n;
		cin >> arr;

		arr = arr.substr(1, arr.size() - 2);

		for (int i = 0; i < arr.size(); ++i) {
			if (atoi(arr.substr(i, 1).c_str()) != 0 || arr.substr(i, 1).compare("0") == 0) {
				num *= 10;
				num += stoi(arr.substr(i, 1));
			}
			else {
				d.push_back(num);
				num = 0;
			}
		}

		if (num != 0) {
			d.push_back(num);
		}

		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'R') {							//R �̸�
				reverse = !reverse;						//������ false
			}
			else if (s[i] == 'D') {						//
				if (d.empty()) {
					error = true;
					break;
				}
				if (reverse == true) {					//������ true��
					d.pop_back();						//�ڿ��� ����
				}
				else {
					d.pop_front();						//������ false�� �տ��� ����
				}
			}
		}

		if (error) {
			cout << "error" << endl;
			continue;
		}

		cout << "[";
		if (!reverse) {
			while (d.size()) {							//�տ��� ���� cout�ϸ� pop_front
				cout << d.front();
				d.pop_front();
				if (d.size()) {
					cout << ",";
				}
			}
		}
		else {											//�ڿ��� ���� cout�ϸ� pop_back
			while (d.size()) {
				cout << d.back();
				d.pop_back();
				if (d.size()) {
					cout << ",";
				}
			}
		}
		cout << "]" << endl;
	}

	return 0;
}