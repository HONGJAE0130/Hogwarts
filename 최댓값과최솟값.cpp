#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	string tmp;
	vector<int> v;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')                          //�����Ͻ� 
		{
			v.push_back(atoi(tmp.c_str()));    //atoi �Լ� => ���ڿ��� ������ ��ȯ�����ִ� �Լ�   c_str�Լ� => string�� char* ������ ��ȯ
			tmp.clear();
		}
		else                                    //tmp�� ���ϱ�
		{
			tmp += s[i];
		}
	}
	v.push_back(atoi(tmp.c_str()));
	sort(v.begin(), v.end(), greater<int>());      //�������� ����
	answer += to_string(v.back()) + " " + to_string(v.front()); //to_string���� int�� string���� sort�� ������ �հ� ���� answer�� ���� 

	return answer;
}