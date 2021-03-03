#include <string>
#include <algorithm>
using namespace std;

int solution(string s) {
	int len = s.length();
	int checkstr = 0;
	int min = len;
	int sum = 0;
	for (int i = 1; i <= len / 2; i++) {                                     //�� �� ������ �ڸ��� ����
		int j;
		for (j = 1; s.substr(j - 1, i).length() == i; j += i) {              //
			if (s.substr(j - 1, i).compare(s.substr(j + i - 1, i)) == 0) {     //compare�� �̿��ؼ� substr�� ��ġ���� check s�� substr��
				checkstr++;
			}
			else {
				if (checkstr == 0) {
					sum += i;
				}
				else {
					if (checkstr < 9) sum += (i + 1);
					else if (checkstr < 99) sum += (i + 2);
					else if (checkstr < 999) sum += (i + 3);
					else sum += (i + 4);
					checkstr = 0;
				}
			}
		}
		if (s.substr(j - 1, i).length() > 0) sum += s.substr(j - 1, i).length();
		if (min > sum) min = sum;
		sum = 0;
	}
	return min;
}