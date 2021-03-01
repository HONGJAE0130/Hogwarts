#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack <char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (st.empty() || st.top() != s[i]) st.push(s[i]);    //st�� ����ְų� ������ ���κ��� ���� ��Ʈ����char�� �ٸ��� ���ÿ� char�� push
		else if (s[i] == st.top()) st.pop();                   //char , ������ top�� ���ٸ� ����pop

	}
	if (!st.empty()) return 0;                               //������ ������� �ʴٸ� 0
	else return 1;                                          //����ٸ� return 1;

	return answer;
}