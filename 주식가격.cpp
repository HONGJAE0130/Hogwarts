#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> st;
	for (int i = 0; i < prices.size(); i++)
	{
		//price �� answer�� ������� ����
		while (!st.empty() && prices[st.top()] > prices[i])
		{
		//������ ����ְ� ������ ������ ���� ���� ������ ũ��
			answer[st.top()] = i - st.top();
			//������ �������ٸ�  i-���� ����
			st.pop();
			//��
		}
		//���� �ε��� ���� ����
		st.push(i);
	}
	while (!st.empty()) {
		answer[st.top()] = prices.size() - st.top() - 1;
		st.pop();
	}

	return answer;
}