#include <string>
#include <iostream>
using namespace std;
int alpha[26] = { 0, };
int main()
{
	int i;
	int max = -1;
	int idx = -1;
	string s;
	cin >> s;                        //�Է� 
	for (i = 0; i < s.length(); i++)
	{
		if (s[i] < 97)                //�빮��
			alpha[s[i] - 65]++;
		else                        //�ҹ���
			alpha[s[i] - 97]++;
	}
	for (i = 0; i < 26; i++)             //���� ���� ���ĺ� max
	{
		if (max < alpha[i])
		{
			max = alpha[i];
			idx = i;
		}
	}
	for (i = 0; i < 26; i++)       //���� ���� ���ĺ� ã��
	{
		if (idx == i)
			continue;
		if (max == alpha[i])      //��ĥ �� ? ���
		{
			cout << '?';
			return 0;
		}
	}
	cout << (char)(idx + 65);
	return 0;
}
