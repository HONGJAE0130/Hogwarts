#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int result = 0;
	cin >> n;
	string str;
	map<string, int> s;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		s[str]++;
	}
	for (auto i = s.begin(); i != s.end(); i++)		// auto �� �� ��ȯ�� �����Ӱ� �� �� �ִ� Ű����
	{
		result = max(result, i->second);			//���� ū  �� ã��
	}
	for (auto j = s.begin(); j != s.end(); j++)
	{										
		if (result == j->second) {					// ���� ū ���� �ִ� ��ġ ã��
			cout << j->first;
			return 0;
		}
	}

}